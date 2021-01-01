#include "Fly.h"

void Fly::onGmTick() {
	bool wKey = Utils::usingKey(0x57), sKey = Utils::usingKey(0x53), aKey = Utils::usingKey(0x41), dKey = Utils::usingKey(0x44), spaceKey = Utils::usingKey(0x20), shiftKey = Utils::usingKey(0xA0);
	if (Player != nullptr && Minecraft::ClientInstance()->MinecraftGame()->canUseKeys()) {
		if (wKey || sKey || aKey || dKey) {
			float yaw = Player->bodyRot.y;
			if (wKey) {
				if (!aKey && !dKey) {
					yaw += 90.f;
				}
				else if (aKey) {
					yaw += 45.f;
				}
				else if (dKey) {
					yaw += 135.f;
				}
			}
			else if (sKey) {
				if (!aKey && !dKey) {
					yaw -= 90.f;
				}
				else if (aKey) {
					yaw -= 45.f;
				}
				else if (dKey) {
					yaw -= 135.f;
				}
			}
			else if (!wKey && !sKey) {
				if (dKey) yaw += 180.f;
			}
			Player->velocity = Vec3(cos((yaw) * (PI / 180.f)) * speed, 0, sin((yaw) * (PI / 180.f)) * speed);
		}
		else {
			Player->velocity = Vec3(0, 0, 0);
		}
		if (spaceKey || shiftKey) {
			if (spaceKey) Player->velocity.y = speed;
			if (shiftKey) Player->velocity.y = -speed;
		}
	}
}