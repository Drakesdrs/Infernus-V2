#include "ColorCommand.h"
#include <sstream>
#include "../Modules/TabGUI.h"
int colorint = 1;

void ColorCommand::execute(std::string input, std::vector<std::string> words) {
	if (words.size() > 1) {
		std::stringstream hi(words.at(1));
		hi >> colorint;
		if (colorint < 5 && colorint > 0 || words.at(1) == "1" || words.at(1) == "2" || words.at(1) == "3" || words.at(1) == "4"){
			this->respond("Color set to " + words.at(1));

			if (colorint == 1) {
				TabGUI::color1 = 255; //r
				TabGUI::color2 = 128; //g
				TabGUI::color3 = 0; //b
			}
			else if (colorint == 2) {
				TabGUI::color1 = 0;
				TabGUI::color2 = 255;
				TabGUI::color3 = 0;
			}
			else if (colorint == 3) {
				TabGUI::color1 = 0;
				TabGUI::color2 = 0;
				TabGUI::color3 = 255;
			}
			else if (colorint == 4) {
				TabGUI::color1 = 0;
				TabGUI::color2 = 0;
				TabGUI::color3 = 0;
			}


		}
		else {
			this->respond("Please input a color id from 1 - 4");
		}
	}
	else {
		this->respond("Invalid Params");
	}
}

