// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AbilityAnimationTable.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct MMOUNREALCLIENT_API FAbilityAnimationTable : public FTableRowBase
{
	GENERATED_BODY()
public:
	FAbilityAnimationTable() {

	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 actorTemplate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString animation;
};
