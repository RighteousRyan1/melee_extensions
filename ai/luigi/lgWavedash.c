#include "lgAi.h"

static MexCpuData cpu_data = {
    .attack_radius = 18,

    .Think = Luigi_CPUThink
};

void Luigi_CPUThink(FighterData* data) {
    data->scale.X *= 1.01f;
	if (data->state_id == ASID_JUMPF
        || data->state_id == ASID_JUMPB) {
        // reset stick data
        CPU_SET_LSTICK_X(data, 0);
        CPU_SET_LSTICK_Y(data, 0);

        // wavedash
        CPU_SET_LSTICK_X_FIGHTER(data, 80);
        CPU_SET_LSTICK_Y(data, -80);
        CPU_PRESS_R(data);
        CPU_WAIT(data, 1);
        CPU_RELEASE_R(data);

        CPU_EXECUTE(data);
	}
}