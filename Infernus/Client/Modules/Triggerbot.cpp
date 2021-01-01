#include "Triggerbot.h"

void Triggerbot::onGmTick() {
	MultiPlayerLevel* Level = Player->MultiPlayerLevel;
	GameMode* GM = Minecraft::GameMode();
	if (Player != nullptr && Level != nullptr && GM != nullptr) {
		Actor* facingEnt = Level->facingActor;
		if (facingEnt) {
			bool isFriend = false;
			for (auto Friend : Minecraft::Friends) {
				if (Friend == facingEnt->getFormattedNameTag()) isFriend = true;
			}
			if (!isFriend) {
				GM->attack(facingEnt);
				Player->swing();
			}
		}
	}
}