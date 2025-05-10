#include "dk.h"

int up_b_count = 0;

// allow user to spam Up-B for more height
void dk_specialHiAir(GOBJ* gobj) {
	void (*cb)(GOBJ * gobj) = (void*)0x8010FD10;
	cb(gobj);

	FighterData* fd = gobj->userdata;

	if (fd->input.trigger > 0) {
		//up_b_count++;
	}
	fd->phys.self_vel.Y += up_b_count;

	OSReport("up_b_count: %f\n", fd->input.trigger);
}