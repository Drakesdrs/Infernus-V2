#include "PlayerFinder.h"

void PlayerFinder::onGmTick() {
	XD.clear();
	XDD.clear();
	if (Player != nullptr) {
		MultiPlayerLevel* entlist = Player->MultiPlayerLevel;
		size_t size = entlist->getListSize();
		if (size > 0 && size <= 5000) {
			for (size_t I = 0; I < size; I++) {
				Actor* currEnt = entlist->get(I);
				if (currEnt != nullptr && currEnt != Player && currEnt->getFormattedNameTag().size() > 5) {
					XD.push_back(Vec3(floor(currEnt->getPos()->x), floor(currEnt->getPos()->y), floor(currEnt->getPos()->z)));
					XDD.push_back(currEnt->getFormattedNameTag());
				}
			}
		}
	}
}
	

void PlayerFinder::onRender() {
	if (XD.size() > 0) {
		for (size_t i = 0; i < XD.size(); i++) {
			RenderUtils::RenderText(XDD.at(i) + " x: " + std::to_string(int(XD.at(i).x)) + " y: " + std::to_string(int(XD.at(i).y)) + " z: " + std::to_string(int(XD.at(i).x)), Vec2(10, 60 + i * 10 + 30), MC_Colour(255, 255, 255), 1.0f, 1.0f);
		}
	}
}