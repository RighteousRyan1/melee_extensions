#ifndef ONLY_UP_GROUMR_H
#define ONLY_UP_GROUMR_H

#include "mex.h"

void grOuMr_onCreation(GOBJ*);
void grOuMr_onFrame(GOBJ*);

float getLineSlopeRads(int);
LineHazardDesc* OnTouchLine(int);

// manage every wall's attrs simply with these
#define ALL_KB_GROWTH 0
#define ALL_KB 100
#define ALL_ELEM HITATTR_ELEC
#define ALL_SFX HITSFX_ELEC
#define ALL_DMG 10
#define NOMATCH_DIVISOR 2

#define KB_GROWTH_ONLYUP 50

#define RAD_TO_DEG (180. / M_PI)

/*extern GOBJ* goombas[];
extern Vec3 goomba_pos[];
extern const int goomba_count;*/

// each damage group that should be considered a hazard
extern const int dmg_groups_slopecalc[];
extern const int dmg_groups_slopecalc_count;

// each damage group that should be considered a hazard
extern const int dmg_groups_cardinal[];
extern const int dmg_groups_cardinal_count;
// cardinal damage directions
static LineHazardDesc hazard_desc_cardinal[];

extern const int dmg_groups_nomatch[];
extern const int dmg_groups_nomatch_count;
// directions that don't match wall type so recovery isn't as easy
static LineHazardDesc hazard_desc_nomatch[];

// so players can grab the ledge unapologetically
extern const int dmg_groups_cardinal_onlytops[];
extern const int dmg_groups_cardinal_onlytops_count;
// cardinal damage directions
static LineHazardDesc hazard_desc_up;

// so players can grab the ledge unapologetically, but with pizzazz
extern const int dmg_groups_nomatch_onlytops[];
extern const int dmg_groups_nomatch_onlytops_count;

// to match slope
static LineHazardDesc hazard_sloped;
// cardinal damage directions
static LineHazardDesc hazard_desc_nomatch_up;

// nothing. so the fighter is not damaged, hit, or anything
static LineHazardDesc hazard_desc_harmless;

#endif // ONLY_UP_H