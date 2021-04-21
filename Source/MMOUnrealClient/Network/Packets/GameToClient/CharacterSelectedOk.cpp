#include "CharacterSelectedOk.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Kismet/GameplayStatics.h"

/**
 * @author Dego1n
 */
CharacterSelectedOk::CharacterSelectedOk(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
	#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] CharacterSelectedOk"));
	#endif
	this->Handle();
}

CharacterSelectedOk::~CharacterSelectedOk()
{

}

void CharacterSelectedOk::Handle()
{
	int16 chracterRace = ReadH(); // currently unused
	FFunctionGraphTask::CreateAndDispatchWhenReady([this]() {
		
		//UWorldGameInstance* wgi = Cast<UWorldGameInstance>(GameSocketThread::Runnable->world->GetGameInstance());
		//UUserWidget* loadingScreenWidget =  CreateWidget<UUserWidget>(GameSocketThread::Runnable->world, wgi->LoadingScreenWidget);
		//loadingScreenWidget->AddToViewport();
		GameSocketThread::Runnable->CharacterSelectedOk();
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);

}