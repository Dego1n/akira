// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API RequestSell : public AbstractSendablePacket
{
private:
	TMap<int32, int32> _items;
	int32 _buyListId;
public:
	RequestSell(int32 buyListId, TMap<int32, int32> items);
	void Build() override;
};
