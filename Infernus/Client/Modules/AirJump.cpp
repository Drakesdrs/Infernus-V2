#include "AirJump.h"

void AirJump::onGmTick() {
	if (Player != nullptr) {
		Player->onGround = true;
	}
}