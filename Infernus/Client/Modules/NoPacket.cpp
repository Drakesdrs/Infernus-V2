#include "NoPacket.h"

void NoPacket::onPacket(PacketType type, void* Packet, bool* cancel) {
	*cancel = true;
}