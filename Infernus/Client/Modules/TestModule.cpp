#include "TestModule.h"

void TestModule::onGmTick() {
	if (Minecraft::ClientInstance() != nullptr && Player != nullptr) {
		Player->handleFallDistanceOnServer(4, false);
	}
}