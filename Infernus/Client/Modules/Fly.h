#pragma once
#include "../../Other/Module.h"

class Fly : public Module {
public:
	Fly() : Module::Module("Fly", "Movement", "Fly") {};
	void onGmTick();
public:
	/*void setSpeed(float speed) {
		this->speed = speed;
	}*/
private:
	float speed = 1.0f;
};