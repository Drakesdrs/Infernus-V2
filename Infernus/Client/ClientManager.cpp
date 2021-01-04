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
std::vector<std::string> Minecraft::Friends = { "EchoHackCmd", "bricker1462", "SIMANNTHE1ST", "PatarFan" };

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
#include "Commands/SpeedCommand.h"
#include "Commands/SpamCommand.h"
#include "Commands/ColorCommand.h"

void ClientManager::InitCommands() {
	Commands.push_back(new TestCommand());
	Commands.push_back(new SpeedCommand());
	Commands.push_back(new SpamCommand());
	Commands.push_back(new ColorCommand());
}

/* Combat */
#include "Modules/Killaura.h"
#include "Modules/Hitbox.h"
#include "Modules/Triggerbot.h"
#include "Modules/TargetStrafe.h"
/* Movement */
#include "Modules/AirJump.h"
#include "Modules/Jetpack.h"
#include "Modules/AutoSprint.h"
#include "Modules/Jesus.h"
#include "Modules/Speed.h"
#include "Modules/Fly.h"
#include "Modules/AutoWalk.h"
/* Player */
#include "Modules/ClickTP.h"
#include "Modules/Velocity.h"
/* Visuals */
#include "Modules/TabGUI.h"
#include "Modules/ArrayList.h"
#include "Modules/Clickgui.h"
#include "Modules/PlayerFinder.h"
/* World */
#include "Modules/Instabreak.h"
#include "Modules/Nuker.h"
/* Exploits */
#include "Modules/NoPacket.h"
#include "Modules/Freecam.h"
#include "Modules/MineplexDisabler.h"
#include "Modules/HiveDisabler.h"
#include "Modules/CubecraftFly.h"
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
	Modules.push_back(new Speed());
	Modules.push_back(new Fly());
	Modules.push_back(new AutoWalk());
	Modules.push_back(new CubecraftFly());
	Modules.push_back(new TargetStrafe());
	/* Player */
	Modules.push_back(new ClickTP());
	Modules.push_back(new Velocity());
	/* Visuals */
	Modules.push_back(new TabGUI());
	Modules.push_back(new Arraylist());
	Modules.push_back(new Clickgui());
	Modules.push_back(new PlayerFinder());
	/* World */
	Modules.push_back(new Instabreak());
	Modules.push_back(new Nuker());
	/* Exploits */
	Modules.push_back(new NoPacket());
	Modules.push_back(new Freecam());
	Modules.push_back(new MineplexDisabler());
	Modules.push_back(new HiveDisabler());
	/* Other */
	Modules.push_back(new TestModule());
	Modules.push_back(new Spammer());
	Modules.push_back(new Uninject());

	InitModuleFiles();

	for (auto & Module : Modules) { //Initialize Categories
		bool exists = false;
		for (const auto& currCategory : Categories) {
			if (currCategory == Module->category) exists = true;
		}
		if (!exists) {
			Categories.push_back(Module->category);
		}
	}

	for (;;) {
		for (int I = 0; I < Modules.size(); I++) { //Loop Modules
			Modules.at(I)->onBaseTick();
		}
	}
}

class Module* ClientManager::GetModuleByName(std::string name) {
	for (auto Module : Modules) {
		if (Module->name == name) return Module;
	}
	return nullptr;
}

std::vector<class Module*> ClientManager::GetModulesFromCategory(std::string Category) {
	bool exists = false;
	for (const auto& Curr : Categories) {
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

void ClientManager::InitModuleFiles() {
	Utils::CreateDir("Infernus/Modules");

	/* JSON Data */

	std::string infernusPath = getenv("APPDATA") + std::string(R"(\..\Local\Packages\Microsoft.MinecraftUWP_8wekyb3d8bbwe\RoamingState\Infernus)");

	Utils::DebugLogOutput("Preparing Module Data");
	std::string path = std::string(infernusPath + "\\Modules\\Modules.json");

	if (!Utils::doesPathExist(path)) {
		CloseHandle(CreateFileA(path.c_str(), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr));
		JSON json = JSON::object();
		for (auto Module : ClientManager::Modules) {
			json[Module->name] = {
				{"Toggle", Module->isEnabled},
				{"State", Module->State},
				{"Key", Module->key}
			};
		}
		std::ofstream File;
		File.open(path, std::ofstream::trunc);
		if (File.is_open()) {
			File << json.dump();
		}
		File.close();
	}
	else {
		std::ifstream File(path);
		JSON json = JSON::parse(File);
		bool update = false;
		for (auto Module : Modules) {
			JSON data = json[Module->name];
			if (!data.is_null() && !data["Toggle"].is_null() && !data["State"].is_null() && !data["Key"].is_null()) {
				Module->isEnabled = data["Toggle"].get<bool>();
				Module->State = data["State"].get<std::string>();
				Module->key = data["Key"].get<uint64_t>();
			}
			else {
				json[Module->name] = {
					{"Toggle", Module->isEnabled},
					{"State", Module->State},
					{"Key", Module->key}
				};
				update = true;
			}
		}
		if (update) {
			std::ofstream File;
			File.open(path, std::ofstream::trunc);
			if (File.is_open()) {
				File << json.dump();
			}
			File.close();
		}
	}
	return;
}

void ClientManager::UpdateModuleData(Module* Mod) {
	std::string infernusPath = getenv("APPDATA") + std::string(R"(\..\Local\Packages\Microsoft.MinecraftUWP_8wekyb3d8bbwe\RoamingState\Infernus)");
	std::string path = std::string(infernusPath + "\\Modules\\Modules.json");

	if (!Utils::doesPathExist(path)) {
		InitModuleFiles();
		return;
	}
	else {
		std::ifstream File(path);
		JSON json = JSON::parse(File);
		JSON data = json[Mod->name];
		if (!data.is_null() && !data["Toggle"].is_null() && !data["State"].is_null() && !data["Key"].is_null()) {
			json[Mod->name] = {
				{"Toggle", Mod->isEnabled},
				{"State", Mod->State},
				{"Key", Mod->key}
			};

			std::ofstream File;
			File.open(path, std::ofstream::trunc);
			if (File.is_open()) {
				File << json.dump();
			}
			File.close();
		}
	}
}
