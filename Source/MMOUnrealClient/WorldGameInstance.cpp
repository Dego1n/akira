#include "WorldGameInstance.h"
#include "EngineGlobals.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Network/Packets/ClientToGame/EnterWorld.h"
#include "Config/VersionInfo.h"
#include "MoviePlayer.h"

/**
 * @author Deog1n
 */

UWorldGameInstance::UWorldGameInstance()
{

}



void UWorldGameInstance::WorldLevelLoaded(UObject* WorldContextObject)
{
	if(GameSocketThread::Runnable != nullptr)
	{
		GameSocketThread::Runnable->world = GetWorld();
		GameSocketThread::Runnable->SendPacket(new EnterWorld());
	}
}

void UWorldGameInstance::EndPlay()
{
		GameSocketThread::Runnable->Stop();
		GameSocketThread::Runnable = nullptr;
		FGenericPlatformMisc::RequestExit(true);
}

void UWorldGameInstance::UpdateBuildNumbers()
{
	UVersionInfo* versionInfo = GetMutableDefault<UVersionInfo>();

	this->buildRevision = FString::FromInt(versionInfo->VersionRevision);
	this->buildBranch = versionInfo->VersionBranch;
	this->buildVersion = versionInfo->Version;
	this->buildDate = versionInfo->VersionTime;
}

void UWorldGameInstance::Init()
{
	Super::Init();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UWorldGameInstance::BeginLoadingScreen);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UWorldGameInstance::EndLoadingScreen);
}

void UWorldGameInstance::BeginLoadingScreen(const FString& InMapName)
{
		FLoadingScreenAttributes* LoadingScreen = new FLoadingScreenAttributes();
		LoadingScreen->WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();
		LoadingScreen->bAutoCompleteWhenLoadingCompletes = true;
		LoadingScreen->MinimumLoadingScreenDisplayTime = 0;
		LoadingScreen->bMoviesAreSkippable = false;
		LoadingScreen->bWaitForManualStop = false;
		LoadingScreen->bAllowEngineTick = true;
		GetMoviePlayer()->SetupLoadingScreen(*LoadingScreen);
}

void UWorldGameInstance::EndLoadingScreen(UWorld* InLoadedWorld)
{
	
}