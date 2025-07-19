#include "GrOuFx.h"
#include <stddef.h>
#include <float.h>

// the gobj here is the stage itself...
void grOuFx_onCreation(GOBJ* map) {
    // callback to the original load of the stage
    void (*cb)(GOBJ * gobj) = (void*)0x80223A2C;
    cb(map);

    OSReport("GrOuFx Callback initialized.\n");
}
void grOuFx_onFrame(GOBJ* map) {
    void (*cb)(GOBJ * gobj) = (void*)0x80223A84;
    cb(map);    

    // code if needed
    // COBJ* camera = Match_GetCamera()->userdata;
    // camera->eye->pos.X = 100;
}

LineHazardDesc* OnTouchLine(int line_id) {
    // not invalid line
    if (line_id != -1) {
        int group_id = Stage_GetLinesGroup(line_id);

        // check all dmg line groups
        for (int i = 0; i < dmg_groups_cardinal_count; i++) {
            // if this is one of them
            if (group_id == dmg_groups_cardinal[i]) {
                // get line direction to determine damage direction
                int line_dir = Stage_GetLinesDirection(line_id);

                switch (line_dir) {
                    case (LINEDIR_GROUND):
                        return &hazard_desc_cardinal[0];
                    case (LINEDIR_CEIL):
                        return &hazard_desc_cardinal[1];
                    case (LINEDIR_LEFTWALL):
                        return &hazard_desc_cardinal[2];
                    case (LINEDIR_RIGHTWALL):
                        return &hazard_desc_cardinal[3];
                }
            }
        }

        // for lines that should not send directly in the tangent of their line direction
        for (int i = 0; i < dmg_groups_nomatch_count; i++) {
            if (group_id == dmg_groups_nomatch[i]) {
                int line_dir = Stage_GetLinesDirection(line_id);

                switch (line_dir) {
                    case (LINEDIR_GROUND):
                        return &hazard_desc_nomatch[0];
                    case (LINEDIR_CEIL):
                        return &hazard_desc_nomatch[1];
                    case (LINEDIR_LEFTWALL):
                        return &hazard_desc_nomatch[2];
                    case (LINEDIR_RIGHTWALL):
                        return &hazard_desc_nomatch[3];
                }
            }
        }

        // for lines that should not send directly in the tangent of their line direction
        for (int i = 0; i < dmg_groups_op_count; i++) {
            if (group_id == dmg_groups_op[i]) {
                int line_dir = Stage_GetLinesDirection(line_id);

                switch (line_dir) {
                case (LINEDIR_GROUND):
                    return &hazard_desc_op[0];
                case (LINEDIR_CEIL):
                    return &hazard_desc_op[1];
                case (LINEDIR_LEFTWALL):
                    return &hazard_desc_op[2];
                case (LINEDIR_RIGHTWALL):
                    return &hazard_desc_op[3];
                }
            }
        }

        // groups that should only damage from the top

        for (int i = 0; i < dmg_groups_cardinal_onlytops_count; i++) {
            if (group_id == dmg_groups_cardinal_onlytops[i]) {
                int line_dir = Stage_GetLinesDirection(line_id);

                if (line_dir == LINEDIR_GROUND)
                    return &hazard_desc_up;
                else
                    return &hazard_desc_harmless;
            }
        }

        for (int i = 0; i < dmg_groups_nomatch_onlytops_count; i++) {
            if (group_id == dmg_groups_nomatch_onlytops[i]) {
                int line_dir = Stage_GetLinesDirection(line_id);

                if (line_dir == LINEDIR_GROUND)
                    return &hazard_desc_nomatch_up;
                else
                    return &hazard_desc_harmless;
            }
        }
        
        // slope is calculated to determine knockback angle 
        for (int i = 0; i < dmg_groups_slopecalc_count; i++) {
            if (group_id == dmg_groups_slopecalc[i]) {
                int line_dir = Stage_GetLinesDirection(line_id);

                // -90 because knockback needs to be perpendicular to the line slope
                int slope = (getLineSlopeRads(line_id) * RAD_TO_DEG) + 90;
                
                float facing = 0.0;
                GOBJ* f_contact = getClosestFighterToLine(line_id, &facing);
                FighterData* f_contact_data = f_contact->userdata;

                //OSReport("f_contact_data retrieved\n");

                // for some reason this crashes. what?
                // Playerblock* pb = Fighter_GetPlayerblock(f_contact_data->ply);

                //OSReport("Playerblock retreived\n");

                //OSReport("Character affected: %s\n", getCharName(pb->c_kind));
                //OSReport("Chardir: %f\n", facing);

                // 1.0 = right, -1.0 = left
                // only left and right because up and down are calculated properly with no directional influence (lol)
                if (line_dir == LINEDIR_LEFTWALL || line_dir == LINEDIR_RIGHTWALL) {
                    // make sure knockback is applied properly
                    if (facing == 1.0) {
                        //OSReport("oldSlope: %i\n", slope);
                        slope = (slope + 180) % 360;
                        //OSReport("newSlope: %i\n", slope);
                    }
                }

                hazard_sloped.angle = slope;

                return &hazard_sloped;
            }
        }

        // slope is calculated to determine knockback angle, but is inverted
        for (int i = 0; i < dmg_groups_inward_count; i++) {
            if (group_id == dmg_groups_inward[i]) {
                int line_dir = Stage_GetLinesDirection(line_id);

                // -90 because knockback needs to be perpendicular to the line slope
                int slope = (getLineSlopeRads(line_id) * RAD_TO_DEG) + 90;

                float facing = 0.0;
                GOBJ* f_contact = getClosestFighterToLine(line_id, &facing);
                FighterData* f_contact_data = f_contact->userdata;

                // Playerblock* pb = Fighter_GetPlayerblock(f_contact_data->ply);

                //OSReport("Character affected: %s\n", getCharName(pb->c_kind));
                //OSReport("Chardir: %f\n", facing);

                // 1.0 = right, -1.0 = left
                // this ensures that the fighter is always knocked *into* the wall first so teching is possible for spacies
                if (facing == -1.0) {
                    //OSReport("oldSlope: %i\n", slope);
                    slope = (slope + 180) % 360;
                    //OSReport("newSlope: %i\n", slope);
                }

                hazard_sloped.angle = slope;

                return &hazard_sloped;
            }
        }
    }

    return 0;
}

