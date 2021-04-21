#include "TargetSelected.h"
#include "Model/Actor/GameActor.h"
#include "Model/WorldInstance.h"
#include "Network/Game/Thread/GameSocketThread.h"

/**
 * @author Dego1n
 */
TargetSelected::TargetSelected(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] Target Selected"));
	#endif

	this->Handle();
}

TargetSelected::~TargetSelected()
{
}

void TargetSelected::Handle()
{
	
	int32 objectId = ReadD();
	
	FFunctionGraphTask::CreateAndDispatchWhenReady([this, objectId]() {
		
		AGameActor* actor = WorldInstance::GetInstance()->GetPlayerById(objectId);
		
		if(actor != nullptr)
		{ 
			GameSocketThread::Runnable->character->TargetSelected(actor);
		}
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
}