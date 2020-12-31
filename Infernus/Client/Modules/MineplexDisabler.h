#pragma once
#include "../../Other/Module.h"

class MineplexDisabler : public Module {
public:
	MineplexDisabler() : Module::Module("MemeplexDisablerxd", "Exploits", "XD") {};
	void onPacket(PacketType type, void* Packet, bool* cancel);
private:
	int counter = 0;
};