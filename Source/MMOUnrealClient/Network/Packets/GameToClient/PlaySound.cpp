// MMOClient 2020


#include "PlaySound.h"
#include "Network/Game/Thread/GameSocketThread.h"

/**
 * @author Dego1n
 */
PlaySound::PlaySound(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] PlaySound"));
#endif

	this->Handle();
}

PlaySound::~PlaySound()
{

}

void PlaySound::Handle()
{
	int32 soundId = ReadD();

	FFunctionGraphTask::CreateAndDispatchWhenReady([this, soundId]() {
		GameSocketThread::Runnable->character->PlaySound(soundId);
		}
	, TStatId(), nullptr, ENamedThreads::GameThread);
}

