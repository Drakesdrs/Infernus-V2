#include "DVDScreensaver.h"

void Screensaver::onRender() {
	if (Minecraft::ClientInstance() != nullptr) {
		Position.x += Velocity.x / dividerr;
		Position.y += Velocity.y / dividerr;
		Vec2 Xp = Minecraft::ClientInstance()->GuiData()->ScaledResolution;
		if (Xp.x < Position.x + RenderUtils::GetTextWidth("SCREENSAVER", scale) / 2 || Position.x - RenderUtils::GetTextWidth("SCREENSAVER", scale) / 2 < 0) {
			Velocity.x = -Velocity.x;
			XD = MC_Colour(rand() % 127 + 127, rand() % 127 + 127, rand() % 127 + 127);
		}
		if (Xp.y < Position.y + 10 * scale * 2 || Position.y < 0) {
			Velocity.y = -Velocity.y;
			XD = MC_Colour(rand() % 127 + 127, rand() % 127 + 127, rand() % 127 + 127);
		}
		RenderUtils::RenderText("DVD", Vec2(Position.x - RenderUtils::GetTextWidth("DVD", scale) / 2, Position.y), XD, scale, 1);
		RenderUtils::RenderText("SCREENSAVER", Vec2(Position.x - RenderUtils::GetTextWidth("SCREENSAVER", scale) / 2, Position.y + 10 * scale), XD, scale, 1);
	}
}