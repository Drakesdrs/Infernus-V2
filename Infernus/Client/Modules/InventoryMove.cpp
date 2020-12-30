#include "InventoryMove.h"

void InventoryMove::onTick() {
	if (Minecraft::ClientInstance != NULL) {
		if (Minecraft::ClientInstance()->LocalPlayer() != NULL) {
			ClientInstance* Curr = Minecraft::ClientInstance();
			LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
			bool wKey = Utils::usingKey(0x57), sKey = Utils::usingKey(0x53), aKey = Utils::usingKey(0x41), dKey = Utils::usingKey(0x44);
			float yaw = Player->bodyRot.y;
			if (Player->canOpenContainerScreen()) {
				
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


			}
		}
	}
}