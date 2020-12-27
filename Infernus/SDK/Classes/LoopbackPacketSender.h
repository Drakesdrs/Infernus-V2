#pragma once

class LoopbackPacketSender {
public:
	virtual void Function0();
	virtual void sendToServer(void* Packet);
};