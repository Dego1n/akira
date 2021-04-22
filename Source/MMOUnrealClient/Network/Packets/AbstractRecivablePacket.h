#pragma once

#include "CoreMinimal.h"

#include "EngineGlobals.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

/**
 * @author Dego1n
 * ����������� ����� ��� ������� �� �������
 */
class MMOUNREALCLIENT_API AbstractRecivablePacket
{
public:
	AbstractRecivablePacket(TArray<int8> packet);
	virtual ~AbstractRecivablePacket();

private:
	TArray<int8> received_packet;
	int32 pointer;
protected:
	int16 ReadH();
	int32 ReadD();
	FString ReadS();
};
