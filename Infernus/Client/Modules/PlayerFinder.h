#pragma once
#include "../../Other/Module.h"
class PlayerFinder :
    public Module
{
public:
    PlayerFinder() : Module::Module("PlayerFinder", "Visuals", "Find Players' coordinates.") {};
    void onGmTick();
    void onRender();
private:
    std::vector<Vec3> XD;
    std::vector<std::string> XDD;
};