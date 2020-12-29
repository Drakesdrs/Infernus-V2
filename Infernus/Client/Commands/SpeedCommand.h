#pragma once
#include "../../Other/Module.h"

class SpeedCommand : public Command {
public:
	SpeedCommand() : Command::Command("speed", "Modifies the value for the Speed Module") {};
	void execute(std::string input, std::vector<std::string> words);
};