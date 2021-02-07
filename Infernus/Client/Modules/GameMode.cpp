#include "GameMode.h"

void GameMode::onEnable() {
	if (this->Player != nullptr) {
		this->savedGM = this->Player->getGameType();
	}
	else this->isEnabled = false;
}

void GameMode::onGmTick() {
	if (this->Player != nullptr) {
		this->Player->setPlayerGameType(this->GM);
	}
	else this->isEnabled = false;
}

void GameMode::onDisable() {
	if (this->Player != nullptr) {
		this->Player->setPlayerGameType(this->savedGM);
	}
	else this->isEnabled = false;
}