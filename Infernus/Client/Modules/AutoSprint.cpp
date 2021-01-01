#include "AutoSprint.h"

void AutoSprint::onGmTick() {
	if (Player != nullptr) {
		if (Player->velocity.magnitudexz() > 0.05f) {
			Player->setSprinting(true);
		}
	}
}