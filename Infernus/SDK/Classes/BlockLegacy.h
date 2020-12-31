#pragma once

class Material { //Just grabbed this class from Horion - Sorry
public:
	int type; //4 = Block | 5 = Water
	bool isFlammable;
	bool isNeverBuildable;
	bool isAlwaysDestroyable;
	bool isReplaceable;
	bool isLiquid;
};

class BlockLegacy {
public:
	char pad_0000[48]; //0x0000
	std::string name; //0x0030
	char pad_0038[160]; //0x0038
	class Material* Material; //0x00D8
	char pad_00E0[104]; //0x00E0
	int64_t blockId; //0x0148
	char pad_0150[48]; //0x0150
};

class Block {
public:
	char pad_0000[16]; //0x0000
	class BlockLegacy* BlockLegacy; //0x0010
};

class BlockSource {
public:
	Block* getBlock(const Vec3_i& blockPos) {
		using GetBlock = Block * (__fastcall*)(BlockSource*, const Vec3_i&);
		static GetBlock _GetBlock = reinterpret_cast<GetBlock>(Utils::FindSig("48 89 5C 24 ? 57 48 83 EC 20 48 8B F9 48 8B DA 8B 4A 04 0F BF 47 2A 3B C8 0F 8C ? ? ? ? 0F BF 47 28 3B C8"));
		return _GetBlock(this, blockPos);
	}
};