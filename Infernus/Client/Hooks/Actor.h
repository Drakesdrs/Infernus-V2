#pragma once
#include "../../Other/Module.h"

class Actor_Hooks : public Hook {
public:
	void Install();
};

typedef bool(__fastcall* IsImmobile)(Actor*);
IsImmobile _IsImmobile;

bool IsImmobile_Callback(Actor* Entity) {
	LocalPlayer* myPlayer = Minecraft::ClientInstance()->LocalPlayer();
	if (Entity != nullptr && myPlayer != nullptr && myPlayer == Entity) {
		return false; //Default disable immobility state
	}
	return _IsImmobile(Entity);
}

void Actor_Hooks::Install() {
	uintptr_t ActorVTable_Addr = Utils::FindSig("48 8D ?? ?? ?? ?? ?? 48 89 01 44 88 79 ?? 44 88 79 ??");
	if (ActorVTable_Addr) {
		Utils::DebugLogOutput("\n"); //New Line
		Utils::DebugLogOutput("Successfully found address needed for Actor Hooks!");
		int offset = *reinterpret_cast<int*>(ActorVTable_Addr + 3);
		uintptr_t** VTable = reinterpret_cast<uintptr_t**>(ActorVTable_Addr + offset + 7);
		/* IsImmobile */
		{
			void* IsImmobile_Addr = VTable[86];
			if (MH_CreateHook(IsImmobile_Addr, &IsImmobile_Callback, reinterpret_cast<LPVOID*>(&_IsImmobile)) == MH_OK) {
				Utils::DebugLogOutput("Successfully created Actor::isImmobile Hook, Installing Hook now...");
				MH_EnableHook(IsImmobile_Addr);
			}
			else {
				Utils::DebugLogOutput("Failed to create Actor::isImmobile Hook!");
			}
		}
	}
	else {
		Utils::DebugLogOutput("Failed to find address needed for the Actor Hooks!");
	}
	Utils::DebugLogOutput("\n"); //New Line
}