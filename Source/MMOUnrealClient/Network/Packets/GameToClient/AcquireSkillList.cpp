// MMOClient 2019


#include "AcquireSkillList.h"
#include "Database/Ability/AbilityTable.h"
#include "Model/Ability/Ability.h"
#include "Network/Game/Thread/GameSocketThread.h"

AcquireSkillList::AcquireSkillList(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] AcquireSkillList"));
#endif
	this->Handle();
}


AcquireSkillList::~AcquireSkillList()
{
}

void AcquireSkillList::Handle()
{
	int32 size = ReadD();
	TArray<FAbility> abilities;
	for (int i = 0; i < size; i++)
	{
		FAbility ability;

		ability.ability_id = ReadD();
		ability.ability_level = ReadD();
		ability.required_sp = ReadD();


		abilities.Add(ability);
	}
	FFunctionGraphTask::CreateAndDispatchWhenReady([this, abilities]() {
		GameSocketThread::Runnable->character->AcquireSkillList(abilities);


		}
	, TStatId(), nullptr, ENamedThreads::GameThread);
}
