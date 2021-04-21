// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseActorInfoWidget.generated.h"

/**
 * 
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseActorInfoWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString className;

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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 skillPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 physAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 physDefence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 physAccuracy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 physEvasion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 physCritical;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 attackSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 moveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 magicAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 magicDefence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 magicAccuracy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 magicEvasion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 magicCritical;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 castingSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 str;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 con;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 dex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 _int;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 wis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 men;

	UFUNCTION(BlueprintCallable, Category = "InGameInterface Functions")
	void CloseCharacterInfo();

};
