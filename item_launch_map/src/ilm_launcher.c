#include "ilm.h"

const int validLauncherItems[] = {
    ITEM_BOBOMB,
};

static Vec3 launcher_left = {
    .X = -327.5,
    .Y = 63.5,
    .Z = 0
};
static Vec3 launcher_right = {
    .X = 327.5,
    .Y = 63.5,
    .Z = 0
};

// how many frames since the map loaded
int frame = 0;
const float frameMax = 60 * 60 * 8;

// so they dont spawn so damn often all the time
#define MAGICAL_DIVISOR 8

float randFloat(float min, float max) {
    float range = (max - min);
    return min + (range * (HSD_Randi(RAND_MAX) / (float)RAND_MAX));
}

void onFrameCb(GOBJ* map) {
	void (*cb)(GOBJ * gobj) = (void*)0x80223A84;
	cb(map);

    frame++;

    float chance = frame / frameMax / MAGICAL_DIVISOR;


    int randChance = HSD_Randf() <= chance; //HSD_Randi(RAND_CHANCE_FRAME);

    OSReport("Chance: %f\n", chance);

    // only run future code if there is an item to spawn (given the random chance)
    if (!randChance)
        return;

    // the kind of item to launch
    int kind = validLauncherItems[HSD_Randi(sizeof(validLauncherItems) / sizeof(validLauncherItems[0]))];

    // which launcher to use (left, right)
    int launcher_kind = HSD_Randi(2);

    // determine the position of the launcher
    Vec3 launcher_pos = launcher_kind == 1 ? launcher_right : launcher_left;

    // base velocity assumes spawn on the left
    Vec3 vel_base = { .X = 1, .Y = 1, .Z = 0 };
    float rand_vel_mag = randFloat(MIN_VEL_MAG, MAX_VEL_MAG);

    // multiply by the randomized magnitude
    Vec3 vel_actual = vel_base;

    vel_actual.X *= rand_vel_mag;
    vel_actual.Y *= rand_vel_mag;

    /*if (launcher_kind == 1)
        OSReport("Launching from the right!\n");
    else
        OSReport("Launching from the left!\n");

    OSReport("Item launched: %i\n", kind);
    OSReport("Magnitude: %f:\n", rand_vel_mag);*/

    // invert velocities if launching from the right
    if (launcher_kind == 1)
        vel_actual.X *= -1;

    // define our item
    SpawnItem item = {
        .it_kind = kind,
        .pos = launcher_pos,
        .pos2 = launcher_pos,
        .vel = vel_actual
    };

    // create + launch the item
    // Item_CreateItem(&item);
    GOBJ* newItem = Item_CreateItem(&item);
    //ItemData id = newItem->userdata;
}

void onDeletion(GOBJ* map) {
    void (*cb)(GOBJ * gobj) = (void*)0x80223A7C;
    cb(map);

    frame = 0;
}