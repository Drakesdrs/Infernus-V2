#include "FightBot.h"

void FightBot::onGmTick() {
	LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
	MultiPlayerLevel* Level = Player->MultiPlayerLevel;
	GameMode* GM = Minecraft::GameMode();
	Angles = Vec2(0, 0);
	MyMan = nullptr;
	if (Player != nullptr && GM != nullptr && Level != nullptr && Minecraft::ClientInstance()->MinecraftGame()->canUseKeys()) {
		Vec3 myPos = *Player->getPos();
		size_t entListSize = Level->getListSize();
		if (entListSize > 0 && entListSize <= 5000) {
			float distanc = 999;
			for (size_t I = 0; I < entListSize; I++) {
				Actor* currEnt = Level->get(I);
				float distance = currEnt->getPos()->distance(myPos);
				if (currEnt != nullptr && currEnt != Player) {
					bool isFriend = false;
					for (auto Friend : Minecraft::Friends) {
						if (currEnt->getFormattedNameTag() == Friend) isFriend = true;
					}
					if (!isFriend) {
						if (distanc > distance) {
							distanc = distance;
							MyMan = currEnt;
						}
					}
				}
			}
		}
		if (MyMan != nullptr) {
			float distance = MyMan->getPos()->distance(*Player->getPos());
			if (distance <= 4) {
				//attack
				Angles = getAngles(*Player->getPos(), *MyMan->getPos());
				GM->attack(MyMan);
				Player->swing();
			}
			//walk
			if (distance >= 2) {
				//pathfinsing/path checking

				//jumping

				//walking
				//if (Player->onGround) {
					Angles = getAngles(*Player->getPos(), *MyMan->getPos());
					Vec2 currRot = getAngles(*Player->getPos(), *MyMan->getPos());
					Vec2 calcAngles = Vec2((currRot.x) * -(PI / 180.f), (currRot.y + 90.0f) * (PI / 180.f));
					Player->velocity = Vec3(cos(calcAngles.y) * cos(calcAngles.x) * walkSpeed, Player->velocity.y, sin(calcAngles.y) * cos(calcAngles.x) * walkSpeed);
				//}
			}
		}
	}
	else {
		this->isEnabled = false;
	}
}

void FightBot::onPacket(PacketType type, void* Packet, bool* cancel) {
	if (type == PacketType::Movement) {
		MovePlayerPacket* current = (MovePlayerPacket*)Packet;
		if (Angles.x != 0 && Angles.y != 0) {
			current->bodyRot.x = Angles.x;
			current->bodyRot.y = Angles.y;
		}
	}
}

Vec2 FightBot::getAngles(Vec3 PlayerPosition, Vec3 EntityPosition) {
	Vec2 Angles;
	float dX = PlayerPosition.x - EntityPosition.x;
	float dY = PlayerPosition.y - EntityPosition.y;
	float dZ = PlayerPosition.z - EntityPosition.z;
	double distance = sqrt(dX * dX + dY * dY + dZ * dZ);
	Angles.x = (float)(atan2(dY, distance) * 180.0f / PI);
	Angles.y = (float)(atan2(dZ, dX) * 180.0f / PI) + 90.0f;
	return Angles;
}
