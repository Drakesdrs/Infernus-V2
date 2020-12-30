#pragma once
#include "../../Other/Module.h"
class InventoryMove :
    public Module
{
public:
    InventoryMove() : Module::Module("InventoryMove", "Player", "Move around while in inventory") {};
    void onTick();
};

