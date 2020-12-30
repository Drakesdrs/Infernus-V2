#pragma once
#include "../../Other/Module.h"

class Killaura : public Module {
public:
	Killaura() : Module::Module("Killaura", "Combat", "Automatically attack nearby entities") {};
	void onGmTick();
private:
	Vec2 getAngles(Vec3 PlayerPosition, Vec3 EntityPosition);
	void onTick();
	Vec2 lookeing;
};