#include "MemeplexDisablerxd.h"

void MemeplexDisablerxd::onPacket(PacketType type, void* Packet, bool* cancel) {
	if (type == PacketType::Movement) {
		MovePlayerPacket* current = (MovePlayerPacket*)Packet;
		if (counter == 5) counter = 0;
		else current->position.y -= counter / 100;
		counter++;
	}
}