#pragma once
#include "../../Other/Module.h"

class Triggerbot : public Module {
public:
	Triggerbot() : Module::Module("Triggerbot", "Combat", "Automatically attack the entity you're facing!") {};
	void onGmTick();
};