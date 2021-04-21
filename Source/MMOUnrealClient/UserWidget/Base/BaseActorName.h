#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseActorName.generated.h"

/**
 * @author Dego1n
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseActorName : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString actorName;
};
