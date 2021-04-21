// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseActorTitle.generated.h"

/**
 * 
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseActorTitle : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString actorTitle;
};
