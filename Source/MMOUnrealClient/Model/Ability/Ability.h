// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Ability.generated.h"

USTRUCT(BlueprintType)
struct MMOUNREALCLIENT_API FAbility
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ability_id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ability_level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ability_name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ability_description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ability_mana_cost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 required_sp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* abilityTexture;
};
