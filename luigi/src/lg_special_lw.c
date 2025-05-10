#include "luigi.h"

void lg_specialLw_iasaCallback(GOBJ* gobj) {
	// Fighter_LoseStock, Fighter_Respawn... kills?

	if (Fighter_IASACheck_JumpF(gobj) != 0) {
		ActionStateChange(0, 1, 0, gobj, ASID_KNEEBEND, 0x0, 0);
	}
	void (*cb)(GOBJ * gobj) = (void*)0x80144950;

	cb(gobj);
}

void lg_specialAirLw_iasaCallback(GOBJ* gobj) {
	if (Fighter_IASACheck_JumpAerial(gobj) != 0) {
		Fighter_EnterJumpAerial(gobj);
	}
	void (*cb)(GOBJ * gobj) = (void*)0x80144954;

	cb(gobj);
}