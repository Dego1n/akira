#pragma once

#include "CoreMinimal.h"

#include "EngineGlobals.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "Network/Packets/Enum/ClientToAuthPackets.h"

/**
 * @author Dego1n
 * Абстрактный класс для отправляемых на сервер пакетов
 */
class MMOUNREALCLIENT_API AbstractSendablePacket
{
public:
	AbstractSendablePacket();
	virtual ~AbstractSendablePacket() = 0; //?
	uint8* GetData();
	int16 GetSize();

protected:
	TArray<uint8> packet;
	void PrepareForSend();
	virtual void Build() = 0;
	void WriteH(int16 value);
	void WriteD(int32 value);
	void WriteS(FString value);
};
