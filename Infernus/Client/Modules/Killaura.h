#pragma once
#include "../../Other/Module.h"

class Killaura : public Module {
public:
	Killaura() : Module::Module("Killaura", "Combat", "Automatically attack nearby entities") {};
	void onPacket(PacketType type, void* Packet, bool* cancel);
	void onGmTick();
private:
	Vec2 getAngles(Vec3 PlayerPosition, Vec3 EntityPosition);
	Vec2 lookeing;
};