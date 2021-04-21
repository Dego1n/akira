#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TargetWidget.generated.h"

/**
 * @author Dego1n
 */
UCLASS()
class MMOUNREALCLIENT_API UTargetWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString actorName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool showHp = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float maxHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float currentHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float hpPercentage;
};
