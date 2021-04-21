// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidget/Windows/AcquireSkillList/BaseAcquireSkillListSlot.h"
#include "BaseAcquireSkillList.generated.h"

/**
 * 
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseAcquireSkillList : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Window")
	TArray<UBaseAcquireSkillListSlot*> abilitySlots;

	UFUNCTION(BlueprintImplementableEvent, Category = "Ability Window", BlueprintCallable)
	void AcquireSkillListUpdated();
};
