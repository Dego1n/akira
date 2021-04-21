#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Network/Auth/Model/ServerStruct.h"

#include "LobbyUserWidget.generated.h"


/**
 * @author Dego1n
 */
UCLASS()
class MMOUNREALCLIENT_API ULobbyUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Network Auth")
	void ConnectToAuthServer(FString username, FString password);

	UFUNCTION(BlueprintCallable, Category = "Network Auth")
	void DoRequestServerLogin(int32 ServerID);

	UFUNCTION(BlueprintCallable, Category = "Network Auth")
	void CloseConnectionWithAuthServer();

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "NetworkAuth", BlueprintCallable)
	void OnReceivedServerList(const TArray<FServerStruct>& gameServers);

	UFUNCTION(BlueprintImplementableEvent, Category = "NetworkAuth", BlueprintCallable)
	void OnReceivedAuthFailed(const FString& message);

	UFUNCTION(BlueprintImplementableEvent, Category = "NetworkAuth", BlueprintCallable)
	void OnReceivedConnectionFailed(const FString& message);

	void StartConnectionToGameServer(int32 game_session_key, FServerStruct server);
};
