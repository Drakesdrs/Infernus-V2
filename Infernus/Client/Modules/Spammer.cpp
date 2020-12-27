#include "Spammer.h"

void Spammer::onGmTick() {
	LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
	if (Player != nullptr) {
		TextPacket* newPacket = new TextPacket(Player, "Infernus!");
		Minecraft::ClientInstance()->LoopbackPacketSender()->sendToServer(newPacket);
		delete newPacket;
	}
}