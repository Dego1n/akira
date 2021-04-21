// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidget/Windows/Loot/BaseLootWindowSlot.h"
#include "Model/Actor/GameActor.h"
#include "BaseLootWindow.generated.h"

/**
 * 
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseLootWindow : public UUserWidget
{
	GENERATED_BODY()
public:
	AGameActor* owner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LootWindowSlots")
	TArray<UBaseLootWindowSlot*> lootWindowSlots;

	UFUNCTION(BlueprintImplementableEvent, Category = "LootWindowSlots", BlueprintCallable)
	void SlotsUpdated();
};
