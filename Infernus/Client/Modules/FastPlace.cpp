#include"FastPlace.h"

void FastPlace::onMouse(char action, bool isDown, bool* cancel) {
	GameMode* GM = Minecraft::GameMode();
	MultiPlayerLevel* Level = Player->MultiPlayerLevel;
	Vec3_i blockPos = Level->facingBlockPos;
	auto blockFace = Level->blockFace;
	while (action == 2 && isDown) 
	if(Player != nullptr)
		GM->buildBlock(&blockPos, blockFace);
		Sleep(100);
	
}