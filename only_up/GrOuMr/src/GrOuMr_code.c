#include "GrOuMr.h"
// #include <stddef.h>

// float stage_scale;

/*GOBJ* goombas[1];
Vec3 goomba_pos[1];
const int goomba_count = 1;

Vec3 VEC3_ZERO = { .X = 0, .Y = 0, .Z = 0 };

int frame_time;*/

/*bool vec3_equals(Vec3 a, Vec3 b) {
    return a.X == b.X && a.Y == b.Y && a.Z == b.Z;
}

void manageGoombas() {
    for (int i = 0; i < goomba_count; i++) {
        GOBJ* cur_goomba = goombas[i];

        // && !vec3_equals(id->pos, VEC3_ZERO)
        if (cur_goomba) {
            ItemData* id = cur_goomba->userdata;
            id->pos = goomba_pos[i];
            id->self_vel = VEC3_ZERO;

            OSReport("Goomba pos = { X: %f, Y: %f }\n", id->pos.X, id->pos.Y);
        }
    }
}*/

// the gobj here is the stage itself...
void grOuMr_onCreation(GOBJ* map) {
    // callback to the original load of the stage
    void (*cb)(GOBJ * gobj) = (void*)0x80223A2C;
    cb(map);

    // Stage_InitDamageHazard(map, 0, OnTouchLine);

    //stage_scale = Stage_GetScale();

    /*goombas[0] = NULL;
    goomba_pos[0].X = 275 * stage_scale;
    goomba_pos[0].Y = 800 * stage_scale;*/

    OSReport("GrOuMr Callback initialized.\n");

    // __asm("$rax 0xFFF0");
}

// replace callback in gobj2 when ready
/*void grOuMr_onFrame(GOBJ* map) {
    void (*cb)(GOBJ * gobj) = (void*)0x80223A84;
    cb(map);

    for (GOBJ* f = (*stc_gobj_lookup)[MATCHPLINK_FIGHTER]; f; f = f->next)
    {
        FighterData* fp = f->userdata;

        // filter out inactive or dead fighters
        if (fp->flags.sleep || fp->flags.dead)
            continue;

        Vec3 respawnPos;
        int respawn = Stage_GetGeneralPoint(6, &respawnPos);

        if (fp->phys.pos.Y < 0) {
            // Fighter_LoseStock(fp->ply);
            Fighter_DeathLogic(f);
            Fighter_DestroyVoiceSFX(fp);
            fp->phys.pos.X = respawnPos.X;
            fp->phys.pos.Y = respawnPos.Y;
        }
    }

    // return;

    /*frame_time++;

    manageGoombas();

    // OSReport("item_gobjs: %i\n", sizeof((*stc_gobj_lookup)[MATCHPLINK_ITEM]) / sizeof(GOBJ*));

    if (frame_time % 120 != 0) return;

    for (int i = 0; i < goomba_count; i++) {
        GOBJ* cur_goomba = goombas[i];

        // position always managed by OnFrame
        SpawnItem goomba_it = {
            .it_kind = ITEM_GOOMBA,
            .pos = goomba_pos[i]
        };

        cur_goomba = Item_CreateItem(&goomba_it);

        ItemData* id = cur_goomba->userdata;

        OSReport("Created goomba at = { X: %f, Y: %f }\n", goomba_pos[i].X, goomba_pos[i].Y);
    }

    frame_time = 0;
    OSReport("Re-instated goombas.\n");
}*/

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
        // doesn't work currently. don't know why! slope gets printed 
        for (int i = 0; i < dmg_groups_slopecalc_count; i++) {
            if (group_id == dmg_groups_slopecalc[i]) {
                // int line_dir = Stage_GetLinesDirection(line_id);

                // -90 because knockback needs to be perpendicular to the line slope
                int slope = (getLineSlopeRads(line_id) * RAD_TO_DEG) + 90;

                hazard_sloped.angle = slope;

                return &hazard_sloped;
            }
        }
    }

    return 0;
}

float getLineSlopeRads(int line_id) {
    Vec3 lPt, rPt;

    GrColl_GetGroundLineEndLeft(line_id, &lPt);
    GrColl_GetGroundLineEndRight(line_id, &rPt);

    return atan2(rPt.Y - lPt.Y, rPt.X - lPt.X);
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

const int dmg_groups_slopecalc[] = { 17, 20, 26 };
const int dmg_groups_slopecalc_count = 3;

const int dmg_groups_cardinal[] = { 17, 20 };
const int dmg_groups_cardinal_count = 0;
const int dmg_groups_nomatch[] = { -1 };
const int dmg_groups_nomatch_count = 0;

const int dmg_groups_cardinal_onlytops[] = { -1 };
const int dmg_groups_cardinal_onlytops_count = 0;

const int dmg_groups_nomatch_onlytops[] = { -1 };
const int dmg_groups_nomatch_onlytops_count = 0;

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
        .dmg = ALL_DMG / NOMATCH_DIVISOR,
        .kb_growth = ALL_KB_GROWTH / NOMATCH_DIVISOR,
        .kb = ALL_KB / NOMATCH_DIVISOR,
        .element = ALL_ELEM,
        .sfx = ALL_SFX
    },
    // bottom
    {
        .x0 = 1,
        .angle = 180,
        .x10 = 0,
        .x1c = 1,
        .dmg = ALL_DMG / NOMATCH_DIVISOR,
        .kb_growth = ALL_KB_GROWTH / NOMATCH_DIVISOR,
        .kb = ALL_KB / NOMATCH_DIVISOR,
        .element = ALL_ELEM,
        .sfx = ALL_SFX
    },
    // left wall
    {
        .x0 = 1,
        .angle = 270,
        .x10 = 0,
        .x1c = 1,
        .dmg = ALL_DMG / NOMATCH_DIVISOR,
        .kb_growth = ALL_KB_GROWTH / NOMATCH_DIVISOR,
        .kb = ALL_KB / NOMATCH_DIVISOR,
        .element = ALL_ELEM,
        .sfx = ALL_SFX
    },
    // right wall
    {
        .x0 = 1,
        .angle = 270,
        .x10 = 0,
        .x1c = 1,
        .dmg = ALL_DMG / NOMATCH_DIVISOR,
        .kb_growth = ALL_KB_GROWTH / NOMATCH_DIVISOR,
        .kb = ALL_KB / NOMATCH_DIVISOR,
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
    .angle = 135,
    .x10 = 0,
    .x1c = 1,
    .dmg = ALL_DMG / NOMATCH_DIVISOR,
    .kb_growth = KB_GROWTH_ONLYUP,
    .kb = ALL_KB / NOMATCH_DIVISOR,
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