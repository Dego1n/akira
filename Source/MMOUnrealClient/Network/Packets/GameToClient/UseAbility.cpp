// MMOClient 2019


#include "UseAbility.h"
#include "Model/Actor/GameActor.h"
#include "Model/WorldInstance.h"
#include "Network/Game/Thread/GameSocketThread.h"

/**
 * @author Dego1n
 */
UseAbility::UseAbility(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] UseAbility"));
#endif

	this->Handle();
}

UseAbility::~UseAbility()
{
}

void UseAbility::Handle()
{
	int32 actorId = ReadD();
	int32 targetId = ReadD();
	int32 abilityId = ReadD();
	int32 castTimeTemp = ReadD();
	float castTime = castTimeTemp / 10.0;
	UE_LOG(LogTemp, Warning, TEXT("CAST TIME TEMP: %d"), castTimeTemp);
	UE_LOG(LogTemp, Warning, TEXT("RIGHT CAST TIME: %f"), castTime);
	FFunctionGraphTask::CreateAndDispatchWhenReady([this, actorId, targetId, abilityId, castTime]() {

		AGameActor* actor = WorldInstance::GetInstance()->GetPlayerById(actorId);
		AGameActor* target = WorldInstance::GetInstance()->GetPlayerById(targetId);

		if (actor != nullptr && target != nullptr)
		{
			GameSocketThread::Runnable->character->UseAbility(target, abilityId, castTime);
		}
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
}