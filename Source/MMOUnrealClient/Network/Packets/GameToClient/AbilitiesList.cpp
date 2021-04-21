// MMOClient 2019


#include "AbilitiesList.h"
#include "Model/Ability/Ability.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Model/WorldInstance.h"
#include "Database/Ability/AbilityTable.h"

AbilitiesList::AbilitiesList(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] AbilitiesList"));
#endif
	this->Handle();
}


AbilitiesList::~AbilitiesList()
{
}

void AbilitiesList::Handle()
{
	int32 abilitiesCount = ReadD();
	TArray<FAbility> abilities;
	for (int i = 0; i < abilitiesCount; i++)
	{
		FAbility ability;

		ability.ability_id = ReadD();
		ability.ability_level = ReadD();

		abilities.Add(ability);
	}
	FFunctionGraphTask::CreateAndDispatchWhenReady([this, abilities]() {
		GameSocketThread::Runnable->character->UpdateAbilities(abilities);
		
		

		}
	, TStatId(), nullptr, ENamedThreads::GameThread);
}
