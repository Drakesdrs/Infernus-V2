#pragma once
#include "../../Other/Module.h"

class TeleportCommand : public Command {
public:
	TeleportCommand() : Command::Command("tp", "Teleport to the specified coordinates") {};
	void execute(std::string input, std::vector<std::string> words);
};