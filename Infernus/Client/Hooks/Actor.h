#pragma once
#include "../../Other/Module.h"

class Actor_Hooks : public Hook {
public:
	void Install();
};

typedef bool(__thiscall* IsImmobile)(Actor*);
IsImmobile _IsImmobile;

bool IsImmobile_Callback(Actor* Entity) {
	LocalPlayer* myPlayer = Minecraft::ClientInstance()->LocalPlayer();
	if (Entity != nullptr && myPlayer != nullptr && myPlayer == Entity) {
		return false; //Default disable immobility state
	}
	return _IsImmobile(Entity);
}

typedef void(__thiscall* lerpMotion)(Actor*, Vec3*);
lerpMotion _lerpMotion;

void lerpMotion_Callback(Actor* Entity, Vec3* Velocity) {
	if (Entity != nullptr) {
		LocalPlayer* Player = Minecraft::ClientInstance()->LocalPlayer();
		if (Player != nullptr && Entity == Player) {
			for (auto Module : ClientManager::Modules) {
				if (Module->isEnabled) Module->onLerp(Entity, Velocity);
			}
		}
	}
	_lerpMotion(Entity, Velocity);
}

void Actor_Hooks::Install() {
	uintptr_t ActorVTable_Addr = Utils::FindSig("48 8D 05 ?? ?? ?? ?? 48 89 07 48 8D 8F ?? ?? ?? ?? 48 8B 87");
	if (ActorVTable_Addr) {
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
		/* Lerp Motion */
		{
			void* lerpMotion_Addr = VTable[38];
			Utils::DebugLogOutput(Utils::ptrToStr((uint64_t)lerpMotion_Addr));
			if (MH_CreateHook(lerpMotion_Addr, &lerpMotion_Callback, reinterpret_cast<LPVOID*>(&_lerpMotion)) == MH_OK) {
				Utils::DebugLogOutput("Successfully created Actor::lerpMotion Hook, Installing Hook now...");
				MH_EnableHook(lerpMotion_Addr);
			}
			else {
				Utils::DebugLogOutput("Failed to create Actor::lerpMotion Hook!");
			}
		}
	}
	else {
		Utils::DebugLogOutput("Failed to find address needed for the Actor Hooks!");
	}
}