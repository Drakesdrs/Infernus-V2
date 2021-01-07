#pragma once 
#include "../../Other/Module.h"

class FastPlace : public Module {
public:
	FastPlace() : Module::Module("FastPlace", "World", "Find Players' coordinates.") {};
	void onMouse(char action, bool isDown, bool* cancel);
};