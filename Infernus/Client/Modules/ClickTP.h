#pragma once
#include "../../Other/Module.h"

class ClickTP : public Module {
public:
	ClickTP() : Module::Module("ClickTP", "Player", "Automatically teleport On-Click!") {};
	void onMouse(char action, bool isDown, bool* cancel);
};