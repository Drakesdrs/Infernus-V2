#pragma once
#include "../../Other/Module.h"

class MouseItem : public Hook {
public:
	void Install();
};

typedef void(__fastcall* AVMouseItem)(uint64_t, char, bool, uint64_t, uint64_t, int, int, BYTE);
AVMouseItem _MouseItem;

void MouseCallback(uint64_t a1, char action, bool isDown, uint64_t a4, uint64_t a5, int x, int y, BYTE a8) {
	bool cancelSend = false;
	for (auto Module : ClientManager::Modules) {
		if (Module->isEnabled) Module->onMouse(action, isDown, &cancelSend);
	}
	if (!cancelSend) _MouseItem(a1, action, isDown, a4, a5, x, y, a8);
}

void MouseItem::Install() {
	uintptr_t sigAddr = Utils::FindSig("48 8B C4 48 89 58 ?? 48 89 68 ?? 48 89 70 ?? 57 41 54 41 55 41 56 41 57 48 83 EC ?? 44 0F B7 BC 24 B0 00 00 00");
	if (sigAddr) {
		Utils::DebugLogOutput("Found address needed for the MouseItem Hook, Preparing Hook install now...");
		if (MH_CreateHook((void*)sigAddr, &MouseCallback, reinterpret_cast<LPVOID*>(&_MouseItem)) == MH_OK) {
			Utils::DebugLogOutput("Successfully created MouseItem Hook, Installing Hook now...");
			MH_EnableHook((void*)sigAddr);
		}
		else {
			Utils::DebugLogOutput("Failed to create MouseItem Hook!");
		}
	}
	else {
		Utils::DebugLogOutput("Failed to find address needed for MouseItem Hook!");
	}
}