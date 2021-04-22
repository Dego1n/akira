#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 * ����� ������� ������������ ����� ����� ����������� � ������� �����������. 
 * ���� ��� �� - �������� � ����� ����� ConnectionAccepted � session_key
 */
class MMOUNREALCLIENT_API RequestConnect : public AbstractSendablePacket
{
public:
	RequestConnect();
	void Build() override;
};
