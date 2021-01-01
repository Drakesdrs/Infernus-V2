#pragma once

class RakNetInstance {
public:
	char pad_0000[864]; //0x0000
	std::string serverIp; //0x0360
	char pad_0368[24]; //0x0368
	class TextHolder dynamicIp; //0x0380
	char pad_0388[184]; //0x0388
};

class NetworkHandler {
public:
	char pad_0000[48]; //0x0000
	class RakNetInstance* Raknet; //0x0030
};

class LoopbackPacketSender {
public:
	char pad_0008[8]; //0x0008
	class NetworkHandler* NetworkHandler; //0x0010

	virtual void Function0();
	virtual void sendToServer(void* Packet);
};