#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NPCDialog.generated.h"

/**
 * @author Dego1n
 */
UCLASS()
class MMOUNREALCLIENT_API UNPCDialog : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "NPCDialog Events", BlueprintCallable)
	void UpdateDialog(const FString& dialog);

	UFUNCTION(BlueprintCallable, Category = "NPCDialog Functions")
	void CloseDialog();
};
