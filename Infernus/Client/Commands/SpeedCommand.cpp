#include "SpeedCommand.h"
#include "../Modules/Speed.h"

void SpeedCommand::execute(std::string input, std::vector<std::string> words) {
	if (words.size() > 1) {
		if (Utils::isStringFloat(words.at(1))) {
			Speed* speedMod = (Speed*)ClientManager::GetModuleByName("Speed");
			if (speedMod != nullptr) {
				speedMod->setSpeed(std::atof(words.at(1).c_str()));
				this->respond("Set speed to " + words.at(1));
			}
			else {
				this->respond("Something went wrong fetching the Speed Module!");
			}
		}
		else {
			this->respond("You did not enter a valid number!");
		}
	}
	else {
		this->respond("You did not enter the required parameters!");
	}
}