#pragma once
#include <utility>

#include "../SDK/Minecraft.h"
#include "../Client/ClientManager.h"

class Module {
public:
	std::string name, category, description;
	uint64_t key;
	bool isEnabled = false, wasEnabled = false;
	Module(std::string name, std::string category, std::string description, uint64_t key = NULL);
	
	std::string State;
	int AnimateProgress = 1;
	bool closing = false;
	bool Animating = false;

	void onBaseTick();
	virtual void onLoop() {};
	virtual void onTick() {};
	virtual void onEnable() {};
	virtual void onDisable() {};

	virtual void onRender() {};
	virtual void onGmTick() {};
	virtual void onKey(uint64_t key, bool isDown, bool* cancel) {};
	virtual void onMouse(char action, bool isDown, bool* cancel) {};

	virtual void onPacket(PacketType type, void* Packet, bool* cancel) {};

	virtual void onStartDestroyBlock(GameMode* GM, Vec3_i* blockPos, uint8_t blockFace) {};
	virtual void onPlayerAttack(LocalPlayer* attacker, Actor* victim) {};

public:

	void setState(std::string newState) {
		this->State = std::move(newState);
	}

	void toggle() {
		this->isEnabled = !this->isEnabled;
	}
};

class Hook {
public:
	virtual void Install() {};
};

class Command {
public:
	std::string input, description;
	Command(std::string input, std::string description) {
		this->input = std::move(input);
		this->description = std::move(description);
	}
	virtual void execute(std::string input, std::vector<std::string> words) {};
	void respond(std::string output);
};