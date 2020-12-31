#pragma once
#include "../../Other/Module.h"
class ColorCommand : public Command {
public:
	ColorCommand() : Command::Command("color", " Change gui color.") {};
	void execute(std::string input, std::vector<std::string> words);
};

