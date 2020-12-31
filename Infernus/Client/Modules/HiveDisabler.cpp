#include "HiveDisabler.h"

void HiveDisabler::onGmTick() {
	if (Minecraft::ClientInstance()->MinecraftGame()->canUseKeys()) {
		if (send && XDwhat.size() > 0) {
			for (int i = 0; i < XDwhat.size(); i++) {
				if (XDwhat.at(0) == 1) {
					for (int i = 0; i < multiplier; i++) {
						log = false;
						Minecraft::ClientInstance()->LoopbackPacketSender()->sendToServer(&movePacket.at(0));
						log = true;
					}
					movePacket.erase(movePacket.begin());
				}
				else {
					for (int i = 0; i < multiplier; i++) {
						log = false;
						Minecraft::ClientInstance()->LoopbackPacketSender()->sendToServer(&authPacket.at(0));
						log = true;
					}
					authPacket.erase(authPacket.begin());
				}
				XDwhat.erase(XDwhat.begin());
			}
			send = false;
		}
		tick++;
		if (tick == 1) { tick = 0; send = true; }
	}
	else {
		movePacket.clear(); authPacket.clear(); XDwhat.clear(); tick = 0; packetcount = 0; log = true; send = false;
	}
}

void HiveDisabler::onPacket(PacketType type, void* Packet, bool* cancel) {
	if (type == PacketType::Movement && log) {
		MovePlayerPacket* current = (MovePlayerPacket*)Packet;
		movePacket.push_back(*current); XDwhat.push_back(1);
		*cancel = true;
		packetcount++;
	}
	if (type == PacketType::AuthInput && log) {
		PlayerAuthInputPacket* current = (PlayerAuthInputPacket*)Packet;
		authPacket.push_back(*current); XDwhat.push_back(2);
		*cancel = true;
		packetcount++;
	}
}