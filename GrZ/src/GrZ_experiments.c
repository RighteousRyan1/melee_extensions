#include "GrZ.h"

//GOBJ** fighters;
//FighterData** fdatas;

// FighterData.cb.OnTakeDamage : examples of callbacks

void onGo(GOBJ* map) {
    OSReport("onGo!\n");
    void (*cb)(GOBJ * gobj) = (void*)0x802238DC;
    cb(map);

    //CollDataStage* cd = *stc_colldata;

    /*int count = 6;
    //GOBJ** fighterArray = (GOBJ**)malloc(count * sizeof(GOBJ*));
    for (int i = 0; i < count; i++) {
        fighters[i] = Fighter_GetGObj(i);
    }*/

    /*for (GOBJ* f = (*stc_gobj_lookup)[MATCHPLINK_FIGHTER]; f; f = f->next)
    {
        FighterData* fp = f->userdata;

        // filter out inactive or dead fighters

        // why != ?
        if (fp->flags.sleep || fp->flags.dead)
            continue;

        // fp->smash.

        // Fighter_SetScale(f, 10);

        // just experimenting a tad
        SpawnItem item = {
            .it_kind = ITEM_HOMERUNBAT,
            .pos = fp->phys.pos,
        };

        Item_CreateItem(&item);

        // do stuff
    }*/
}

void onFrame(GOBJ* map) {
    void (*cb)(GOBJ * gobj) = (void*)0x80223A84;
    cb(map);

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