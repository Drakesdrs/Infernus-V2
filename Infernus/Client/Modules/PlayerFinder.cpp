#include "PlayerFinder.h"

void PlayerFinder::onGmTick() {
	XD.clear();
	if (Player != nullptr) {
		offsetCalc = *Player->getPos();
		MultiPlayerLevel* entlist = Player->MultiPlayerLevel;
		size_t size = entlist->getListSize();
		if (size > 0 && size <= 5000) {
			for (size_t I = 0; I < size; I++) {
				Actor* currEnt = entlist->get(I);
				if (currEnt != nullptr && currEnt != Player && currEnt->getFormattedNameTag().size() > 5) {
					XD.push_back(currEnt);
				}
			}
		}
	}
}

void PlayerFinder::onRender() {
	if (XD.size() > 0 && Minecraft::ClientInstance() != nullptr && Minecraft::ClientInstance()->MinecraftGame()->canUseKeys()) {
		if (XD.size() > RenderEnt) sortstuff();
		for (int i = 0; i < min(XD.size(), RenderEnt); i++) {
			if (XD.at(i) != nullptr) {
				RenderUtils::RenderText(XD.at(i)->getFormattedNameTag() + (offset ? " [ X:" + std::to_string(int(offsetCalc.x - XD.at(i)->getPos()->x)) + ", Y:" + std::to_string(int(offsetCalc.y - XD.at(i)->getPos()->y)) + ", Z:" + std::to_string(int(offsetCalc.z - XD.at(i)->getPos()->z)) + " ]" : " [ X:" + std::to_string(int(XD.at(i)->getPos()->x)) + ", Y:" + std::to_string(int(XD.at(i)->getPos()->y)) + ", Z:" + std::to_string(int(XD.at(i)->getPos()->z)) + "]") + (BPS ? std::to_string(float(XD.at(i)->getPos()->distance(*XD.at(i)->getPosOld()))) + "bps" : ""), Vec2(10, 60 + i * 10 + 30), MC_Colour(255, 255, 255), 1.0f, 1.0f);
			}
		}
	}
}

void PlayerFinder::sortstuff() {
	bool changed = true;
	while (changed) {
		changed = false;
		for (int i = 0; i < XD.size() - 1; i++) {
			if (XD.at(i)->getPos()->distance(offsetCalc) > XD.at(i + 1)->getPos()->distance(offsetCalc)) {
				Actor* tmp = XD.at(i);
				XD.at(i) = XD.at(i + 1);
				XD.at(i + 1) = tmp;
				changed = true;
			}
		}
	}
};