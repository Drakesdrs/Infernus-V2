#include "TargetStrafe.h"
#include "Speed.h"

void TargetStrafe::onGmTick() {
	MultiPlayerLevel* Level = Player->MultiPlayerLevel;
	GameMode* GM = Minecraft::GameMode();
	bool wKey = Utils::usingKey(0x57), sKey = Utils::usingKey(0x53), aKey = Utils::usingKey(0x41), dKey = Utils::usingKey(0x44), xddxd = false;
	if (Player->isJumping()) xddxd = true; else xddxd = false;
	if (Player != nullptr && GM != nullptr && Level != nullptr && (((aKey || dKey || sKey || wKey) && !spacerot ) || (spacerot && xddxd))) {
		Vec3 myPos = *Player->getPos();
		size_t entListSize = Level->getListSize();
		if (entListSize > 0 && entListSize <= 5000) {
			float distance = 99;
			float distanc = 999;
			for (size_t I = 0; I < entListSize; I++) {
				Actor* currEnt = Level->get(I);
				distance = currEnt->getPos()->distance(myPos);
				if (currEnt != nullptr && currEnt != Player) {
					bool isFriend = false;
					for (auto Friend : Minecraft::Friends) {
						if (currEnt->getFormattedNameTag() == Friend) isFriend = true;
					}
					if (!isFriend && currEnt->isAlive() && currEnt->getFormattedNameTag().size() > 5 /*&& ((currEnt->getPos()->x != currEnt->getPosOld()->x) && (currEnt->getPos()->z != currEnt->getPosOld()->z))*/) {
						if (distanc > distance) {
							distanc = distance;
							EntPos = *currEnt->getPos();
							if (goback) look = -currEnt->bodyRot.y;
						}
					}
				}
			}
			if (EntPos != Vec3(0, 0, 0) && distanc <= CatchDistance) {
				Vec2 CalcRot = Utils::getAngles(*Player->getPos(), EntPos);
				if (!goback) {
					if (aKey && !dKey) {
						clockwise = false;
					}
					else if (dKey && !aKey) {
						clockwise = true;
					}

					
					if (avoidvoid) {
						bool onvoid = true;
						for (int i = 0; i < ceil(Player->getPos()->y) + 2; i++) {
							if (Player->BlockSource->getBlock(Vec3_i(Player->getPos()->x, Player->getPos()->y + 2 - i, Player->getPos()->x))->BlockLegacy->BlockID() != 0) {
								onvoid = false;
							}
						}
						if (onvoid) clockwise = !clockwise;
					}

					if (clockwise) {
						CalcRot.y += 90.0f;
						if (distanc > StrafeDistance) CalcRot.y -= 45.0f;
					}
					else {
						CalcRot.y -= 90.0f;
						if (distanc > StrafeDistance) CalcRot.y += 45.0f;
					}
				}
				else {
					//stuff to go to where the enemy is not looking
				}

				Vec2 CalcAngles = Vec2((CalcRot.x) * -(PI / 180.f), (CalcRot.y + 90.0f) * (PI / 180.f));
				Player->velocity = Vec3(cos(CalcAngles.y) * cos(CalcAngles.x) * speed, Player->velocity.y, sin(CalcAngles.y) * cos(CalcAngles.x) * speed);
			}
		}
	}
}