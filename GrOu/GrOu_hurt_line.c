#include "GrOu.h"

// TODO: make dangerous collision lines
LineHazardDesc* gr_ft_line_touch(int line_id) {
    static int dmg_groups[] = { 1 };

    static LineHazardDesc hazard_desc[] = {
        // ground
        {
            .x0 = 1,
            .dmg = 22,
            .angle = 90,
            .kb_growth = 100,
            .x10 = 0,
            .kb = 80,
            .element = 1,
            .x1c = 1,
            .sfx = 8,
        },
        // bottom
        {
            .x0 = 1,
            .dmg = 22,
            .angle = 270,
            .kb_growth = 100,
            .x10 = 0,
            .kb = 80,
            .element = 1,
            .x1c = 1,
            .sfx = 8,
        },
        // left wall
        {
            .x0 = 1,
            .dmg = 22,
            .angle = 0,
            .kb_growth = 100,
            .x10 = 0,
            .kb = 80,
            .element = 1,
            .x1c = 1,
            .sfx = 8,
        },
        // right wall
        {
            .x0 = 1,
            .dmg = 22,
            .angle = 180,
            .kb_growth = 100,
            .x10 = 0,
            .kb = 80,
            .element = 1,
            .x1c = 1,
            .sfx = 8,
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