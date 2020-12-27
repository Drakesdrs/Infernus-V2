#include "Nuker.h"

void Nuker::onStartDestroyBlock(GameMode* GM, Vec3_i* blockPos, uint8_t blockFace) {
	for (int x = -radius; x < radius; x++) {
		for (int y = -radius; y < radius; y++) {
			for (int z = -radius; z < radius; z++) {
				Vec3_i newPos = Vec3_i(blockPos->x + x, blockPos->y + y, blockPos->z + z);
				GM->destroyBlock(&newPos, blockFace);
			}
		}
	}
}