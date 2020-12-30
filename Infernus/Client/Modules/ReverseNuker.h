#pragma once
#include "../../Other/Module.h"

class ReverseNuker : public Module {
public:
	ReverseNuker() : Module::Module("ReverseNuker", "World", "Place lots of blocks at a time.") {};
	void onStartDestroyBlock(GameMode* GM, Vec3_i* blockPos, uint8_t blockFace);
	void onMouse(char action, bool isDown, bool* cancel);

		
private:
	int radius = 3;
};