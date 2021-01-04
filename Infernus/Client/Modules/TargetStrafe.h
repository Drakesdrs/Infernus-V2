#pragma once
#include "../../Other/Module.h"

class TargetStrafe : public Module {
public:
	TargetStrafe() : Module::Module("TargetStrafe", "Movement", "Strafe around enemies") {};
	void onGmTick();
	void onDisable() {};
private:
	Vec3 EntPos;
	float CatchDistance = 12.0f;
	float StrafeDistance = 1.0f;
	float speed = 1.5f;
	bool goback = false;
		float look;
	bool clockwise = false;
	bool changeable = false;
	bool avoidvoid = false;
	bool spacerot = false;
};