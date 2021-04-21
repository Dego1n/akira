// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChatBoxWidget.generated.h"

/**
 * @author Dego1n
 */
UCLASS()
class MMOUNREALCLIENT_API UChatBoxWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	TArray<FString> messages;

	UFUNCTION(BlueprintImplementableEvent, Category = "ChatBox Events", BlueprintCallable)
	void UpdateChatboxMessages(const FString& messages);
	
	UFUNCTION(BlueprintCallable, Category = "ChatBox Functions", BlueprintCallable)
	void SendMessage(const FString message);


};
