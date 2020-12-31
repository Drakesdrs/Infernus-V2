#include "AutoWalk.h"

void AutoWalk::onTick() {

	if (Minecraft::ClientInstance() != 0) {
		if (Minecraft::ClientInstance()->LocalPlayer() != 0) {
			LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();

			Player->velocity.z = sin((Minecraft::ClientInstance()->LocalPlayer()->bodyRot.y + 90) * (3.14159 / 180.0f)) * 0.235f;
			Player->velocity.x = cos((Minecraft::ClientInstance()->LocalPlayer()->bodyRot.y + 90) * (3.14159 / 180.0f)) * 0.235f;

		}
	}
}

	
