#include "PlayerFinder.h"

void PlayerFinder::onGmTick() {
	XD.clear();
	XDD.clear();
	XDDD.clear();
	if (Player != nullptr) {
		offsetCalc = *Player->getPos();
		MultiPlayerLevel* entlist = Player->MultiPlayerLevel;
		size_t size = entlist->getListSize();
		if (size > 0 && size <= 5000) {
			for (size_t I = 0; I < size; I++) {
				Actor* currEnt = entlist->get(I);
				currEnt->setNameTagVisible(true);
				if (currEnt != nullptr && currEnt != Player && (currEnt->getFormattedNameTag().size() > 5)) {
					XD.push_back(*currEnt->getPos());
					XDD.push_back(currEnt->getFormattedNameTag());
					XDDD.push_back(currEnt->getPos()->distance(offsetCalc));
				}
			}
		}
	}
}

void PlayerFinder::onRender() {
	if (XD.size() > 0 && Minecraft::ClientInstance() != nullptr && Minecraft::ClientInstance()->MinecraftGame()->canUseKeys()) {
		if (XD.size() >= RenderEnt) sortstuff();
		for (int i = 0; i < min(XD.size(), RenderEnt); i++) {
			RenderUtils::RenderText(XDD.at(i) + (offset ? " [X:" + std::to_string(int(offsetCalc.x - XD.at(i).x)) + ", Y:" + std::to_string(int(offsetCalc.y - XD.at(i).y)) + ", Z:" + std::to_string(int(offsetCalc.z - XD.at(i).z)) + "]" : " [X:" + std::to_string(int(XD.at(i).x)) + ", Y:" + std::to_string(int(XD.at(i).y)) + ", Z:" + std::to_string(int(XD.at(i).z)) + "]"), Vec2(10, 150 + i * 10 + 10), MC_Colour(255, 255, 255), 1.0f, 1.0f);
		}
		RenderUtils::FlushText();
	}
}

void PlayerFinder::sortstuff() {
	bool changed = true;
	while (changed) {
		changed = false;
		for (int i = 0; i < XD.size() - 1; i++) {
			if (XDDD.at(i) > XDDD.at(i + 1)) {
				Vec3 tmp1 = XD.at(i);
				XD.at(i) = XD.at(i + 1);
				XD.at(i + 1) = tmp1;

				std::string tmp2 = XDD.at(i);
				XDD.at(i) = XDD.at(i + 1);
				XDD.at(i + 1) = tmp2;

				int tmp3 = XDDD.at(i);
				XDDD.at(i) = XDDD.at(i + 1);
				XDDD.at(i + 1) = tmp3;
				changed = true;
			}
		}
	}
};