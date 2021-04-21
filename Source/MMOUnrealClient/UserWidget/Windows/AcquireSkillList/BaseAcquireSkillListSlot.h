// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Model/Ability/Ability.h"
#include "Database/Ability/AbilityTable.h"
#include "BaseAcquireSkillListSlot.generated.h"

/**
 * 
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseAcquireSkillListSlot : public UUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FAbility ability;
	
	UFUNCTION(BlueprintCallable, Category = "AbilitySlot", BlueprintCallable)
	UTexture2D* GetTexture(int32 item_id);

	UFUNCTION(BlueprintCallable, Category = "AbilitySlot", BlueprintCallable)
	FAbilityTable GetAbilityTableObject(int32 item_id);
};
