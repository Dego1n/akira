// MMOClient 2020

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API QuestTalk : public AbstractSendablePacket
{
private:
	int32 objectId;
	int32 questId;
	FString ref;
public:
	QuestTalk(int32 objectId, int32 questId, FString ref);
	void Build() override;
};
