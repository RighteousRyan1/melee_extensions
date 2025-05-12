#include "dk.h"

int up_b_count = 0;

// allow user to spam Up-B for more height
void dk_specialHiAir(GOBJ* gobj) {
	void (*cb)(GOBJ * gobj) = (void*)0x8010FD10;
	cb(gobj);

	FighterData* fd = gobj->userdata;

	if (fd->state.frame == 1) {
		up_b_count = 0;
	}
	
	if (fd->input.timer_b) {
		up_b_count++;
		OSReport("nonzero, -> %f\n", fd->input.timer_b);
		OSReport("up_b_count eval: %f\n", up_b_count / 100.0);
	}
	fd->phys.self_vel.Y += up_b_count / 100.0;

	OSReport("self_vel.Y: %f\n", fd->phys.self_vel.Y);
}