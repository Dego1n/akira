#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"


/**
 * @author Dego1n 
 * ����� ������� ��������� ������ ���� ����������� �� ������� ������ �������.
 * � ������ �� �������� game_session_key, ��������� ���������� � Auth �������� � ������������ � ���������� ������ �� Game ������
 */
class MMOUNREALCLIENT_API GameServerAuthOk : public AbstractRecivablePacket
{
public:
	GameServerAuthOk(TArray<int8> packet);
	~GameServerAuthOk();
private:
	void Handle();
};
