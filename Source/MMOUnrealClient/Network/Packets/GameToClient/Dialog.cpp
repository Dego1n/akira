#include "Dialog.h"
#include "Model/Actor/PlayableCharacter.h"
#include "Network/Game/Thread/GameSocketThread.h"

/**
 * @author Dego1n
 */
Dialog::Dialog(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] Dialog"));
	#endif
	this->Handle();
}

Dialog::~Dialog()
{
}

void Dialog::Handle()
{
	FString dialog = ReadS();

	FFunctionGraphTask::CreateAndDispatchWhenReady([this, dialog]() {
		APlayableCharacter* pc = GameSocketThread::Runnable->character;
	
		if(pc != nullptr)
		{
			pc->ShowDialog(dialog);
		}
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);

}