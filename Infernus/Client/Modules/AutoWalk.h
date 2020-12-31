#pragma once
#include "../../Other/Module.h"
class AutoWalk : public Module
{
public:
	AutoWalk() : Module::Module("PVP Bot", "Combat", "Automatically PVP") {};
	void onTick();
	//
};

