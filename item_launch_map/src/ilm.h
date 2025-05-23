#include "mex.h"

#define MIN_VEL_MAG 2.5
#define MAX_VEL_MAG 3.25

#define RAND_MAX 0x0FF

void onFrameCb(GOBJ*);
float randFloat(float, float);

extern const int validLauncherItems[];

static Vec3 launcher_left;
static Vec3 launcher_right;