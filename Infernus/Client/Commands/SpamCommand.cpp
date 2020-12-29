#include "SpamCommand.h"
#include "../Modules/Spammer.h"

void SpamCommand::execute(std::string input, std::vector<std::string> words) {
	if (words.size() > 1) {
		Spammer* spamMod = (Spammer*)ClientManager::GetModuleByName("Spammer");
		if (spamMod != nullptr) {
			spamMod->setMessage(input.erase(0, words.at(0).length() + 2));
			this->respond("Updated message for Spammer!");
		}
		else {
			this->respond("Something went wrong fetching the Spammer Module!");
		}
	}
	else {
		this->respond("You did not enter the required parameters!");
	}
}