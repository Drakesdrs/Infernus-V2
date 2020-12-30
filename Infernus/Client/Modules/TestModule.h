#pragma once
#include "../../Other/Module.h"

class TestModule : public Module {
public:
	TestModule() : Module::Module("Test Module", "Other", "Testing", 0x46) {};
	void onGmTick();
	//void onLerp(Actor* nigga, Vec3 niggaknocc);
	void onDisable() { speed = 5; timer = 0; if (Minecraft::ClientInstance()->LocalPlayer() != nullptr) Minecraft::ClientInstance()->LocalPlayer()->velocity = Vec3(0, 0, 0); State = "Fast "; };
private:
	int timer = 0;
	float speed = 5;
	Vec3 leapbegin;
};