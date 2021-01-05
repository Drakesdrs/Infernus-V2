#include "PlayerFinder.h"
#include <sstream>

void PlayerFinder::onRender() {


	if(Player != nullptr){	
	MultiPlayerLevel* entlist = Player->MultiPlayerLevel;		
		size_t size = entlist->getListSize();

		if (size > 0 && size <= 5000) {
			for (size_t I = 0; I < size; I++) {
				Actor* currPlayer = entlist->get(I);

				if (currPlayer != nullptr && currPlayer != Player) {
					std::string xpos = std::to_string(currPlayer->getPos()->x);
					std::string ypos = std::to_string(currPlayer->getPos()->y);
					std::string zpos = std::to_string(currPlayer->getPos()->z);


					RenderUtils::RenderText("x: " + xpos + " y: " + ypos +  " z: " + zpos, Vec2(10, 60 + I * 10 + 30), MC_Colour(255, 255, 255), 1.0f, 1.0f);
				}
			}
		}
	}
}