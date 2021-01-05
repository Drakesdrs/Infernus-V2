#include "HudStuff.h"

void info::onGmTick() {
	if (Minecraft::ClientInstance() != nullptr && Player != nullptr) {
		stuffToRender.clear();
		Oldpos = pos;
		pos = *Player->getPos();
		if (BPS) {
			bps = float(pos.distance(Oldpos)) * 20;
			std::string Xp = std::to_string(bps);
			Xp.erase(Xp.begin() + 4, Xp.end());
			stuffToRender.push_back(Xp + "BPS");
		}

		if (Position) {
			stuffToRender.push_back("X: " + std::to_string(int(floor(pos.x))) + " Y: " + std::to_string(int(floor(pos.y))) + " Z: " + std::to_string(int(floor(pos.z))));
		}

		if (Entities) {
			std::string Xp;
			if (Player->MultiPlayerLevel != nullptr) {
				size_t entListSize = Player->MultiPlayerLevel->getListSize();
				if (FilterEntites) {
					if (entListSize > 0 && entListSize <= 5000) {
						int counr = 0;
						for (size_t I = 0; I < entListSize; I++) {
							if (Player->MultiPlayerLevel->get(I) != nullptr && Player->MultiPlayerLevel->get(I) != Player && Player->MultiPlayerLevel->get(I)->getFormattedNameTag().size() > 5) {
								counr++;
							}
						}
						Xp = std::to_string(counr) + " filtered";
					}
				}
				else
					Xp = std::to_string(entListSize);
			}
			stuffToRender.push_back(Xp + " entities found");
		}
	}
}


void info::onRender() {
	if (Minecraft::ClientInstance() != nullptr && stuffToRender.size() > 0) {
		Vec2 xdhahaha = Minecraft::ClientInstance()->GuiData()->ScaledResolution;
		for (int i = 0; i < stuffToRender.size(); i++) {
			RenderUtils::RenderText(stuffToRender.at(i), Vec2(1, xdhahaha.y - stuffToRender.size() * 10 + i * 10 + 1), MC_Colour(255, 255, 255), 1, 1);
		}
	}
}