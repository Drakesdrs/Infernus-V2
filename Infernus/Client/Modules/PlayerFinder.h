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
    void sortstuff();
    std::vector<Actor*> XD;
    Vec3 offsetCalc;
    //
    int RenderEnt = 5; //how many entites to show at once (from closest)
    bool offset = true; //instead of position show the relative position
    bool BPS = true; //show Block Per Second of the entity;
};