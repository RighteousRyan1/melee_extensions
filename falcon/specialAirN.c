#include "falcon.h"
#include "mex.h"

void specialAirN(GOBJ* gobj) {
	void (*cb)(GOBJ * gobj) = (void*)0x800E2D5C;

	FighterData fs = gobj->userdata;

	Fighter_LoseStock(fs.ply);

	cb(gobj);
}