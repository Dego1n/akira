// MMOClient 2020

#pragma once

#include "CoreMinimal.h"
#include "Model/Quest/QuestRewardType.h"
#include "QuestProgression.generated.h"

/**
 * @author Dego1n
 */
USTRUCT(BlueprintType)
struct MMOUNREALCLIENT_API FQuestProgression
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 questId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> completedStates;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString currentState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<QuestRewardType, int32> rewards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int32, int32> itemsRewards;
};
