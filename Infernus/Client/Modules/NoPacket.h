#pragma once
#include "../../Other/Module.h"

class NoPacket : public Module {
public:
	NoPacket() : Module::Module("NoPacket", "Other", "Disables Client Packets being sent to the Server") {};
	void onPacket(PacketType, void*, bool*);
};