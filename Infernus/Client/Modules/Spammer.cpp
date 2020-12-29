#include "Spammer.h"

void Spammer::onGmTick() {
	if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - savedTime) >= std::chrono::milliseconds((int)delay)) {
		LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
		if (Player != nullptr) {
			if (this->State == "Bypass") {
				int rndInt = Utils::randomFloat(0, 100);
				std::string brackets = std::string("[ " + std::to_string(rndInt) + " ]");
				TextPacket* newPacket = new TextPacket(Player, brackets + std::string(" " + this->message + " ") + brackets);
				Minecraft::ClientInstance()->LoopbackPacketSender()->sendToServer(newPacket);
				delete newPacket;
			}
			else {
				TextPacket* newPacket = new TextPacket(Player, this->message);
				Minecraft::ClientInstance()->LoopbackPacketSender()->sendToServer(newPacket);
				delete newPacket;
			}
		}
		savedTime = std::chrono::high_resolution_clock::now();
	}
}