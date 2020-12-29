#include "ClientManager.h"
#include "../Other/Module.h"

std::string ClientManager::CommandPrefix = ".";

std::vector<Hook*> ClientManager::Hooks;
std::vector<Module*> ClientManager::Modules;
std::vector<std::string> ClientManager::Categories;
std::vector<Command*> ClientManager::Commands;

#include "Hooks/ClientInstance.h"
#include "Hooks/RenderContext.h"
#include "Hooks/GameMode.h"
#include "Hooks/Actor.h"
#include "Hooks/LoopbackPacketSender.h"
#include "Hooks/KeyItem.h"
#include "Hooks/MouseItem.h"

/* Minecraft */
ClientInstance* Minecraft::CachedInstance = nullptr; //Resolve error on compile
GameMode* Minecraft::CachedGameMode = nullptr; //Resolve error on compile
/* Packet */
uint64_t Packet::MovePlayerPacket_Addr = 0x0;
uint64_t Packet::PlayerAuthPacket_Addr = 0x0;
uint64_t Packet::TextPacket_Addr = 0x0;
/* Other */
std::vector<std::string> Minecraft::Friends = { "EchoHackCmd", "bricker1462", "SIMANNTHE1ST" };

void ClientManager::InitHooks() {

	if (MH_Initialize() == MH_OK) {
		Hooks.push_back(new ClientInstance_Hook());
		Hooks.push_back(new RenderContext());
		Hooks.push_back(new GameMode_Hook());
		Hooks.push_back(new Actor_Hooks());
		Hooks.push_back(new LoopbackPacketSender_Hook());
		Hooks.push_back(new KeyItem());
		Hooks.push_back(new MouseItem());
	}

	Utils::DebugLogOutput("Initializing Hooks...");

	for (int I = 0; I < Hooks.size(); I++) { //Initialize the hooks
		Hooks.at(I)->Install();
		Utils::DebugLogOutput("\n"); //New Line
	}
}

#include "Commands/TestCommand.h"

void ClientManager::InitCommands() {
	Commands.push_back(new TestCommand());
}

/* Combat */
#include "Modules/Killaura.h"
#include "Modules/Hitbox.h"
#include "Modules/Triggerbot.h"
/* Movement */
#include "Modules/AirJump.h"
#include "Modules/Jetpack.h"
#include "Modules/AutoSprint.h"
#include "Modules/Jesus.h"
/* Player */
#include "Modules/ClickTP.h"
/* Visuals */
#include "Modules/TabGUI.h"
#include "Modules/ArrayList.h"
#include "Modules/Clickgui.h"
/* World */
#include "Modules/Instabreak.h"
#include "Modules/Nuker.h"
/* Exploits */
#include "Modules/NoPacket.h"
#include "Modules/Freecam.h"
/* Other */
#include "Modules/TestModule.h"
#include "Modules/Spammer.h"
#include "Modules/Uninject.h"

void ClientManager::InitModules() {
	/* Combat */
	Modules.push_back(new Killaura());
	Modules.push_back(new Hitbox());
	Modules.push_back(new Triggerbot());
	/* Movement */
	Modules.push_back(new AirJump());
	Modules.push_back(new Jetpack());
	Modules.push_back(new AutoSprint());
	Modules.push_back(new Jesus());
	/* Player */
	Modules.push_back(new ClickTP());
	/* Visuals */
	Modules.push_back(new TabGUI());
	Modules.push_back(new Arraylist());
	Modules.push_back(new Clickgui());
	/* World */
	Modules.push_back(new Instabreak());
	Modules.push_back(new Nuker());
	/* Exploits */
	Modules.push_back(new NoPacket());
	Modules.push_back(new Freecam());
	/* Other */
	Modules.push_back(new TestModule());
	Modules.push_back(new Spammer());
	Modules.push_back(new Uninject());

	for (int I = 0; I < Modules.size(); I++) { //Initialize Categories
		bool exists = false;
		for (auto currCategory : Categories) {
			if (currCategory == Modules.at(I)->category) exists = true;
		}
		if (!exists) {
			Categories.push_back(Modules.at(I)->category);
		}
	}

	for (;;) {
		for (int I = 0; I < Modules.size(); I++) { //Loop Modules
			Modules.at(I)->onBaseTick();
		}
	}
}

std::vector<class Module*> ClientManager::GetModulesFromCategory(std::string Category) {
	bool exists = false;
	for (auto Curr : Categories) {
		if (Curr == Category) exists = true;
	}
	if (exists) {
		std::vector<Module*> ModulesArr;
		for (auto Module : Modules) {
			if (Module->category == Category) ModulesArr.push_back(Module);
		}
		return ModulesArr;
	}
	else {
		return std::vector<Module*>();
	}
}

bool ClientManager::handleCommand(std::string input) {
	if (input.rfind(CommandPrefix, 0) == 0) {
		std::string originLower = input;
		std::for_each(originLower.begin(), originLower.end(), [](char& c) {
			c = ::tolower(c); //Convert to lower case
		});
		originLower.erase(0, CommandPrefix.length()); //Remove prefix from newly lower case converted string
		std::istringstream iss(originLower);
		std::vector<std::string> words(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

		bool wasFound = false;
		std::vector<Command*> cmds = Commands;

		for (int I = 0; I < cmds.size(); I++) {
			for (int I = 0; I < Commands.size(); I++) {
				if (Commands.at(I)->input == words.at(0)) {
					wasFound = true;
					Commands.at(I)->execute(input, words);
				}
				else {
					if (Commands.at(I) == Commands.back()) {
						if (!wasFound) Commands.back()->respond("Unknown Command!");
						wasFound = false;
					};
				};
			};
			return true;
		}
	}
	return false;
}