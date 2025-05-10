#include "luigi.h"
#include "lg_special_hold_s.c"

void lg_special_s_end(GOBJ* gobj) {
	void (*cb)(GOBJ * gobj) = (void*)0x80143D7C;
	cb(gobj);

	appr_lstick = 0;

	OSReport("Reset appr_lstick.");
}