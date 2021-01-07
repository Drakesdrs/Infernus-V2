#pragma once
#include "../../Other/Module.h"
#include "TabGUI.h"
class Keystrokes : public Module
{
public:
    Keystrokes() : Module::Module("Keystrokes", "Visuals", "keystrokez") {};
    void onGmTick();
    void onRender();
private:
    bool wKey, sKey, aKey, dKey;
};

