#include "AbstractRecivablePacket.h"
#include "UnrealString.h"
#include "StringConv.h"

/**
 * @author Dego1n
 */

AbstractRecivablePacket::AbstractRecivablePacket(TArray<int8> packet)
{
	received_packet = packet;
	pointer = 2; //���������� 2 ����� - ID ������
}

AbstractRecivablePacket::~AbstractRecivablePacket()
{

}

int16 AbstractRecivablePacket::ReadH()
{
	int16 result = received_packet[pointer++] & 0xff;
	result |= (received_packet[pointer++] << 8) & 0xff00;
	return result;
}

int32 AbstractRecivablePacket::ReadD()
{
	int32 result = received_packet[pointer++] & 0xff;
	result |= (received_packet[pointer++] << 8) & 0xff00;
	result |= (received_packet[pointer++] << 0x10) & 0xff0000;
	result |= (received_packet[pointer++] << 0x18) & 0xff000000;

	return result;
}

FString AbstractRecivablePacket::ReadS()
{
	TArray<uint8> byteArray;
	int32 size = 0;
	for(int32 i = pointer; i < pointer + (received_packet.Num() - pointer); i++)
	{
		if(received_packet[i] == 0x00 && received_packet[i + 1] == 0x00)
		{
			break;
		}
		byteArray.Add(received_packet[i]);
		size++;
	}

	//��������� ��������� �����, ��� ����� � ����� ������ ���� �����. 
	//���� �� ����� ������� ���������� ������� ����� ���� ������� ������� ��� ������ �����������
	//�� ������������ �� ���...
	byteArray.Add(0); 
	
	pointer += size + 2;

	return FString(UTF8_TO_TCHAR(byteArray.GetData()));
}