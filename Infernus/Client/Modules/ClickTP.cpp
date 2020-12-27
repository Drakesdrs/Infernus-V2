#include "ClickTP.h"

void ClickTP::onMouse(char action, bool isDown, bool* cancel) {
	if (action == 2 && isDown) {
		LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
		if (Player != nullptr) {
			MultiPlayerLevel* Level = Player->MultiPlayerLevel;
			Vec3_i blockPos = Level->facingBlockPos;
			if (blockPos != Vec3_i(0, 0, 0)) {
				Player->setPos(Vec3(blockPos.x + 0.5f, blockPos.y + 2.f, blockPos.z + 0.5f));
			}
		}
	}
}