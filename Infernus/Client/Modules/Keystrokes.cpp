#include "Keystrokes.h"

void Keystrokes::onGmTick() {
	wKey = Utils::usingKey(0x57);
	sKey = Utils::usingKey(0x53);
	aKey = Utils::usingKey(0x41);
	dKey = Utils::usingKey(0x44);
}

void Keystrokes::onRender() {
	if (Minecraft::ClientInstance() != nullptr && Minecraft::ClientInstance()->MinecraftGame()->canUseKeys()) {
		Vec2 screen = Minecraft::ClientInstance()->GuiData()->ScaledResolution;
		MC_Colour color = MC_Colour(TabGUI::color1, TabGUI::color2, TabGUI::color3);
		MC_Colour colorPressed = MC_Colour(TabGUI::color1 - 40, TabGUI::color2 - 40, TabGUI::color3 - 40);

		RenderUtils::DrawRectangle(Vec4(35, screen.y - 65, 35 + 30.f, screen.y - 65 + 30.f), wKey ? colorPressed : color, .9, 2); //w
		RenderUtils::RenderText("W", Vec2(44, screen.y - 60), wKey ? colorPressed : color, 2.5, 1);

		RenderUtils::DrawRectangle(Vec4(35, screen.y - 32, 35 + 30.f, screen.y - 32 + 30.f), sKey ? colorPressed : color, .9, 2); //s
		RenderUtils::RenderText("S", Vec2(44, screen.y - 26), sKey ? colorPressed : color, 2.5, 1);

		RenderUtils::DrawRectangle(Vec4(2, screen.y - 32, 2 + 30.f, screen.y - 32 + 30.f), aKey ? colorPressed : color, .9, 2); //a
		RenderUtils::RenderText("A", Vec2(12, screen.y - 26), aKey ? colorPressed : color, 2.5, 1);

		RenderUtils::DrawRectangle(Vec4(68, screen.y - 32, 68 + 30.f, screen.y - 32 + 30.f), dKey ? colorPressed : color, .9, 2); //d
		RenderUtils::RenderText("D", Vec2(78, screen.y - 26), dKey ? colorPressed : color, 2.5, 1);

		RenderUtils::FlushText();
	}
}