const char* getCharName(int c_kind) {
    // magical shit.
    // for some reason FTKIND and CKIND are different. FUCKING WIZARDRY
    switch (c_kind) {
    case CKIND_MARIO:
        return "Mario";
    case CKIND_FOX:
        return "Fox";
    case CKIND_FALCON:
        return "Captain Falcon";
    case CKIND_DK:
        return "Donkey Kong";
    case CKIND_KIRBY:
        return "Kirby";
    case CKIND_BOWSER:
        return "Bowser";
    case CKIND_LINK:
        return "Link";
    case CKIND_SHEIK:
        return "Sheik";
    case CKIND_NESS:
        return "Ness";
    case CKIND_PEACH:
        return "Peach";
    case CKIND_POPO:
        return "Popo";
    case CKIND_PIKACHU:
        return "Pikachu";
    case CKIND_SAMUS:
        return "Samus";
    case CKIND_YOSHI:
        return "Yoshi";
    case CKIND_JIGGLYPUFF:
        return "Jigglypuff";
    case CKIND_MEWTWO:
        return "Mewtwo";
    case CKIND_LUIGI:
        return "Luigi";
    case CKIND_MARTH:
        return "Marth";
    case CKIND_ZELDA:
        return "Zelda";
    case CKIND_YOUNGLINK:
        return "Young Link";
    case CKIND_DRMARIO:
        return "Dr. Mario";
    case CKIND_FALCO:
        return "Falco";
    case CKIND_PICHU:
        return "Pichu";
    case CKIND_GANONDORF:
        return "Ganondorf";
    case CKIND_ROY:
        return "Roy";
    case CKIND_MASTERHAND:
        return "Master Hand";
        // Add more IDs if needed
    default:
        return "Unknown Character";
    }
}
float getLineSlopeRads(int line_id) {
    Vec3 lPt, rPt;

    GrColl_GetGroundLineEndLeft(line_id, &lPt);
    GrColl_GetGroundLineEndRight(line_id, &rPt);

    return atan2(rPt.Y - lPt.Y, rPt.X - lPt.X);
}
Vec3 getLineCenter(int line_id) {
    Vec3 lPt, rPt;

    GrColl_GetGroundLineEndLeft(line_id, &lPt);
    GrColl_GetGroundLineEndRight(line_id, &rPt);

    float midX = (lPt.X + rPt.X) / 2;
    float midY = (lPt.Y + rPt.Y) / 2;

    Vec3 def = { .X = midX, .Y = midY, .Z = 0 };

    //OSReport("Got line center...\n");

    return def;
}
FighterData* getClosestFighterToLine(int line_id, float* facing_dir) {
    FighterData* closest = NULL;
    float closest_dist = FLT_MAX;

    // OSReport("Pre-loop lookup\n");

    for (GOBJ* f = (*stc_gobj_lookup)[MATCHPLINK_FIGHTER]; f; f = f->next) {
        FighterData* fd = f->userdata;

        // filter out inactive or dead fighters
        if (fd->flags.sleep || fd->flags.dead)
            continue;

        //OSReport("checking in loop...\n");

        Vec3 fpos = fd->phys.pos;
        Vec3 lcenter = getLineCenter(line_id);

        //OSReport("fpos: { X: %f, Y: %f }\n", fpos.X, fpos.Y);

        float dist = Math_Vec3Distance(&fpos, &lcenter);

        //OSReport("Dist: %f\n", dist);

        if (!closest || dist < closest_dist) {
            closest = fd;
            closest_dist = dist;
            *facing_dir = fd->facing_direction;
            //OSReport("facing_dir: %f\n", facing_dir);
        }
    }
    
    return closest;
}

