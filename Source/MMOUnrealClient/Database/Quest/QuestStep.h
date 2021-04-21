// MMOClient 2020

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "QuestStep.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct MMOUNREALCLIENT_API FQuestStep : public FTableRowBase
{
	GENERATED_BODY()
public:
	FQuestStep() {

	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 questId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText questStep;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText questStepShortText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText questStepFullText;
};
