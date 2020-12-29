#pragma once
#include "../../Other/Module.h"

class Spammer : public Module {
public:
	Spammer() : Module::Module("Spammer", "Other", "Spam") {};
	void onGmTick();
private:
	std::string message;
	void setMessage(std::string newMsg) {
		this->message = newMsg;
	}
};