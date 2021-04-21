// MMOClient 2020

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API QuestList : public AbstractRecivablePacket
{
public:
	QuestList(TArray <int8> packet);
	~QuestList();

private:
	void Handle();
};
