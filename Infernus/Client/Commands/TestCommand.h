#pragma once
#include "../../Other/Module.h"

class TestCommand : public Command {
public:
	TestCommand() : Command::Command("test", "Test Command") {};
	void execute(std::string input, std::vector<std::string> words);
};