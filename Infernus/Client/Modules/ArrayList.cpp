#include "ArrayList.h"

void Arraylist::onRender() {

	if (Minecraft::ClientInstance() != nullptr) {
		auto Categories = ClientManager::Categories;
		std::vector<Module*> XP;
		for (int i = 0; i < Categories.size(); i++) {
			auto Modules = ClientManager::GetModulesFromCategory(Categories.at(i));
			for (auto Mod : Modules) {
				if (Mod->isEnabled || Mod->Animating) XP.push_back(Mod);
			}
		}

		XP = sortstuff(XP);

		//render stuff idk
		if (XP.size() > 0) {
			MC_Colour colour(255, 255, 255);
			int Screensize = 950; //here screen size
			int lol = 0, lol1 = RenderUtils::GetTextWidth(XP.at(0)->name + ((XP.at(0)->State != "") ? " [" + XP.at(0)->State + "]" : ""), 1);
			RenderUtils::FillRectangle(Vec4(Screensize - lol1 - 2, 9, Screensize + 1, 10), colour, 1.0f); //top
			for (; lol < XP.size(); lol++) {
				int lol2 = RenderUtils::GetTextWidth(XP.at(lol)->name + ((XP.at(lol)->State != "") ? " [" + XP.at(lol)->State + "]" : ""), 1), lol3 = 0;

				if (XP.at(lol)->Animating) {
					int AnimOffset = lol2 * XP.at(lol)->AnimateProgress / 50;

					if (XP.at(lol)->closing)
						XP.at(lol)->AnimateProgress--;
					else
						XP.at(lol)->AnimateProgress++;

					if (XP.at(lol)->closing && XP.at(lol)->AnimateProgress < 0)
						XP.at(lol)->Animating = false;
					if (!XP.at(lol)->closing && XP.at(lol)->AnimateProgress > 50)
						XP.at(lol)->Animating = false;

					RenderUtils::RenderText(XP.at(lol)->name + ((XP.at(lol)->State != "") ? " [" + XP.at(lol)->State + "]" : ""), Vec2(Screensize - AnimOffset, 10 + lol * 10), colour, 1.0f, 1.0f);

				}
				else
					RenderUtils::RenderText(XP.at(lol)->name + ((XP.at(lol)->State != "") ? " [" + XP.at(lol)->State + "]" : ""), Vec2(Screensize - lol2, 10 + lol * 10), colour, 1.0f, 1.0f);

				if (lol + 1 < XP.size()) { lol3 = RenderUtils::GetTextWidth(XP.at(lol + 1)->name + ((XP.at(lol + 1)->State != "") ? " [" + XP.at(lol + 1)->State + "]" : ""), 1); } else { lol3 = -2; }
				//RenderUtils::FillRectangle(Vec4(Screensize - lol2, 10 + lol * 10, Screensize, 20 + lol * 10), MC_Colour(0, 0, 0), 0.5f); //back
				RenderUtils::FillRectangle(Vec4(Screensize - lol2 - 2, 10 + lol * 10, Screensize - lol2 - 1, 20 + lol * 10), colour, 1.0f); // left
				RenderUtils::FillRectangle(Vec4(Screensize - lol2 - 2, 20 + lol * 10, Screensize - lol3 - 1, 21 + lol * 10), colour, 1.0f); // bottom
			}
			RenderUtils::FillRectangle(Vec4(Screensize, 9, Screensize + 1, 10 + lol * 10), colour, 1.0f); //right
		}

		XP.clear();
	}
}

std::vector<Module*> Arraylist::sortstuff(std::vector<Module*> lol) {
	bool changed = true;
	while (changed) {
		changed = false;
		for (int i = 0; i < lol.size() - 1; i++) {
			if (RenderUtils::GetTextWidth(lol.at(i)->name + lol.at(i)->State, 1.0f) < RenderUtils::GetTextWidth(lol.at(i + 1)->name + lol.at(i + 1)->State, 1.0f)) {
				Module* tmp = lol.at(i);

				lol.at(i) = lol.at(i + 1);
				lol.at(i + 1) = tmp;
				changed = true;
			}
		}
	}
	return lol;
}