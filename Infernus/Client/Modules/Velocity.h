#pragma once
#include "../../Other/Module.h"

class Velocity : public Module {
public:
	Velocity() : Module::Module("Velocity", "Player", "Reduce Knockback") {};
	void onLerp(Actor*, Vec3*);
};