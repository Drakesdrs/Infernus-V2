#pragma once
#include "../../Other/Module.h"

class FightBot : public Module {
public:
	FightBot() : Module::Module("FightBot", "Combat", "Let a bot fight for u") {};
	void onGmTick();
	void onPacket(PacketType type, void* Packet, bool* cancel);
	void onDisable() { MyMan = nullptr; Angles = Vec2(0, 0); }
private:
	Vec2 getAngles(Vec3 PlayerPosition, Vec3 EntityPosition);
	Vec2 Angles = Vec2(0, 0);
	Actor* MyMan = nullptr;
	float walkSpeed = 0.26f;
};