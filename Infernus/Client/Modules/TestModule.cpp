#include "TestModule.h"

void TestModule::onGmTick() {
	LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
	if (Player != nullptr) {
		Actor* facingEnt = Player->MultiPlayerLevel->facingActor;
		if (facingEnt && Minecraft::ClientInstance()->MinecraftGame()->canUseKeys()) {
			Minecraft::GameMode()->interact(facingEnt, facingEnt->getPos());
			Player->swing();
		}
	}
}