#include "dk.h"
#include "dk_specialHiAir.c"

__attribute__((used))
static struct FtState move_logic[] = {
	// State: 341 - HeavyWait
	{
		295,        // AnimationID
		0x480000,   // StateFlags
		0x35,       // AttackID
		0x40,       // BitFlags
		0x0,        // AnimationCallback
		0x800DF9F0, // IASACallback
		0x800DFA50, // PhysicsCallback
		0x800DFA70, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 342 - HeavyWalkSlow
	{
		296,        // AnimationID
		0x484066,   // StateFlags
		0x35,       // AttackID
		0x0,        // BitFlags
		0x800DFB34, // AnimationCallback
		0x800DFB54, // IASACallback
		0x800DFBB8, // PhysicsCallback
		0x800DFBD8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 343 - HeavyWalkMiddle
	{
		297,        // AnimationID
		0x484066,   // StateFlags
		0x35,       // AttackID
		0x0,        // BitFlags
		0x800DFB34, // AnimationCallback
		0x800DFB54, // IASACallback
		0x800DFBB8, // PhysicsCallback
		0x800DFBD8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 344 - HeavyWalkFast
	{
		298,        // AnimationID
		0x484066,   // StateFlags
		0x35,       // AttackID
		0x0,        // BitFlags
		0x800DFB34, // AnimationCallback
		0x800DFB54, // IASACallback
		0x800DFBB8, // PhysicsCallback
		0x800DFBD8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 345 - HeavyTurn
	{
		299,        // AnimationID
		0x482064,   // StateFlags
		0x35,       // AttackID
		0x0,        // BitFlags
		0x800E01BC, // AnimationCallback
		0x800E0200, // IASACallback
		0x800E0254, // PhysicsCallback
		0x800E0274, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 346 - HeavyWait
	{
		300,        // AnimationID
		0x480000,   // StateFlags
		0x35,       // AttackID
		0x0,        // BitFlags
		0x800E0518, // AnimationCallback
		0x800E0568, // IASACallback
		0x800E05A4, // PhysicsCallback
		0x800E05C4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 347 - HeavyWait
	{
		301,        // AnimationID
		0x480000,   // StateFlags
		0x35,       // AttackID
		0x0,        // BitFlags
		0x0,        // AnimationCallback
		0x800E030C, // IASACallback
		0x800E0330, // PhysicsCallback
		0x800E0350, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 348 - HeavyWait
	{
		302,        // AnimationID
		0x488069,   // StateFlags
		0x35,       // AttackID
		0x0,        // BitFlags
		0x0,        // AnimationCallback
		0x800E0440, // IASACallback
		0x800E0464, // PhysicsCallback
		0x800E0484, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 349 - HeavyWait
	{
		303,        // AnimationID
		0x480000,   // StateFlags
		0x35,       // AttackID
		0x40,       // BitFlags
		0x800E0648, // AnimationCallback
		0x0,        // IASACallback
		0x800E0698, // PhysicsCallback
		0x800E06B8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 350 - HeavyWait
	{
		304,        // AnimationID
		0x4A0000,   // StateFlags
		0x35,       // AttackID
		0x0,        // BitFlags
		0x800E07E4, // AnimationCallback
		0x0,        // IASACallback
		0x800E0848, // PhysicsCallback
		0x800E0868, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 351 - ThrowFWait
	{
		305,        // AnimationID
		0xA80035,   // StateFlags
		0x35,       // AttackID
		0x40,       // BitFlags
		0x8009B5C0, // AnimationCallback
		0x8009B5C4, // IASACallback
		0x8009B634, // PhysicsCallback
		0x8009B654, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 352 - ThrowFWalkSlow
	{
		306,        // AnimationID
		0xA84035,   // StateFlags
		0x35,       // AttackID
		0x0,        // BitFlags
		0x8009B744, // AnimationCallback
		0x8009B764, // IASACallback
		0x8009B7D8, // PhysicsCallback
		0x8009B7F8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 353 - ThrowFWalkMiddle
	{
		307,        // AnimationID
		0xA84035,   // StateFlags
		0x35,       // AttackID
		0x0,        // BitFlags
		0x8009B744, // AnimationCallback
		0x8009B764, // IASACallback
		0x8009B7D8, // PhysicsCallback
		0x8009B7F8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 354 - ThrowFWalkFast
	{
		308,        // AnimationID
		0xA84035,   // StateFlags
		0x35,       // AttackID
		0x0,        // BitFlags
		0x8009B744, // AnimationCallback
		0x8009B764, // IASACallback
		0x8009B7D8, // PhysicsCallback
		0x8009B7F8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 355 - ThrowFTurn
	{
		309,        // AnimationID
		0xA82035,   // StateFlags
		0x35,       // AttackID
		0x0,        // BitFlags
		0x8009B8B4, // AnimationCallback
		0x8009B948, // IASACallback
		0x8009B988, // PhysicsCallback
		0x8009B9A8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 356 - ThrowFWait
	{
		310,        // AnimationID
		0xA80035,   // StateFlags
		0x35,       // AttackID
		0x0,        // BitFlags
		0x8009BA50, // AnimationCallback
		0x8009BAA0, // IASACallback
		0x8009BADC, // PhysicsCallback
		0x8009BAFC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 357 - ThrowFWait
	{
		311,        // AnimationID
		0xA80035,   // StateFlags
		0x35,       // AttackID
		0x0,        // BitFlags
		0x8009BCDC, // AnimationCallback
		0x8009BCE0, // IASACallback
		0x8009BD04, // PhysicsCallback
		0x8009BD24, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 358 - ThrowFWait
	{
		312,        // AnimationID
		0xA88035,   // StateFlags
		0x35,       // AttackID
		0x0,        // BitFlags
		0x8009BBF0, // AnimationCallback
		0x8009BBF4, // IASACallback
		0x8009BC18, // PhysicsCallback
		0x8009BC38, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 359 - ThrowFWait
	{
		313,        // AnimationID
		0xA80035,   // StateFlags
		0x35,       // AttackID
		0x40,       // BitFlags
		0x8009BDC4, // AnimationCallback
		0x0,        // IASACallback
		0x8009BE14, // PhysicsCallback
		0x8009BE34, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 360 - ThrowFWait
	{
		314,        // AnimationID
		0xAA0035,   // StateFlags
		0x35,       // AttackID
		0x0,        // BitFlags
		0x8009BE54, // AnimationCallback
		0x0,        // IASACallback
		0x8009BEB8, // PhysicsCallback
		0x8009BED8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 361 - ThrowFF
	{
		315,        // AnimationID
		0xA40039,   // StateFlags
		0x39,       // AttackID
		0x0,        // BitFlags
		0x8009C0EC, // AnimationCallback
		0x8009C130, // IASACallback
		0x8009C150, // PhysicsCallback
		0x8009C20C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 362 - ThrowFB
	{
		316,        // AnimationID
		0xA4003A,   // StateFlags
		0x3A,       // AttackID
		0x0,        // BitFlags
		0x8009C234, // AnimationCallback
		0x8009C254, // IASACallback
		0x8009C274, // PhysicsCallback
		0x8009C294, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 363 - ThrowFHi
	{
		317,        // AnimationID
		0xA4003B,   // StateFlags
		0x3B,       // AttackID
		0x0,        // BitFlags
		0x8009C2BC, // AnimationCallback
		0x8009C2DC, // IASACallback
		0x8009C2FC, // PhysicsCallback
		0x8009C31C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 364 - ThrowFLw
	{
		318,        // AnimationID
		0xA4003C,   // StateFlags
		0x3C,       // AttackID
		0x0,        // BitFlags
		0x8009C344, // AnimationCallback
		0x8009C364, // IASACallback
		0x8009C384, // PhysicsCallback
		0x8009C3A4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 365 - ThrowFF
	{
		315,        // AnimationID
		0xA40039,   // StateFlags
		0x39,       // AttackID
		0x0,        // BitFlags
		0x8009C3CC, // AnimationCallback
		0x8009C410, // IASACallback
		0x8009C414, // PhysicsCallback
		0x8009C434, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 366 - ThrowFB
	{
		316,        // AnimationID
		0xA4003A,   // StateFlags
		0x3A,       // AttackID
		0x0,        // BitFlags
		0x8009C3CC, // AnimationCallback
		0x8009C410, // IASACallback
		0x8009C414, // PhysicsCallback
		0x8009C434, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 367 - ThrowFHi
	{
		317,        // AnimationID
		0xA4003B,   // StateFlags
		0x3B,       // AttackID
		0x0,        // BitFlags
		0x8009C3CC, // AnimationCallback
		0x8009C410, // IASACallback
		0x8009C414, // PhysicsCallback
		0x8009C434, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 368 - ThrowFLw
	{
		318,        // AnimationID
		0xA4003C,   // StateFlags
		0x3C,       // AttackID
		0x0,        // BitFlags
		0x8009C3CC, // AnimationCallback
		0x8009C410, // IASACallback
		0x8009C414, // PhysicsCallback
		0x8009C434, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 369 - SpecialNStart
	{
		319,        // AnimationID
		0x340211,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x8010E7B4, // AnimationCallback
		0x8010F094, // IASACallback
		0x8010F328, // PhysicsCallback
		0x8010F468, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 370 - SpecialNLoop
	{
		320,        // AnimationID
		0x340211,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x8010E840, // AnimationCallback
		0x8010F098, // IASACallback
		0x8010F348, // PhysicsCallback
		0x8010F50C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 371 - SpecialNCansel
	{
		321,        // AnimationID
		0x340211,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x8010E8E0, // AnimationCallback
		0x8010F1D8, // IASACallback
		0x8010F368, // PhysicsCallback
		0x8010F5B0, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 372 - SpecialN
	{
		322,        // AnimationID
		0x340211,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x8010E930, // AnimationCallback
		0x8010F1DC, // IASACallback
		0x8010F388, // PhysicsCallback
		0x8010F654, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 373 - SpecialN
	{
		323,        // AnimationID
		0x340211,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x8010EB0C, // AnimationCallback
		0x8010F1E0, // IASACallback
		0x8010F3A8, // PhysicsCallback
		0x8010F6F8, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 374 - SpecialAirNStart
	{
		324,        // AnimationID
		0x340611,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x8010EC5C, // AnimationCallback
		0x8010F1E4, // IASACallback
		0x8010F3C8, // PhysicsCallback
		0x8010F79C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 375 - SpecialAirNLoop
	{
		325,        // AnimationID
		0x340611,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x8010ECE8, // AnimationCallback
		0x8010F1E8, // IASACallback
		0x8010F3E8, // PhysicsCallback
		0x8010F840, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 376 - SpecialAirNCancel
	{
		326,        // AnimationID
		0x340611,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x8010ED88, // AnimationCallback
		0x8010F31C, // IASACallback
		0x8010F408, // PhysicsCallback
		0x8010F8E4, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 377 - SpecialAirN
	{
		327,        // AnimationID
		0x340611,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x8010EDD8, // AnimationCallback
		0x8010F320, // IASACallback
		0x8010F428, // PhysicsCallback
		0x8010F988, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 378 - SpecialAirN
	{
		328,        // AnimationID
		0x340611,   // StateFlags
		0x12,       // AttackID
		0x0,        // BitFlags
		0x8010EF7C, // AnimationCallback
		0x8010F324, // IASACallback
		0x8010F448, // PhysicsCallback
		0x8010FA2C, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 379 - SpecialS
	{
		329,        // AnimationID
		0x340212,   // StateFlags
		0x13,       // AttackID
		0x0,        // BitFlags
		0x8010E2BC, // AnimationCallback
		0x8010E334, // IASACallback
		0x8010E33C, // PhysicsCallback
		0x8010E3BC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 380 - SpecialAirS
	{
		330,        // AnimationID
		0x340612,   // StateFlags
		0x13,       // AttackID
		0x0,        // BitFlags
		0x8010E2F8, // AnimationCallback
		0x8010E338, // IASACallback
		0x8010E35C, // PhysicsCallback
		0x8010E428, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 381 - SpecialHi
	{
		331,        // AnimationID
		0x340213,   // StateFlags
		0x14,       // AttackID
		0x0,        // BitFlags
		0x8010FCD4, // AnimationCallback
		0x8010FD9C, // IASACallback
		0x8010FDA4, // PhysicsCallback
		0x8010FE60, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 382 - SpecialAirHi
	{
		332,        // AnimationID
		0x340613,   // StateFlags
		0x14,       // AttackID
		0x0,        // BitFlags
		dk_specialHiAir, // AnimationCallback
		0x8010FDA0, // IASACallback
		0x8010FDEC, // PhysicsCallback
		0x8010FF14, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 383 - SpecialLwStart
	{
		333,        // AnimationID
		0x340214,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x8010DCD8, // AnimationCallback
		0x8010DD14, // IASACallback
		0x8010DD18, // PhysicsCallback
		0x8010DD38, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 384 - SpecialLwLoop
	{
		334,        // AnimationID
		0x3C0214,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x8010DD74, // AnimationCallback
		0x8010DDDC, // IASACallback
		0x8010DDF8, // PhysicsCallback
		0x8010DE18, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 385 - SpecialLwEnd
	{
		335,        // AnimationID
		0x340214,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x8010DF5C, // AnimationCallback
		0x8010DF98, // IASACallback
		0x8010DF9C, // PhysicsCallback
		0x8010DFBC, // CollisionCallback
		0x800761C8, // CameraCallback
	},
	// State: 386 - SpecialLwEnd
	{
		336,        // AnimationID
		0x340614,   // StateFlags
		0x15,       // AttackID
		0x0,        // BitFlags
		0x8010E030, // AnimationCallback
		0x8010E06C, // IASACallback
		0x8010E070, // PhysicsCallback
		0x8010E090, // CollisionCallback
		0x800761C8, // CameraCallback
	},
};