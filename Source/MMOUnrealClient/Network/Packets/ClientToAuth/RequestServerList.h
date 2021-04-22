#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 * ����� ������� ����������� ������ ��������, ������������ ����� �������� ����������� (����� AuthOk)
 */
class MMOUNREALCLIENT_API RequestServerList : public AbstractSendablePacket
{
private:
	int32 auth_session_key;
public:
	RequestServerList(int32 session_key);
	void Build() override;
};
