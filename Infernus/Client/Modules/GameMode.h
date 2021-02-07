#pragma once
#include "../../Other/Module.h"

class Gamemode : public Module {
public:
	Gamemode() : Module::Module("GameMode", "Player", "Change your GameMode") {};
	void onEnable();
	void onGmTick();
	void onDisable();
	int GM = 1;
private:
	int savedGM = 0;
};