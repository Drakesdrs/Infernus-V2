#include "Clickgui.h"

void Clickgui::onRender() {
	if (Minecraft::ClientInstance() != nullptr) {
		std::vector<std::string> Categories = ClientManager::Categories;
		//std::vector<Module *> Modules = ClientManager::GetModulesFromCategory(Categories.at(0));

		Vec4 Screensizestuff = Vec4(150, 50, 550, 450);
		Vec2 offset = Vec2(20, 20);
		int boxsize = 100;


		if (!CatOpen) {
			RenderUtils::FillRectangle(Screensizestuff, BackColour, 0.5);
			RenderUtils::DrawRectangle(Screensizestuff, FrontColour, 0.5, 1);
			int helpersmh = -1;
			for (int i = 0; i < Categories.size(); i++) {
				(i % 3 == 0) ? helpersmh++ : 1;
				Vec4 immagokms = Vec4(Screensizestuff.x + ((i % 3) * boxsize) + offset.x, Screensizestuff.y + (helpersmh * boxsize) + offset.y, Screensizestuff.x + ((i % 3) * boxsize) + offset.x + boxsize, Screensizestuff.y + (helpersmh * boxsize) + offset.y + boxsize);
				RenderUtils::DrawRectangle(immagokms, FrontColour, 1.0f, 1);
				RenderUtils::RenderText(Categories.at(i), Vec2((immagokms.z - immagokms.x) / 2 + immagokms.x - RenderUtils::GetTextWidth(Categories.at(i), 1) / 2, (immagokms.w - immagokms.y) / 2 + immagokms.y - 5), TextColour, 1.0f, 1.0f);
				if (clicked && Utils::IsInnit(Mousepos,immagokms)) {
					clicked = false;
					CatOpen = true;
				}
			}
		}
	}
}

void Clickgui::onMouse(char action, bool isDown, bool* cancel, int x, int y) {
	if (action == 2 && isDown) {
		Mousepos = Vec2(x, y);
		clicked = true;
		Minecraft::ClientInstance()->clientMessage("Test!" + std::to_string(Mousepos.x) + " " + std::to_string(Mousepos.x) + " ");
	}
}