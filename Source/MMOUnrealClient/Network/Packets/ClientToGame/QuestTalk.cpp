// MMOClient 2020


#include "QuestTalk.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

QuestTalk::QuestTalk(int32 objectId, int32 questId, FString ref)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] QuestTalk"));
#endif

	this->objectId = objectId;
	this->questId = questId;
	this->ref = ref;

	Build();
	PrepareForSend();
}

void QuestTalk::Build()
{
	WriteH(ClientToGamePackets::Packet::QUEST_TALK);
	WriteD(objectId);
	WriteD(questId);
	WriteS(ref);
}
