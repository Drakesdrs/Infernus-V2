#include "Speed.h"

void Speed::onGmTick() {
	ClientInstance* Curr = Minecraft::ClientInstance();
	LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
	bool wKey = Utils::usingKey(0x57), sKey = Utils::usingKey(0x53), aKey = Utils::usingKey(0x41), dKey = Utils::usingKey(0x44);
	if (Curr != nullptr && Curr->MinecraftGame()->canUseKeys() && Player != nullptr) {
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
			Player->velocity = Vec3(cos((yaw) * (PI / 180.f)) * speed, Player->velocity.y, sin((yaw) * (PI / 180.f)) * speed);
		}
	}
}