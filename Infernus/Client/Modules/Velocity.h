#pragma once
#include "../../Other/Module.h"

class Velocity : public Module {
public:
	Velocity() : Module::Module("Velocity", "Player", "Reduce Knockback") {};
	void onLerp(Actor*, Vec3*);
	Vec3 newVel = Vec3(0, 0, 0);
};