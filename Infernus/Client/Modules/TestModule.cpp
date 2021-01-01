#include "TestModule.h"

void TestModule::onStartDestroyBlock(GameMode* GM, Vec3_i* blockPos, uint8_t blockFace) {
	for (int i = 0; i < 500; i++) {
		GM->destroyBlock(blockPos, blockFace);
		GM->buildBlock(blockPos, blockFace);
	}
}