#include "falcon.h"
#include "specialAirN.c"

__attribute__((used))
static struct FtState move_logic[] = {
	// State: 341 - Swing42
	{
		295,        // AnimationID
		0x440842,   // StateFlags
		0x41,       // AttackID
		0x0,        // BitFlags
		0x800CD390, // AnimationCallback
		0x800CD3B0, // IASACallback
		0x800CD3D0, // PhysicsCallback
		0x800CD3F0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 342 - Swing42
	{
		296,        // AnimationID
		0x440846,   // StateFlags
		0x45,       // AttackID
		0x0,        // BitFlags
		0x800CD458, // AnimationCallback
		0x800CD478, // IASACallback
		0x800CD498, // PhysicsCallback
		0x800CD4B8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 343 - Swing42
	{
		297,        // AnimationID
		0x44084A,   // StateFlags
		0x49,       // AttackID
		0x0,        // BitFlags
		0x800CD520, // AnimationCallback
		0x800CD540, // IASACallback
		0x800CD560, // PhysicsCallback
		0x800CD580, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 344 - Swing42
	{
		298,        // AnimationID
		0x44084E,   // StateFlags
		0x4D,       // AttackID
		0x0,        // BitFlags
		0x800CD6A0, // AnimationCallback
		0x800CD7C4, // IASACallback
		0x800CD7E4, // PhysicsCallback
		0x800CD804, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 345 - Swing42
	{
		299,        // AnimationID
		0x440852,   // StateFlags
		0x51,       // AttackID
		0x0,        // BitFlags
		0x800CD88C, // AnimationCallback
		0x800CD8AC, // IASACallback
		0x800CD8CC, // PhysicsCallback
		0x800CD8EC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 346 - Swing42
	{
		300,        // AnimationID
		0x440856,   // StateFlags
		0x55,       // AttackID
		0x0,        // BitFlags
		0x800CDB14, // AnimationCallback
		0x800CDB34, // IASACallback
		0x800CDB54, // PhysicsCallback
		0x800CDB74, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 347 - SpecialN
	{
		301,        // AnimationID
		0x340211,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x800E2C80, // AnimationCallback
		0x800E2E38, // IASACallback
		0x800E2F2C, // PhysicsCallback
		0x800E3168, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 348 - SpecialAirN
	{
		302,        // AnimationID
		0x340611,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		specialAirN, // AnimationCallback
		0x800E2E3C, // IASACallback
		0x800E3018, // PhysicsCallback
		0x800E31F4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 349 - SpecialSStart
	{
		303,        // AnimationID
		0x340212,   // StateFlags
		0x13,       // AttackID
		0x0,        // BitFlags
		0x800E384C, // AnimationCallback
		0x800E3B0C, // IASACallback
		0x800E3B1C, // PhysicsCallback
		0x800E3C38, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 350 - SpecialS
	{
		304,        // AnimationID
		0x340212,   // StateFlags
		0x13,       // AttackID
		0x0,        // BitFlags
		0x800E3888, // AnimationCallback
		0x800E3B10, // IASACallback
		0x800E3B3C, // PhysicsCallback
		0x800E3D44, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 351 - SpecialAirSStart
	{
		305,        // AnimationID
		0x340612,   // StateFlags
		0x13,       // AttackID
		0x0,        // BitFlags
		0x800E3964, // AnimationCallback
		0x800E3B14, // IASACallback
		0x800E3B5C, // PhysicsCallback
		0x800E3DE4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 352 - SpecialAirS
	{
		306,        // AnimationID
		0x340612,   // StateFlags
		0x13,       // AttackID
		0x0,        // BitFlags
		0x800E39F0, // AnimationCallback
		0x800E3B18, // IASACallback
		0x800E3BD0, // PhysicsCallback
		0x800E3E40, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 353 - SpecialHi
	{
		307,        // AnimationID
		0x340013,   // StateFlags
		0x14,       // AttackID
		0x0,        // BitFlags
		0x800E4B00, // AnimationCallback
		0x800E4B60, // IASACallback
		0x800E4BF8, // PhysicsCallback
		0x800E4E1C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 354 - SpecialAirHi
	{
		308,        // AnimationID
		0x340413,   // StateFlags
		0x14,       // AttackID
		0x0,        // BitFlags
		0x800E4EE8, // AnimationCallback
		0x800E4F48, // IASACallback
		0x800E4FDC, // PhysicsCallback
		0x800E50D8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 355 - SpecialHiCatch
	{
		309,        // AnimationID
		0x340013,   // StateFlags
		0x14,       // AttackID
		0x0,        // BitFlags
		0x800E51F8, // AnimationCallback
		0x800E5234, // IASACallback
		0x800E5238, // PhysicsCallback
		0x800E523C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 356 - SpecialHiThrow
	{
		310,        // AnimationID
		0x340013,   // StateFlags
		0x14,       // AttackID
		0x0,        // BitFlags
		0x800E5310, // AnimationCallback
		0x800E5384, // IASACallback
		0x800E5388, // PhysicsCallback
		0x800E54B8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 357 - SpecialLw
	{
		311,        // AnimationID
		0x340214,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x800E415C, // AnimationCallback
		0x0,        // IASACallback
		0x800E4408, // PhysicsCallback
		0x800E46B8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 358 - SpecialLwEnd
	{
		312,        // AnimationID
		0x340214,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x800E4268, // AnimationCallback
		0x0,        // IASACallback
		0x800E449C, // PhysicsCallback
		0x800E47B0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 359 - SpecialAirLw
	{
		313,        // AnimationID
		0x340614,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x800E42E0, // AnimationCallback
		0x0,        // IASACallback
		0x800E45E4, // PhysicsCallback
		0x800E48BC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 360 - SpecialAirLwEnd
	{
		314,        // AnimationID
		0x340614,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x800E4354, // AnimationCallback
		0x0,        // IASACallback
		0x800E4618, // PhysicsCallback
		0x800E493C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 361 - SpecialAirLwEndAir
	{
		316,        // AnimationID
		0x340614,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x800E4390, // AnimationCallback
		0x0,        // IASACallback
		0x800E4678, // PhysicsCallback
		0x800E495C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 362 - SpecialLwEndAir
	{
		315,        // AnimationID
		0x340214,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x800E42A4, // AnimationCallback
		0x0,        // IASACallback
		0x800E455C, // PhysicsCallback
		0x800E4838, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 363 - SpecialHiThrow
	{
		317,        // AnimationID
		0x340614,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x800E43CC, // AnimationCallback
		0x0,        // IASACallback
		0x800E4698, // PhysicsCallback
		0x800E49DC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
};