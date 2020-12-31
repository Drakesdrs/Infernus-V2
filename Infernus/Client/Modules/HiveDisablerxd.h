#pragma once
#include "../../Other/Module.h"

class HiveDisablerXD : public Module {
public:
	HiveDisablerXD() : Module::Module("HiveDisablerxd", "Exploits", "xd") {};
	void onGmTick();
	void onDisable() { movePacket.clear(); authPacket.clear(); XDwhat.clear(); tick = 0; packetcount = 0; log = true; send = false; };
	void onPacket(PacketType type, void* Packet, bool* cancel);
private:
	std::vector<MovePlayerPacket> movePacket;
	std::vector<PlayerAuthInputPacket> authPacket;
	std::vector<int> XDwhat;
	bool log = true, send = false;
	int tick, packetcount, multiplier = 15;
};