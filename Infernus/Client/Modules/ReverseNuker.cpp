#include "ReverseNuker.h"
int radius = 3;

void ReverseNuker::onStartDestroyBlock(GameMode* GM, Vec3_i* blockPos, uint8_t blockFace) {
	for (int x = -radius; x < radius; x++) {
		for (int y = -radius; y < radius; y++) {
			for (int z = -radius; z < radius; z++) {
				Vec3_i newPos = Vec3_i(blockPos->x + x, blockPos->y + y, blockPos->z + z);

				GM->buildBlock(&newPos, blockFace);

			}
		}
	}
}

void ReverseNuker::onMouse(char action, bool isDown, bool* cancel) {
	if (action == 2 && isDown) {
		LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
		
		if (Player != nullptr) {
		
			MultiPlayerLevel* Level = Player->MultiPlayerLevel;
			Vec3_i blockPos = Level->facingBlockPos;
		
			if (blockPos != Vec3_i(0, 0, 0)) {
			
				
				
		
			}
		}
	}
}


