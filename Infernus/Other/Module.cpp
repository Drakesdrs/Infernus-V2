#include "Module.h"

#include <utility>

Module::Module(std::string name, std::string category, std::string description, uint64_t key) {
	this->name = std::move(name);
	this->category = std::move(category);
	this->description = std::move(description);
	this->key = key;
}

void Module::onBaseTick() {
	onLoop();
	if (wasEnabled != isEnabled) {
		if (isEnabled) {
			onEnable();
			closing = false;
		}
		else {
			onDisable();
			closing = true;
		}
		Animating = true;
		wasEnabled = isEnabled;
		Minecraft::ClientInstance()->clientMessage(this->name + " " + std::string(isEnabled ? "Enabled" : "Disabled"));
		ClientManager::UpdateModuleData(this);
	}
	if (isEnabled) onTick();
}

void Command::respond(std::string output) {
	Minecraft::ClientInstance()->clientMessage(std::move(output));
}