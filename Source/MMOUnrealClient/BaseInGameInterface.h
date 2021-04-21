// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseInGameInterface.generated.h"

/**
 * 
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseInGameInterface : public UUserWidget
{
	GENERATED_BODY()

public:
	
	//UFUNCTION(BlueprintCallable, Category = "InGameInterface Functions")
	//void Inventory();
	UFUNCTION(BlueprintCallable, Category = "InGameInterface Functions")
	void CharacterInfo();
};
