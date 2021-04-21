// MMOClient 2019


#include "MoveToPawn.h"
#include "Model/WorldInstance.h"

/**
 * @author Dego1n
 */
MoveToPawn::MoveToPawn(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] MoveToPawn"));
	#endif
	this->Handle();
}

MoveToPawn::~MoveToPawn()
{
}
void MoveToPawn::Handle()
{
	int32 actorId = ReadD();
	int32 targetActorId = ReadD();
	int32 radius = ReadD();

	FFunctionGraphTask::CreateAndDispatchWhenReady([this, actorId, targetActorId,radius]() {

		AGameActor* actor = WorldInstance::GetInstance()->GetPlayerById(actorId);
		AGameActor* targetActor = WorldInstance::GetInstance()->GetPlayerById(targetActorId);

		if(actor != nullptr)
		{
			actor->MoveToPawn(targetActor,radius);
		}
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
	
}
