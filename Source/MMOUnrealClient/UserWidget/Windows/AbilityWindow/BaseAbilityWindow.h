// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidget/Windows/AbilityWindow/BaseAbilitySlot.h"
#include "BaseAbilityWindow.generated.h"

/**
 * 
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseAbilityWindow : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Window")
	TArray<UBaseAbilitySlot*> abilitySlots;

	UFUNCTION(BlueprintImplementableEvent, Category = "Ability Window", BlueprintCallable)
	void AbilityListUpdated();

	UFUNCTION(BlueprintCallable, Category = "Ability Window", BlueprintCallable)
	void Fill();

	
};
