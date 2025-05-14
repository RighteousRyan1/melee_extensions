#include "GrZ.h"

// the gobj here is the stage itself...
void GrZ_onCreation(GOBJ* map) {
    // = 0x802239F0 = gobj[0] frameCallback
    // 0x802238DC = OnStageGo GrZTi
    // 0x80223A2C = onCreation (GrZTi), gobj 2
    void (*cb)(GOBJ * gobj) = (void*)0x80223A2C;
    cb(map);

    MapData* md = map->userdata;
    // FighterData fd = fighter->userdata;
    
    Stage_InitDamageHazard(map, 0, OnTouchLine); //Hazard_OnTouch);
    //Stage_AddFtChkDevice(map, 0, Hazard_OnTouch);

    OSReport("onCreation Callback initialized.\n");
}

// TODO: make dangerous collision lines
LineHazardDesc* OnTouchLine(int line_id) {
    static int dmg_groups[] = { 1 };

    //OSReport("OnTouchLine\n");
    
    static LineHazardDesc hazard_desc[] = {
        // ground
        {
            .x0 = 1,
            .dmg = 22,
            .angle = 90,
            .kb_growth = 100,
            .x10 = 0,
            .kb = 80,
            .element = HITATTR_SLASH,
            .x1c = 1,
            .sfx = HITSFX_SWORD
        },
        // bottom
        {
            .x0 = 1,
            .dmg = 22,
            .angle = 270,
            .kb_growth = 100,
            .x10 = 0,
            .kb = 80,
            .element = HITATTR_FIRE,
            .x1c = 1,
            .sfx = HITSFX_FIRE,
        },
        // left wall
        {
            .x0 = 1,
            .dmg = 22,
            .angle = 0,
            .kb_growth = 100,
            .x10 = 0,
            .kb = 80,
            .element = HITATTR_FIRE,
            .x1c = 1,
            .sfx = HITSFX_FIRE,
        },
        // right wall
        {
            .x0 = 1,
            .dmg = 22,
            .angle = 180,
            .kb_growth = 100,
            .x10 = 0,
            .kb = 80,
            .element = HITATTR_FIRE,
            .x1c = 1,
            .sfx = HITSFX_FIRE,
        },
    };

    // not invalid line
    if (line_id != -1) {
        int group_id = Stage_GetLinesGroup(line_id);

        // check all dmg line groups
        for (int i = 0; i < sizeof(dmg_groups) / sizeof(int); i++) {
            // if this is one of them
            if (group_id == dmg_groups[i]) {
                // get line direction to determine damage direction
                int line_dir = Stage_GetLinesDirection(line_id);

                switch (line_dir) {
                    case (LINEDIR_GROUND):
                        return &hazard_desc[0];
                    case (LINEDIR_CEIL):
                        return &hazard_desc[1];
                    case (LINEDIR_LEFTWALL):
                        return &hazard_desc[2];
                    case (LINEDIR_RIGHTWALL):
                        return &hazard_desc[3];
                }
            }
        }
    }

    return 0;
}