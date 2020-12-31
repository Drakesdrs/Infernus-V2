#include "AutoWalk.h"

void AutoWalk::onTick() {
	LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
	


	if (Minecraft::ClientInstance() != NULL) {
		if (Minecraft::ClientInstance()->LocalPlayer() != NULL) {
			Player->velocity.x = cos((Minecraft::ClientInstance()->LocalPlayer()->bodyRot.y + 90) * (3.14159 / 180.0f)) * 0.235f;
			Player->velocity.z = sin((Minecraft::ClientInstance()->LocalPlayer()->bodyRot.y + 90) * (3.14159 / 180.0f)) * 0.235f;
		}
	}

	
	//	Vec2 angles = Vec2((Minecraft::ClientInstance()->LocalPlayer()->bodyRot.x) * -(PI / 180.0f), (Minecraft::ClientInstance()->LocalPlayer()->bodyRot.y + 90.0f) * (PI / 180.0f));
		//Minecraft::ClientInstance()->LocalPlayer()->velocity = Vec3(cos(angles.y) * cos(angles.x) * 10, sin(angles.x) * 10, sin(angles.y) * cos(angles.x) * 10);
		//	Minecraft::ClientInstance()->LocalPlayer()->velocity.x = cos((angles.y + 90) * (3.14159 / 180.0f)) * 0.235f;
	//	Minecraft::ClientInstance()->LocalPlayer()->velocity.z = sin((angles.y + 90) * (3.14159 / 180.0f)) * 0.235f;
}