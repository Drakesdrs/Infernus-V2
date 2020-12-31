#include "AutoWalk.h"

void AutoWalk::onTick() {

	if (Minecraft::ClientInstance() != 0) {
		if (Minecraft::ClientInstance()->LocalPlayer() != 0) {
			LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
			MultiPlayerLevel* ent = Player->MultiPlayerLevel;
			size_t size = ent->getListSize();


			if (size > 0 && size <= 5000) {
				for (size_t i = 0; i < size; i++) {
					Actor* currPlayer = ent->get(i);
					if (currPlayer != nullptr && currPlayer != Player) {
						Player->velocity.z = cos((currPlayer->getPos()->z + 90) * (3.14159 / 180.0f)) * 0.235f;
						Player->velocity.x = cos((currPlayer->getPos()->x + 90) * (3.14159 / 180.0f)) * 0.235f;
						Player->velocity.y = cos((currPlayer->getPos()->y + 90) * (3.14159 / 180.0f)) * 0.235f;

					}
					else {
						
					}
				}


			}
		}
	}
}

	
