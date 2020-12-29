#pragma once
#include "../../Other/Module.h"

class Clickgui : public Module {
public:
	Clickgui() : Module::Module("Clickgui", "Visuals", "Lol") {/*this->isEnabled = true;*/};
	void onRender();
	void onMouse(char action, bool isDown, bool* cancel, int x, int y);
private:
	bool CatOpen = false, ModOpen = false, clicked = false;
	std::string OpenedCat = "";
	Module* OpenedMod;
	Vec2 Mousepos = Vec2(0, 0);
	MC_Colour BackColour = MC_Colour(140, 100, 170);
	MC_Colour FrontColour = MC_Colour(255, 255, 255);
	MC_Colour TextColour = MC_Colour(255, 255, 255); //(255, 128, 0)
};