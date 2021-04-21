// MMOClient 2019


#include "Attack.h"
#include "Model/Actor/GameActor.h"
#include "Model/WorldInstance.h"

Attack::Attack(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] Attack"));
	#endif
	this->Handle();
}

Attack::~Attack()
{
}

void Attack::Handle()
{
	int32 actorId = ReadD(); 
	int32 targetActorId = ReadD(); 


	FFunctionGraphTask::CreateAndDispatchWhenReady([this, actorId, targetActorId]() {

		AGameActor* actor = WorldInstance::GetInstance()->GetPlayerById(actorId);
		AGameActor* targetActor = WorldInstance::GetInstance()->GetPlayerById(targetActorId);
		actor->MontageAttack(targetActor);

	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
	
}