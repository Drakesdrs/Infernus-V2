#pragma once
#include "../../Other/Module.h"
class Screensaver : public Module {
public:
    Screensaver() : Module::Module("L", "Visuals", "idk :)") { Velocity = Vec2(rand() % 6 - 3, rand() % 6 - 3); Position = Vec2(rand() % 1000, rand() % 500); XD = MC_Colour(rand() % 127 + 127, rand() % 127 + 127, rand() % 127 + 127); };
    void onGmTick();
    void onRender();
private:
    Vec2 Velocity, Position;
    MC_Colour XD;
    float scale = 2.0f;
    int dividerr = 2;
};