#pragma once
#include "../../Other/Module.h"
class info : public Module {
public:
    info() : Module::Module("ENTER NAME HERE", "Visuals", "Show different kinds of info") { this->isEnabled = false; };
    void onGmTick();
    void onRender();
private:
    bool BPS = true;
    bool Position = true;
    bool Entities = true;
        bool FilterEntites = true; // part of the entites thingy
    //
    std::vector<std::string> stuffToRender;
    float bps = 0.0f;
    Vec3 pos = Vec3(0, 0, 0);
    Vec3 Oldpos = Vec3(0, 0, 0);

};