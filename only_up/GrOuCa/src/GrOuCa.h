#ifndef ONLY_UP_H
#define ONLY_UP_H

#include "mex.h"

void grOuCa_onCreation(GOBJ*);
LineHazardDesc* OnTouchLine(int);

// manage every wall's attrs simply with these
#define ALL_KB_GROWTH 0
#define ALL_KB 250
#define ALL_ELEM HITATTR_ELEC
#define ALL_SFX HITSFX_ELEC
#define ALL_DMG 10
#define NOMATCH_DIVISOR 2

#define KB_GROWTH_ONLYUP 50

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
// cardinal damage directions
static LineHazardDesc hazard_desc_nomatch_up;

// nothing. so the fighter is not damaged, hit, or anything
static LineHazardDesc hazard_desc_harmless;

#endif // ONLY_UP_H