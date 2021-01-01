#pragma once
#include "../../Other/Module.h"

class CubecraftFly : public Module {
public:
	CubecraftFly() : Module::Module("Cubefly", "Movement", "lol") {};
	void onGmTick();
	//void onLerp(Actor* nigga, Vec3 niggaknocc);
	void onDisable() { speed = 5; timer = 0; if (Minecraft::ClientInstance()->LocalPlayer() != nullptr) Minecraft::ClientInstance()->LocalPlayer()->velocity = Vec3(0, 0, 0); State = "Fast "; };
private:
	int timer = 0;
	float speed = 5;
	Vec3 leapbegin;
};