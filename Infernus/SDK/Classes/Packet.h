#pragma once

enum class PacketType {
	Unknown,
	Movement,
	AuthInput
};

class Packet {
private:
	static uint64_t MovePlayerPacket_Addr;
	static uint64_t PlayerAuthPacket_Addr;
public:
	static uint64_t MovePlayerPacket() {
		if (MovePlayerPacket_Addr) {
			return MovePlayerPacket_Addr;
		}
		else {
			uintptr_t sigAddr = Utils::FindSig("48 8D 05 ? ? ? ? 48 89 01 48 8B 82 ? ? ? ? 48 89 41 ? 48 8B 02 48 8B CA");
			int offset = *reinterpret_cast<int*>(sigAddr + 3);
			MovePlayerPacket_Addr = (uint64_t)reinterpret_cast<uintptr_t**>(sigAddr + offset + 7);
			return MovePlayerPacket_Addr;
		}
	}
	static uint64_t PlayerAuthPacket() {
		if (PlayerAuthPacket_Addr) {
			return PlayerAuthPacket_Addr;
		}
		else {
			uintptr_t sigAddr = Utils::FindSig("48 8D 05 ? ? ? ? 48 89 45 97 48 89 75 BF 0F");
			int offset = *reinterpret_cast<int*>(sigAddr + 3);
			PlayerAuthPacket_Addr = (uint64_t)reinterpret_cast<uintptr_t**>(sigAddr + offset + 7);
			return PlayerAuthPacket_Addr;
		}
	}
};

class MovePlayerPacket {
public:
	uint64_t VTable; //0x0000
	char pad_0008[32]; //0x0008
	uint64_t runtimeId; //0x0028
	Vec3 position; //0x0030
	Vec2 bodyRot; //0x003C
	char pad_0044[5]; //0x0044
	bool onGround; //0x0049
public:
	MovePlayerPacket(Actor* Entity, Vec3 position, Vec2 bodyRot, bool onGround = true) {
		this->VTable = Packet::MovePlayerPacket();
		this->runtimeId = Entity->entityId;
		this->position = position;
		this->bodyRot = bodyRot;
		this->onGround = onGround;
	}
};

class PlayerAuthInputPacket {
public:
	uint64_t VTable; //0x0000
	char pad_0008[24]; //0x0008
	uint64_t runtimeId; //0x0020
	Vec2 bodyRot; //0x0028
	Vec3 position; //0x0030
public:
	PlayerAuthInputPacket(Actor* Entity, Vec3 position, Vec2 bodyRot) {
		this->VTable = Packet::PlayerAuthPacket();
		this->runtimeId = Entity->entityId;
		this->position = position;
		this->bodyRot = bodyRot;
	}
};