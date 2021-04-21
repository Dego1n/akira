#include "AbstractSendablePacket.h"
#include "UnrealString.h"
#include "StringConv.h"

/**
 * @author Dego1n
 */

AbstractSendablePacket::AbstractSendablePacket()
{
}

AbstractSendablePacket::~AbstractSendablePacket()
{

}

void AbstractSendablePacket::PrepareForSend()
{
	int16 packet_size = packet.Num() + 2; //2 дополнительных байта - это размер пакета

	TArray<uint8> size_array;

	size_array.Add((uint8)(packet_size & 0xff));
	size_array.Add((uint8)((packet_size >> 8) & 0xff));

	size_array.Append(packet);

	packet = size_array;
}

uint8 * AbstractSendablePacket::GetData()
{
	return packet.GetData();
}
int16 AbstractSendablePacket::GetSize()
{
	return packet.Num();
}

/**
 * Записываем short в пакет (2 байта)
 */
void AbstractSendablePacket::WriteH(int16 value)
{
	packet.Add((uint8)(value & 0xff));
	packet.Add((uint8)((value >> 8) & 0xff));
}

/**
 * TODO: DOC
 */
void AbstractSendablePacket::WriteD(int32 value)
{
	packet.Add((uint8)(value & 0xff));
	packet.Add((uint8)((value >> 8) & 0xff));
	packet.Add((uint8)((value >> 16) & 0xff));
	packet.Add((uint8)((value >> 24) & 0xff));
}

/**
 * TODO DOC
 */
void AbstractSendablePacket::WriteS(FString value)
{
	FTCHARToUTF8 ToUtf8Converter(value.GetCharArray().GetData());
	auto char_arr = ToUtf8Converter.Get();
		
	for (int32 i = 0; i <= ToUtf8Converter.Length() - 1; i++)
	{
		packet.Add(char_arr[i]);
	}

	packet.Add(0x00);
	packet.Add(0x00);
	return;
}