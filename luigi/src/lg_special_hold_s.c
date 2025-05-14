#include "luigi.h"

#define RAND_MAX 0x7FF

float appr_lstick;

float random_float(float min, float max) {
	return min + ((float)HSD_Randf() / (float)RAND_MAX) * (max - min);
}

void lg_special_hold_s(GOBJ* gobj) {
	void (*cb)(GOBJ * gobj) = (void*)0x80142E98;
	cb(gobj);
	
	static float rand_max = 5.0;

	FighterData* fd = gobj->userdata;
	JOBJ* jobj = gobj->hsd_object;

	// ItemDesc** items = fd->ftData->items;

	float rand_num = random_float(0.1, rand_max);

	//Fighter_SetScale(gobj, rand_num);
	// ft->scale.X = 0.5;
	//OSReport("ft->scale.X: %f\n", ft->scale.X);

	static float max_speed_lsick = 5.0;
	if (abs(appr_lstick) <= max_speed_lsick) {
		appr_lstick += fd->input.lstick.X * 0.25;
	}
	else {
		appr_lstick = max_speed_lsick * sign(appr_lstick);
	}
	OSReport("appr_lstick: %f\n", appr_lstick);
	fd->phys.self_vel_ground.X = appr_lstick;
	// bones[TransN].joint->scale.X = 0.5;
	//jobj->scale.X = rand_num;
}