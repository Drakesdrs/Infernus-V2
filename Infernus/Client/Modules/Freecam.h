#pragma once
#include "../../Other/Module.h"

class Freecam : public Module {
public:
	Freecam() : Module::Module("Freecam", "Exploits", "Make everyone think you aren't moving") {};
	void onEnable();
	void onPacket(PacketType, void*, bool*);
	void onDisable();
private:
	Vec3 savedPos = Vec3();
};