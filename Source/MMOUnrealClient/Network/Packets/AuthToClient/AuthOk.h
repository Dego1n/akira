#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 * ����� ������� ��������� ������ ����������� ����� �������� ����������� � ������� ���������������� ������
 */
class MMOUNREALCLIENT_API AuthOk : public AbstractRecivablePacket
{
public:
	AuthOk(TArray<int8> packet);
	~AuthOk();
private:
	void Handle();
};
