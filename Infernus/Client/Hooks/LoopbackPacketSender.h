#pragma once
#include "../../Other/Module.h"

class LoopbackPacketSender_Hook : public Hook {
public:
	void Install();
};

typedef void(__fastcall* SendToServer)(LoopbackPacketSender* _this, void* Packet);
SendToServer _SendToServer;

void PacketCallback(LoopbackPacketSender* _this, void* Packet) {
	uint64_t currVTable = *(UINT64*)Packet;
	PacketType type = PacketType::Unknown;
	if (currVTable == Packet::MovePlayerPacket()) {
		type = PacketType::Movement;
	}
	if (currVTable == Packet::PlayerAuthPacket()) {
		type = PacketType::AuthInput;
	}
	bool cancelSend = false;
	for (auto Module : ClientManager::Modules) {
		if (Module->isEnabled) Module->onPacket(type, Packet, &cancelSend);
	}
	if(!cancelSend) _SendToServer(_this, Packet);
}

void LoopbackPacketSender_Hook::Install() {
	uintptr_t sigAddr = Utils::FindSig("48 89 5C 24 ? 57 48 81 EC ? ? ? ? 0F B6 41 08 48 8B FA");
	if (sigAddr) {
		Utils::DebugLogOutput("Found address needed for the LoopbackPacketSender::SendToServer Hook, Preparing Hook install now...");
		if (MH_CreateHook((void*)sigAddr, &PacketCallback, reinterpret_cast<LPVOID*>(&_SendToServer)) == MH_OK) {
			Utils::DebugLogOutput("Successfully created LoopbackPacketSender::SendToServer, Installing Hook now...");
			MH_EnableHook((void*)sigAddr);
		}
		else {
			Utils::DebugLogOutput("Failed to create LoopbackPacketSender::SendToServer Hook!");
		}
	}
	else {
		Utils::DebugLogOutput("Failed to find address needed for the LoopbackPacketSender::SendToServer Hook!");
	}
}