static LineHazardDesc hazard_sloped = {
    .x0 = 1,
    .angle = 0,
    .x10 = 0,
    .x1c = 1,
    .dmg = ALL_DMG,
    .kb_growth = ALL_KB_GROWTH,
    .kb = ALL_KB,
    .element = ALL_ELEM,
    .sfx = ALL_SFX
};

// the start of brain-fuckery

const int dmg_groups_slopecalc[] = { 4, 5, 8 };
const int dmg_groups_slopecalc_count = 3;

const int dmg_groups_inward[] = { 20, 21, 24, 25, 26, 27 };
const int dmg_groups_inward_count = 6;

const int dmg_groups_op[] = { 30, 31, 34, 35, 36 };
const int dmg_groups_op_count = 5;

const int dmg_groups_cardinal[] = { -1 };
const int dmg_groups_cardinal_count = 0;
const int dmg_groups_nomatch[] = { 10, 12, 39, 40, 42, 43 };
const int dmg_groups_nomatch_count = 6;

const int dmg_groups_cardinal_onlytops[] = { -1 };
const int dmg_groups_cardinal_onlytops_count = 0;

const int dmg_groups_nomatch_onlytops[] = { 11 };
const int dmg_groups_nomatch_onlytops_count = 1;

// x0 could be "match direction of fighter"?
// x1c could also be
// x0 = 1, x1c = 1

