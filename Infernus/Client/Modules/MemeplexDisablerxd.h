#pragma once
#include "../../Other/Module.h"

class MemeplexDisablerxd : public Module {
public:
	MemeplexDisablerxd() : Module::Module("MemeplexDisablerxd", "Exploits", "XD") {};
	void onPacket(PacketType type, void* Packet, bool* cancel);
private:
	int counter = 0;
};