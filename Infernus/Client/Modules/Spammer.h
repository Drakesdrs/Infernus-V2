#pragma once
#include "../../Other/Module.h"

class Spammer : public Module {
public:
	Spammer() : Module::Module("Spammer", "Other", "Spam") {};
	void onGmTick();
public:
	void setMessage(std::string newMsg) {
		this->message = newMsg;
	}
private:
	std::string message;
};