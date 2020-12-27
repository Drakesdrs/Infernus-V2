#pragma once
#include "../../Other/Module.h"

class TabGUI : public Module {
public:
	TabGUI() : Module::Module("TabGUI", "Visuals", "Manage Modules via Arrow Keys", VK_TAB) {
		this->isEnabled = true;
	};
	void onRender();
	void onKey(uint64_t key, bool isDown, bool* cancel);
private:
	int currentCategory = 0, currentModule = 0;
	bool selectedCategory = false, selectedModule = 0;
	MC_Colour XD = MC_Colour(0, 0, 0); //255, 127, 0
};