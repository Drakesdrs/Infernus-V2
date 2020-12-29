#pragma once
#include "../../Other/Module.h"

class SpamCommand : public Command {
public:
	SpamCommand() : Command::Command("spam", "Modifies the message for the Spammer Module") {};
	void execute(std::string input, std::vector<std::string> words);
};