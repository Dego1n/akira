// MMOClient 2019


#include "StopMoving.h"
#include "Model/Actor/GameActor.h"
#include "Model/WorldInstance.h"
#include "Network/Game/Thread/GameSocketThread.h"

/**
 * @author Dego1n
 */
StopMoving::StopMoving(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] Stop Moving"));
	#endif

	this->Handle();
}

StopMoving::~StopMoving()
{
}

void StopMoving::Handle()
{
	
	int32 objectId = ReadD();
	
	FFunctionGraphTask::CreateAndDispatchWhenReady([this, objectId]() {
		
		AGameActor* actor = WorldInstance::GetInstance()->GetPlayerById(objectId);
		
		if(actor != nullptr)
		{ 
			actor->AbortMove();
		}
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
}