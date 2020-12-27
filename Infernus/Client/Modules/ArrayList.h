#pragma once
#include "../../Other/Module.h"
#include "../ClientManager.h"

class Arraylist : public Module {
public:
	Arraylist() : Module::Module("Arraylist", "Visuals", "Show enabled modules in a very epic way") {};
	void onRender();
	std::vector<Module*> sortstuff(std::vector<Module*> lol);
};