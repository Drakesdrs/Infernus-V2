#include "AutoWalk.h"

void AutoWalk::onTick() {

	if (Player != nullptr) {
		float yaw = Player->bodyRot.y;
		Player->velocity.x = sin((yaw + 90.f) * (3.14159 / 180.0f)) * 0.235f;
		Player->velocity.z = cos((yaw + 90.f) * (3.14159 / 180.0f)) * 0.235f;
	}
}

	
