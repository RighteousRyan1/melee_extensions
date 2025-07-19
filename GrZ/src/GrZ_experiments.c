#include "GrZ.h"

//GOBJ** fighters;
//FighterData** fdatas;

// FighterData.cb.OnTakeDamage : examples of callbacks

void onGo(GOBJ* map) {
    OSReport("onGo!\n");
    void (*cb)(GOBJ * gobj) = (void*)0x802238DC;
    cb(map);

    CollLine* lines = stc_collline;


}

void onFrame(GOBJ* map) {
    void (*cb)(GOBJ * gobj) = (void*)0x80223A84;
    cb(map);
    // Match* m = Match_GetMatchData();

    // Match_SetFarClip can be cool!!!

    // OSReport("onFrame\n");

    for (GOBJ* f = (*stc_gobj_lookup)[MATCHPLINK_FIGHTER]; f; f = f->next)
    {
        FighterData* fp = f->userdata;

        // filter out inactive or dead fighters
        if (fp->flags.sleep || fp->flags.dead)
            continue;

        // fp->smash.

        // Fighter_SetScale(f, 10);

        // just experimenting a tad

        if (fp->item_held != 0x0)
            continue;

        int itkind = ITEM_BOBOMB;

        SpawnItem item = {
            .it_kind = itkind,
            .pos = { .X = 0, .Y = 50, .Z = 0 },
            .vel = {.X = 0, .Y = 5, .Z = 0 }
        };
        Item_CreateItem(&item);
        //GOBJ* newItem = Item_CreateItem(&item);

        //fp->item_held = newItem;

        // do stuff
    }
}