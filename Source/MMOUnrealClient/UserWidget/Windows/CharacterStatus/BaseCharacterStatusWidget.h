// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseCharacterStatusWidget.generated.h"

/**
 * 
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseCharacterStatusWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float currentHp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float maxHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float percentHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float currentMp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float maxMp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float percentMp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 currentExperience;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 startLevelExperience;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 experienceToNextLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float percentExperience;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float percentExperienceToShow;
};
