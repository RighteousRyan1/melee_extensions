#include "only_up.h"
#include "only_up_hazards.c"

__attribute__((used))
static struct MapDesc map_gobjs[] = {
	// map gobj 0
	{
		.onCreation = 0x802239F0,
		.onDeletion = 0x80223A1C,
		.onFrame = 0x80223A24,
		.onUnk = 0x80223A28,
		.is_lobj = 0,
		.is_fog = 0,
		.is_cobj = 0,
	},
	// map gobj 1
	{
		.onCreation = 0x80223ABC,
		.onDeletion = 0x80223B0C,
		.onFrame = 0x80223B14,
		.onUnk = 0x80223B34,
		.is_lobj = 0,
		.is_fog = 0,
		.is_cobj = 0,
	},
	// map gobj 2
	{
		.onCreation = grOuCa_onCreation,
		.onDeletion = 0x80223A7C,
		.onFrame = 0x80223A84,
		.onUnk = 0x80223AB8,
		.is_lobj = 1,
		.is_fog = 1,
		.is_cobj = 0,
	},
	// map gobj 3
	{
		.onCreation = 0x0       ,
		.onDeletion = 0x0       ,
		.onFrame = 0x0       ,
		.onUnk = 0x0       ,
		.is_lobj = 0,
		.is_fog = 0,
		.is_cobj = 0,
	},
};