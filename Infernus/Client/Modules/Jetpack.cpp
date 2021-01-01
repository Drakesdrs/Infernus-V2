#include "Jetpack.h"

void Jetpack::onLoop() {
	MinecraftGame* mcGame = Minecraft::ClientInstance()->MinecraftGame();
	if (Utils::usingKey(this->key)) {
		if (Player != nullptr && mcGame != nullptr && mcGame->canUseKeys()) {
			this->isEnabled = true;
			this->wasEnabled = true;
		}
		else {
			if (this->isEnabled) {
				this->isEnabled = false;
				this->wasEnabled = false;
			}
		}
	}
	else {
		if (this->isEnabled) {
			this->isEnabled = false;
			this->wasEnabled = false;
		}
	}
}

void Jetpack::onTick() {
	if (Player != nullptr) {
		Vec2 currRot = Player->bodyRot;
		Vec2 angles = Vec2((currRot.x) * -(PI / 180.f), (currRot.y + 90.0f) * (PI / 180.f));
		if (this->State == "Bypass") {
			//R3coil you know what to do..
		}
		else {
			Player->velocity = Vec3(cos(angles.y) * cos(angles.x) * speed, sin(angles.x) * speed, sin(angles.y) * cos(angles.x) * speed);
		}
	}
}