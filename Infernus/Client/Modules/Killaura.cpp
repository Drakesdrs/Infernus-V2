#include "Killaura.h"

void Killaura::onGmTick() {
	MultiPlayerLevel* Level = Player->MultiPlayerLevel;
	GameMode* GM = Minecraft::GameMode();
	if (Player != nullptr && GM != nullptr && Level != nullptr && Minecraft::ClientInstance()->MinecraftGame()->canUseKeys()) {
		Vec3 myPos = *Player->getPos();
		size_t entListSize = Level->getListSize();
		lookeing = Vec2(0, 0);
		if (entListSize > 0 && entListSize <= 5000) {
			for (size_t I = 0; I < entListSize; I++) {
				Actor* currEnt = Level->get(I);
				float distance = currEnt->getPos()->distance(myPos);
				if (currEnt != nullptr && currEnt != Player && distance <= 12.f){
					bool isFriend = false;
					for (auto Friend : Minecraft::Friends) {
						if (currEnt->getFormattedNameTag() == Friend) isFriend = true;
					}
					if (!isFriend && currEnt->isAlive() /*&& ((currEnt->getPos()->x != currEnt->getPosOld()->x) && (currEnt->getPos()->z != currEnt->getPosOld()->z))*/) {
						//sync rotation and position before attacking to prevent killaura kicks, aps needs to be about 10
						auto jMod = ClientManager::GetModuleByName("HiveDisabler"); if (jMod != nullptr && jMod->isEnabled) { jMod->onGmTick(); }
						GM->attack(currEnt);
						Player->swing();
						lookeing = getAngles(*Player->getPos(), *currEnt->getPos());
					}
				}
			}
		}
	}
	else {
		this->isEnabled = false;
	}
}

Vec2 Killaura::getAngles(Vec3 PlayerPosition, Vec3 EntityPosition) {
	Vec2 Angles;
	float dX = PlayerPosition.x - EntityPosition.x;
	float dY = PlayerPosition.y - EntityPosition.y;
	float dZ = PlayerPosition.z - EntityPosition.z;
	double distance = sqrt(dX * dX + dY * dY + dZ * dZ);
	Angles.x = (float)(atan2(dY, distance) * 180.0f / PI);
	Angles.y = (float)(atan2(dZ, dX) * 180.0f / PI) + 90.0f;
	return Angles;
};

void Killaura::onPacket(PacketType type, void* Packet, bool* cancel) {
	if (type == PacketType::Movement) {
		MovePlayerPacket* current = (MovePlayerPacket*)Packet;
		if (lookeing.x != 0 && lookeing.y != 0) {
			current->bodyRot.x = lookeing.x;
			current->bodyRot.y = lookeing.y;
		}
	}
}