#include "only_up.h"

// the gobj here is the stage itself...
void grOuCa_onCreation(GOBJ* map) {
    // = 0x802239F0 = gobj[0] frameCallback
    // 0x802238DC = OnStageGo GrZTi
    // 0x80223A2C = onCreation (GrZTi), gobj 2

    // callback to the original load of the stage
    void (*cb)(GOBJ * gobj) = (void*)0x80223A2C;
    cb(map);

    MapData* md = map->userdata;
    // FighterData fd = fighter->userdata;
    
    // for anything facing up, down, left, or right
    Stage_InitDamageHazard(map, 0, OnTouchLine);

    // magical shit
    // COBJ* camera = md->camera_gobj->userdata;
    // AOBJ* anim = camera->aobj;
    // _HSD_FObj* fobj = anim->fobj;
    
    // not entirely sure what this does but this is here for a note...?
    // Stage_AddFtChkDevice(map, 0, Hazard_OnTouch);

    OSReport("GrOuCa Callback initialized.\n");
}

// why must this be named this way?
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
    }

    return 0;
}

// the start of brain-fuckery

const int dmg_groups_cardinal[] = { 45 };
const int dmg_groups_cardinal_count = 1;
const int dmg_groups_nomatch[] = { 0 };
const int dmg_groups_nomatch_count = 0;

const int dmg_groups_cardinal_onlytops[] = { 0 };
const int dmg_groups_cardinal_onlytops_count = 0;

const int dmg_groups_nomatch_onlytops[] = { 47 };
const int dmg_groups_nomatch_onlytops_count = 1;

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
        .angle = 90,
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
        .angle = 90,
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
        .angle = 90,
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
        .angle = 180,
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
        .angle = 0,
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
    .angle = 180,
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