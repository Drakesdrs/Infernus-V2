#include "CubecraftFly.h"

void CubecraftFly::onGmTick() {
	static bool showXD = true;
	if (showXD) {
		Minecraft::ClientInstance()->clientMessage("[SEX FLY]: Dont use on the start of the game since there is few second falldamage imunity, enable only onground, dont fly for too long after you get to the slow fly part, hold foward when flying, this possibly flags im not sure");
		showXD = false;
	}
	LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
	if (Player != nullptr) {
		Player->setSprinting(true);
		if (timer > 5) {
			LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
			Vec2 currRot = Player->bodyRot;
			Vec2 angles = Vec2((currRot.x) * -(PI / 180.f), (currRot.y + 90.0f) * (PI / 180.f));
			Player->velocity = Vec3(cos(angles.y) * cos(angles.x) * speed, 0, sin(angles.y) * cos(angles.x) * speed);
			if (speed > 1.8) {
				speed = speed * 0.92f;
				State = "Zoom: " + std::to_string(speed);
			}
			else {
				speed = 0.4f;
				State = "land ASAP";
			}
		}
		else if (timer == 0) {
			State = "Damage...";
			Player->velocity = Vec3(0, 0, 0);
			leapbegin = *Player->getPos();
			Player->jumpFromGround();
			Player->velocity = Vec3(0, 0, 0);
			int Xddd = 10;
			for (int i = 0; i < 50 * Xddd; i++) {
				if (i <= 25 * Xddd)
					leapbegin.y += 0.16 / Xddd;
				else
					leapbegin.y -= 0.16 / Xddd;
				MovePlayerPacket packet = MovePlayerPacket(Player, leapbegin, Player->bodyRot, false);
				Minecraft::ClientInstance()->LoopbackPacketSender()->sendToServer(&packet);
			}
		}
		else {
			State = "Waiting";
			Player->velocity = Vec3(0, 0, 0);
		}
	}
	timer++;
}

//void CubecraftFly::onLerp(Actor* nigga, Vec3 niggaknocc) {
//	if (nigga == Minecraft::ClientInstance()->LocalPlayer()) {
//		oogaboogahoho = true;
//	}
//}