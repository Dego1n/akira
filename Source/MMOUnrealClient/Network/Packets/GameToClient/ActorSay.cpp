// MMOClient 2019


#include "ActorSay.h"
#include "Network/Game/Thread/GameSocketThread.h"

ActorSay::ActorSay(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] ActorSay"));
	#endif
	this->Handle();
}

ActorSay::~ActorSay()
{

}

void ActorSay::Handle()
{
	int32 actorId = ReadD();  //Пока не используется
	FString actorName = ReadS(); 
	FString actorMessage = ReadS();

	FFunctionGraphTask::CreateAndDispatchWhenReady([this, actorName, actorMessage]() {

		GameSocketThread::Runnable->character->ReceivedChatMessage(actorName,actorMessage);
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
}
