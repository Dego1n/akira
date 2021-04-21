// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseActionBarSlot.generated.h"

/**
 * 
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseActionBarSlot : public UUserWidget
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "AbilitySlot", BlueprintCallable)
	void UseSkill(int32 skillId);
};
