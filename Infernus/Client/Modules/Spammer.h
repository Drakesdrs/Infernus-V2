#pragma once
#include "../../Other/Module.h"

class Spammer : public Module {
public:
	Spammer() : Module::Module("Spammer", "Other", "Spam") {
		this->State = "Bypass";
	};
	void onGmTick();
public:
	void setMessage(std::string newMsg) {
		this->message = newMsg;
	}
	void setDelay(int ms) {
		this->delay = ms;
	}
private:
	std::chrono::time_point<std::chrono::steady_clock> savedTime = std::chrono::high_resolution_clock::now();
	std::string message = std::string("Infernus Client: https://discord.gg/DkFXxjBBQ5");
	int delay = 1000;
};