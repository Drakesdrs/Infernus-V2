#include "TeleportCommand.h"

void TeleportCommand::execute(std::string input, std::vector<std::string> words) {
	if (words.size() > 3) {
		bool correctParams = true;
		for (int I = 1; I < words.size(); I++) {
			if (!Utils::isStringFloat(words.at(I))) correctParams = false;
		}
		if (correctParams) {
			Vec3 tpPos = Vec3(std::atof(words.at(1).c_str()), std::atof(words.at(2).c_str()), std::atof(words.at(3).c_str()));
			LocalPlayer* myPlayer = Minecraft::ClientInstance()->LocalPlayer();
			if (myPlayer != nullptr) myPlayer->setPos(tpPos);
		}
		else {
			this->respond("Incorrect parameters were specified, failed to teleport!");
		}
	}
	else {
		this->respond("Missing all parameters, example: \n");
		this->respond(ClientManager::CommandPrefix + "tp 350 78 350");
	}
}