#include "GameMode.h"

void Gamemode::onEnable() {
	if (this->Player != nullptr) {
		this->savedGM = this->Player->getGameType();
	}
	else this->isEnabled = false;
}

void Gamemode::onGmTick() {
	if (this->Player != nullptr) {
		this->Player->setPlayerGameType(this->GM);
	}
	else this->isEnabled = false;
}

void Gamemode::onDisable() {
	if (this->Player != nullptr) {
		this->Player->setPlayerGameType(this->savedGM);
	}
	else this->isEnabled = false;
}