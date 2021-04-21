// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseAcquireSkillDescription.generated.h"

/**
 * 
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseAcquireSkillDescription : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "AcquireSkil", BlueprintCallable)
	void AcquireAbility(int32 ability_id);
};
