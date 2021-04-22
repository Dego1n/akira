#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 * ����� ������� �������� ����� �������� RequestConnect. �������� session_key ��� ����������� �������
 */
class MMOUNREALCLIENT_API ConnectionAccepted : public AbstractRecivablePacket
{
public:
	ConnectionAccepted(TArray <int8> packet);
	~ConnectionAccepted();
private:
	void Handle();
};
