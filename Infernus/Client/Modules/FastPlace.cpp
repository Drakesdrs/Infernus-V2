#include"FastPlace.h"

void FastPlace::onMouse(char action, bool isDown, bool* cancel) {
	if (action == 2 && isDown)
		MouseDown = true;
	else 
		MouseDown = false;
}

void FastPlace::onGmTick() {
	if (MouseDown) {
		if (Player != nullptr && Minecraft::GameMode() && Player->MultiPlayerLevel != nullptr) {
			GameMode* GM = Minecraft::GameMode();
			MultiPlayerLevel* Level = Player->MultiPlayerLevel;
			Vec3_i blockPos = Level->facingBlockPos;
			auto blockFace = Level->blockFace;
			GM->buildBlock(&blockPos, blockFace);
		}
	}
}