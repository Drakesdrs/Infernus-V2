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
					std::ostringstream x;
					x << currPlayer->getPos()->x;
					std::ostringstream y;
					y << currPlayer->getPos()->y;
					std::ostringstream z;
					z << currPlayer->getPos()->z;
					std::string zpos(z.str());
					std::string xpos(x.str());
					std::string ypos(y.str());

					RenderUtils::RenderText("x: " + xpos + " y: " + ypos +  " z: " + zpos, Vec2(10, 60 + I * 10 + 30), MC_Colour(255, 255, 255), 1.0f, 1.0f);
				}
			}
		}
	}
}