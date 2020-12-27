#include "ArrayList.h"

void Arraylist::onRender() {

	if (Minecraft::ClientInstance() != nullptr) {
		auto Categories = ClientManager::Categories;
		std::vector<Module*> XP;
		for (int i = 0; i < Categories.size(); i++) {
			auto Modules = ClientManager::GetModulesFromCategory(Categories.at(i));
			for (auto Mod : Modules) {
				if (Mod->isEnabled) XP.push_back(Mod);
			}
		}

		XP = sortstuff(XP);

		//render stuff idk
		for (int i = 0; i < XP.size(); i++) {
			RenderUtils::RenderText(XP.at(i)->name, Vec2(200, 10 + i * 10), MC_Colour(255, 255, 255), 1.0f, 1.0f);
		}
	}


}

std::vector<Module*> Arraylist::sortstuff(std::vector<Module*> lol) {
	bool changed = true;
	while (changed) {
		changed = false;
		for (int i = 0; i < lol.size() - 1; i++) {
			if (RenderUtils::GetTextWidth(lol.at(i)->name,1.0f) < RenderUtils::GetTextWidth(lol.at(i + 1)->name,1.0f)) {
				Module * tmp = lol.at(i);
				
				lol.at(i) = lol.at(i + 1);
				lol.at(i + 1) = tmp;
				changed = true;
			}
		}
	}
	return lol;
}