#include "MoveActorToLocation.h"
#include "Network/Auth/Thread/AuthSocketThread.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Model/WorldInstance.h"

/**
 * @author Dego1n
 */

MoveActorToLocation::MoveActorToLocation(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] MoveActorToLocation"));
#endif
	this->Handle();
}

MoveActorToLocation::~MoveActorToLocation()
{
}

void MoveActorToLocation::Handle()
{
	int32 actorId = ReadD();
	int32 targetX = ReadD();
	int32 targetY = ReadD();
	int32 targetZ = ReadD();

	FVector targetVector;
	targetVector.X = targetX;
	targetVector.Y = targetY;
	targetVector.Z = targetZ;

	FFunctionGraphTask::CreateAndDispatchWhenReady([this, actorId, targetVector]() {
		AGameActor* actor = WorldInstance::GetInstance()->GetPlayerById(actorId);
		if(actor != nullptr)
		{
			actor->MoveActorToLocation(targetVector);
		}
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
	
}