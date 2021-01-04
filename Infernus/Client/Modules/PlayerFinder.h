#pragma once
#include "../../Other/Module.h"
class PlayerFinder :
    public Module
{
public:
    PlayerFinder() : Module::Module("PlayerFinder", "Visuals", "Find Players' coordinates.") {};
    void onRender();
};