static LineHazardDesc hazard_desc_cardinal[] = {
    // ground
    {
        .x0 = 1,
        .angle = 90,
        .x10 = 0,
        .x1c = 1,
        .dmg = ALL_DMG,
        .kb_growth = ALL_KB_GROWTH,
        .kb = ALL_KB,
        .element = ALL_ELEM,
        .sfx = ALL_SFX
    },
    // bottom
    {
        .x0 = 1,
        .angle = 270,
        .x10 = 0,
        .x1c = 1,
        .dmg = ALL_DMG,
        .kb_growth = ALL_KB_GROWTH,
        .kb = ALL_KB,
        .element = ALL_ELEM,
        .sfx = ALL_SFX
    },
    // left wall
    {
        .x0 = 1,
        .angle = 180,
        .x10 = 0,
        .x1c = 1,
        .dmg = ALL_DMG,
        .kb_growth = ALL_KB_GROWTH,
        .kb = ALL_KB,
        .element = ALL_ELEM,
        .sfx = ALL_SFX
    },
    // right wall
    {
        .x0 = 1,
        .angle = 0,
        .x10 = 0,
        .x1c = 1,
        .dmg = ALL_DMG,
        .kb_growth = ALL_KB_GROWTH,
        .kb = ALL_KB,
        .element = ALL_ELEM,
        .sfx = ALL_SFX
    },
};
static LineHazardDesc hazard_desc_nomatch[] = {
    // ground
    {
        .x0 = 1,
        .angle = 0,
        .x10 = 0,
        .x1c = 1,
        .dmg = ALL_DMG,
        .kb_growth = ALL_KB_GROWTH,
        .kb = ALL_KB,
        .element = ALL_ELEM,
        .sfx = ALL_SFX
    },
    // bottom
    {
        .x0 = 1,
        .angle = 180,
        .x10 = 0,
        .x1c = 1,
        .dmg = ALL_DMG,
        .kb_growth = ALL_KB_GROWTH,
        .kb = ALL_KB,
        .element = ALL_ELEM,
        .sfx = ALL_SFX
    },
    // left wall
    {
        .x0 = 1,
        .angle = 270,
        .x10 = 0,
        .x1c = 1,
        .dmg = ALL_DMG,
        .kb_growth = ALL_KB_GROWTH,
        .kb = ALL_KB,
        .element = ALL_ELEM,
        .sfx = ALL_SFX
    },
    // right wall
    {
        .x0 = 1,
        .angle = 270,
        .x10 = 0,
        .x1c = 1,
        .dmg = ALL_DMG,
        .kb_growth = ALL_KB_GROWTH,
        .kb = ALL_KB,
        .element = ALL_ELEM,
        .sfx = ALL_SFX
    },
};
static LineHazardDesc hazard_desc_up = {
    .x0 = 1,
    .angle = 0,
    .x10 = 0,
    .x1c = 1,
    .dmg = ALL_DMG,
    .kb_growth = KB_GROWTH_ONLYUP,
    .kb = ALL_KB,
    .element = ALL_ELEM,
    .sfx = ALL_SFX
};
static LineHazardDesc hazard_desc_nomatch_up = {
    .x0 = 1,
    .angle = 0,
    .x10 = 0,
    .x1c = 1,
    .dmg = ALL_DMG,
    .kb_growth = KB_GROWTH_ONLYUP,
    .kb = ALL_KB,
    .element = ALL_ELEM,
    .sfx = ALL_SFX
};
static LineHazardDesc hazard_desc_harmless = {
    .x0 = 1,
    .angle = 0,
    .x10 = 0,
    .x1c = 1,
    .dmg = 0,
    .kb_growth = 0,
    .kb = 0,
    .element = 0,
    .sfx = 0
};
static LineHazardDesc hazard_desc_op[] = {
    // ground
    {
        .x0 = 1,
        .angle = 0,
        .x10 = 0,
        .x1c = 1,
        .dmg = ALL_DMG,
        .kb_growth = ALL_KB_GROWTH,
        .kb = ALL_KB * 2,
        .element = ALL_ELEM,
        .sfx = ALL_SFX
    },
    // bottom
    {
        .x0 = 1,
        .angle = 180,
        .x10 = 0,
        .x1c = 1,
        .dmg = ALL_DMG,
        .kb_growth = ALL_KB_GROWTH,
        .kb = ALL_KB * 2,
        .element = ALL_ELEM,
        .sfx = ALL_SFX
    },
    // left wall
    {
        .x0 = 1,
        .angle = 270,
        .x10 = 0,
        .x1c = 1,
        .dmg = ALL_DMG,
        .kb_growth = ALL_KB_GROWTH,
        .kb = ALL_KB * 2,
        .element = ALL_ELEM,
        .sfx = ALL_SFX
    },
    // right wall
    {
        .x0 = 1,
        .angle = 270,
        .x10 = 0,
        .x1c = 1,
        .dmg = ALL_DMG,
        .kb_growth = ALL_KB_GROWTH,
        .kb = ALL_KB * 2,
        .element = ALL_ELEM,
        .sfx = ALL_SFX
    },
};

Vec2** v2spl(Vec2* source, Vec2* dest, int splits) {
    Vec2** result = (Vec2**)malloc(splits * sizeof(Vec2*));
    if (!result) {
        return NULL; // Memory allocation failed
    }
    for (int i = 0; i < splits; i++) {
        result[i] = (Vec2*)malloc(sizeof(Vec2));
        if (!result[i]) {
            // Free previously allocated memory in case of failure
            for (int j = 0; j < i; j++) {
                free(result[j]);
            }
            free(result);
            return NULL;
        }
        *result[i] = lerp(*source, *dest, (float)i / (splits - 1));
    }
	return result;
}
/*
Vec2 slerp(Vec2 a, Vec2 b, float t) {
    float dot = a.X * b.X + a.Y * b.Y;
    float theta = acosf(dot);
    float sinTheta = sinf(theta);

    if (sinTheta < FLT_EPSILON) {
        return a; // If the angle is too small, return the first vector
    }
    float aCoeff = sinf((1 - t) * theta) / sinTheta;
    float bCoeff = sinf(t * theta) / sinTheta;
    Vec2 result;
    result.X = aCoeff * a.X + bCoeff * b.X;
    result.Y = aCoeff * a.Y + bCoeff * b.Y;
    return result;
}
Vec2 lerp(Vec2 a, Vec2 b, float t) {
    Vec2 result;
    result.X = a.X + (b.X - a.X) * t;
    result.Y = a.Y + (b.Y - a.Y) * t;
    return result;
}*/