#include "Keystrokes.h"

void Keystrokes::onRender() {
	if (Minecraft::ClientInstance() != nullptr && Minecraft::ClientInstance()->MinecraftGame()->canUseKeys()) {
		Vec2 screen = Minecraft::ClientInstance()->GuiData()->ScaledResolution;
		MC_Colour color = MC_Colour(TabGUI::color1,TabGUI::color2,TabGUI::color3);
		MC_Colour colorPressed = MC_Colour(TabGUI::color1 - 20, TabGUI::color2 - 20, TabGUI::color3 - 20);

		if (Utils::usingKey(0x57)) {
			RenderUtils::DrawRectangle(Vec4(35, screen.y - 65, 35 + 30.f, screen.y - 65 + 30.f), colorPressed, .9, 2); //w
			RenderUtils::RenderText("W", Vec2(44, screen.y - 60), colorPressed, 2.5, 1);
		}
		else {
			RenderUtils::DrawRectangle(Vec4(35, screen.y - 65, 35 + 30.f, screen.y - 65 + 30.f), color, .9, 2); 
			RenderUtils::RenderText("W", Vec2(44, screen.y - 60), color, 2.5, 1);
		}
		

		if (Utils::usingKey(0x53)) {
			RenderUtils::DrawRectangle(Vec4(35, screen.y - 32, 35 + 30.f, screen.y - 32 + 30.f), colorPressed, .9, 2); //s
			RenderUtils::RenderText("S", Vec2(44, screen.y - 26), colorPressed, 2.5, 1);
		} else {
			RenderUtils::DrawRectangle(Vec4(35, screen.y - 32, 35 + 30.f, screen.y - 32 + 30.f), color, .9, 2); //s
			RenderUtils::RenderText("S", Vec2(44, screen.y - 26), color, 2.5, 1);
		}


		if (Utils::usingKey(0x41)) {
			RenderUtils::DrawRectangle(Vec4(2, screen.y - 32, 2 + 30.f, screen.y - 32 + 30.f), colorPressed, .9, 2); //a
			RenderUtils::RenderText("A", Vec2(12, screen.y - 26), colorPressed, 2.5, 1);
		}
		else {
			RenderUtils::DrawRectangle(Vec4(2, screen.y - 32, 2 + 30.f, screen.y - 32 + 30.f), color, .9, 2); //a
			RenderUtils::RenderText("A", Vec2(12, screen.y - 26), color, 2.5, 1);
		}


		if (Utils::usingKey(0x44)) {
			RenderUtils::DrawRectangle(Vec4(68, screen.y - 32, 68 + 30.f, screen.y - 32 + 30.f), colorPressed, .9, 2); //d
			RenderUtils::RenderText("D", Vec2(78, screen.y - 26), colorPressed, 2.5, 1);
		}
		else {
			RenderUtils::DrawRectangle(Vec4(68, screen.y - 32, 68 + 30.f, screen.y - 32 + 30.f), color, .9, 2); //d
			RenderUtils::RenderText("D", Vec2(78, screen.y - 26), color, 2.5, 1);
		}



	}
}