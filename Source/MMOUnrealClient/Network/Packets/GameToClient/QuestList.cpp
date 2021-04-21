// MMOClient 2020


#include "QuestList.h"
#include "Model/Quest/QuestProgression.h"
#include "Model/Quest/QuestRewardType.h"
#include "Network/Game/Thread/GameSocketThread.h"

/**
 * @author Dego1n
 */
QuestList::QuestList(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] QuestList"));
#endif

	this->Handle();
}

QuestList::~QuestList()
{

}

void QuestList::Handle()
{
	TArray<FQuestProgression> quests;

	int32 questSize = ReadD();
	for (int i = 0; i < questSize; i++)
	{
		FQuestProgression qp;
		qp.questId = ReadD();
		int questCompletedStatesSize = ReadD();
		TArray<FString> completedStates;
		for (int x = 0; x < questCompletedStatesSize; x++)
		{
			completedStates.Add(ReadS());
		}
		qp.completedStates = completedStates;
		qp.currentState = ReadS();
		int32 rewardsSize = ReadD();
		TMap<QuestRewardType, int32> questRewards;
		for (int x = 0; x < rewardsSize; x++)
		{
			int32 key = ReadD();
			int32 value = ReadD();
			questRewards.Add(static_cast<QuestRewardType>(key), value);
		}
		qp.rewards = questRewards;
		int32 rewardsItemsSize = ReadD();
		TMap<int32, int32> questItemsRewards;
		for (int x = 0; x < rewardsItemsSize; x++)
		{
			int32 key = ReadD();
			int32 value = ReadD();
			questItemsRewards.Add(key, value);
		}
		qp.itemsRewards = questItemsRewards;
		quests.Add(qp);
	}
	FFunctionGraphTask::CreateAndDispatchWhenReady([this, quests]() {
		GameSocketThread::Runnable->character->updateQuestList(quests);
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
}

