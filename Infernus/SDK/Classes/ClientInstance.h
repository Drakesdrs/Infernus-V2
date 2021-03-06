#pragma once
#include "TextHolder.h"
#include "MinecraftUIRenderContext.h"
#include "Actor.h"
#include "LocalPlayer.h"
#include "GameMode.h"
#include "LoopbackPacketSender.h"
#include "Packet.h"

class ClientInstance {
public:
	class LocalPlayer* LocalPlayer() {
		if (this != nullptr) {
			return *reinterpret_cast<class LocalPlayer**>(reinterpret_cast<__int64>(this) + 0x138);
		}
		else {
			return nullptr;
		}
	}
	class MinecraftGame* MinecraftGame() {
		if (this != nullptr) {
			return *reinterpret_cast<class MinecraftGame**>(reinterpret_cast<__int64>(this) + 0x98);
		}
		else {
			return nullptr;
		}
	}

	class LoopbackPacketSender* LoopbackPacketSender() {
		if (this != nullptr) {
			return *reinterpret_cast<class LoopbackPacketSender**>(reinterpret_cast<__int64>(this) + 0xD0);
		}
		else {
			return nullptr;
		}
	}

	class GuiData* GuiData() {
		if (this != nullptr) {
			return *reinterpret_cast<class GuiData**>(reinterpret_cast<__int64>(this) + 0x4D0);
		}
		else {
			return nullptr;
		}
	}

	bool isValidTarget(class Actor* Entity) {
		if (Entity == nullptr) {
			return false;
		}
		if (Entity->isInvisible() || !Entity->isAlive() || Entity->isImmobile()) {
			return false;
		}
		if (Entity->getEntityTypeId() > 60 && Entity->getEntityTypeId() < 104 && Entity->getEntityTypeId() != 63) {
			return false;
		}
		if (Entity->getFormattedNameTag().length() <= 1) {
			return false;
		}
		if (!(this->LocalPlayer()->canAttack(Entity, false))) {
			return false;
		}
		return true;
	};
	void clientMessage(std::string output) {
		class LocalPlayer* Player = this->LocalPlayer();
		if (Player != nullptr) {
			TextHolder msg(output);
			Player->displayTextObjectMessage(&msg);
		}
	}
};

class BitmapFont {
public:
	//
};

class MinecraftGame {
public:
	class BitmapFont* MCFont() {
		return *reinterpret_cast<class BitmapFont**>(reinterpret_cast<__int64>(this) + 0xD8);
	}
	bool canUseKeys() {
		return *(bool*)(reinterpret_cast<uintptr_t>(this) + 0x260);
	}
};

class GuiData
{
public:
	char pad_0000[40]; //0x0000
	Vec2 ScaledResolution; //0x0028
public:

	float GuiScale() {
		return *reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(this) + 0x34);
	};

	uint16_t mouseX() {
		return *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(this) + 0x52);
	};

	uint16_t mouseY() {
		return *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(this) + 0x54);
	};
};