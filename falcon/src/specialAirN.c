#include "falcon.h"
#include "mex.h"

void specialAirN(GOBJ* gobj) {
	void (*cb)(GOBJ * gobj) = (void*)0x800E2D5C;

	FighterData* fs = gobj->userdata;

	Fighter_SetScale(gobj, 10);

	//Fighter_LoseStock(fs->ply);
	//Fighter_DestroyVoiceSFX(fs);

	cb(gobj);
}