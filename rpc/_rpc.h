#pragma once
#include "utility.h"

void HandleRpc(uint8_t callId, MessageReader* reader);

class RPCInterface {
public:
	virtual ~RPCInterface() {}
	virtual void Process() = 0;
};

class RpcCloseDoorsOfType : public RPCInterface {
	SystemTypes__Enum selectedSystem;
	bool pinDoor;
public:
	RpcCloseDoorsOfType(SystemTypes__Enum selectedSystem, bool pinDoor);
	virtual void Process() override;
};

class RpcSnapTo : public RPCInterface {
	Vector2 targetVector;
public:
	RpcSnapTo(Vector2 targetVector);
	virtual void Process() override;
};

class RpcRepairSystem : public RPCInterface {
	SystemTypes__Enum selectedSystem;
	int32_t amount;
public:
	RpcRepairSystem(SystemTypes__Enum selectedSystem, int32_t amount);
	virtual void Process() override;
};

class RpcCompleteTask : public RPCInterface {
	uint32_t taskId;
public:
	RpcCompleteTask(uint32_t taskId);
	virtual void Process() override;
};

class RpcPlayAnimation : public RPCInterface {
	uint8_t animId;
public:
	RpcPlayAnimation(uint8_t taskId);
	virtual void Process() override;
};

class RpcSetScanner : public RPCInterface {
	bool playAnimation;
public:
	RpcSetScanner(bool playAnimation);
	virtual void Process() override;
};

class RpcReportPlayer : public RPCInterface {
	PlayerSelection reportedPlayer;
public:
	RpcReportPlayer(PlayerSelection target);
	virtual void Process() override;
};

class RpcMurderPlayer : public RPCInterface {
	PlayerSelection target;
public:
	RpcMurderPlayer(PlayerSelection target);
	virtual void Process() override;
};

class RpcSetColor : public RPCInterface {
	uint8_t bodyColor;
public:
	RpcSetColor(uint8_t colorId);
	virtual void Process() override;
};

class RpcSetName : public RPCInterface {
	std::string name;
public:
	RpcSetName(std::string name);
	virtual void Process() override;
};
