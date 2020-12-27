#pragma once
#include "../../Other/Module.h"

class Nuker : public Module {
public:
	Nuker() : Module::Module("Nuker", "World", "Destroy a large variety of blocks in a small amount of time") {};
	void onStartDestroyBlock(GameMode* GM, Vec3_i* blockPos, uint8_t blockFace);
private:
	int radius = 3;
};