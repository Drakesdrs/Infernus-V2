#pragma once
#include "../../Other/Module.h"

class Speed : public Module {
public:
	Speed() : Module::Module("Speed", "Movement", "Move Faster") {};
	void onGmTick();
private:
	float speed = .5f;
};