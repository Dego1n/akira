#pragma once

#include "CoreMinimal.h"

#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 * ����� ������� ���������� ����� � ������ ��� �����������, ���������� ����� ��������� ����� ������ � ConnectionAccepted
 */
class MMOUNREALCLIENT_API RequestAuth : public AbstractSendablePacket
{
private:
	int32 auth_session_key;
	FString username;
	FString password;
public:
	RequestAuth(int32 session_key, FString username, FString password);
	void Build() override;
};
