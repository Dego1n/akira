// MMOClient 2019


#include "SystemMessage.h"
#include "Network/Game/Thread/GameSocketThread.h"

SystemMessage::SystemMessage(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] SystemMessage"));
	#endif
	this->Handle();
}

SystemMessage::~SystemMessage()
{
}

void SystemMessage::Handle(){
	FString message = ReadS();

	FFunctionGraphTask::CreateAndDispatchWhenReady([this, message]() {

		GameSocketThread::Runnable->character->ReceivedSystemMessage(message);
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
}