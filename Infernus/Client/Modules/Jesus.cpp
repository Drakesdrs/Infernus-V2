#include "Jesus.h"

void Jesus::onGmTick() {
	if (Player != nullptr && Player->isInWater() || Player->isInLava()) {
		Player->velocity.y = 0.25f;
	}
}