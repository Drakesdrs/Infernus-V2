#pragma once
#include "../Other/Utils.h"

class ClientManager {
public:
	static std::string CommandPrefix;
public:
	static void InitHooks();
	static void InitCommands();
	static void InitModules();
	static std::vector<class Hook*> Hooks;
	static std::vector<class Module*> Modules;
	static std::vector<std::string> Categories;
	static std::vector<class Command*> Commands;

	static class Module* GetModuleByName(std::string name);
	static std::vector<class Module*> GetModulesFromCategory(std::string Category);

	static bool handleCommand(std::string input);
};