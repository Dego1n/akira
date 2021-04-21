// MMOClient 2020

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Model/Quest/QuestProgression.h"
#include "Database/Quest/QuestTable.h"
#include "Database/Quest/QuestStep.h"
#include "Database/Item/ItemTable.h"
#include "BaseQuestListWindow.generated.h"

/**
 * 
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseQuestListWindow : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Window")
	TArray<FQuestProgression> quests;

	UFUNCTION(BlueprintImplementableEvent, Category = "Quest Window Events", BlueprintCallable)
	void QuestListUpdated();

	UFUNCTION(BlueprintCallable, Category = "Quest Window", BlueprintCallable)
	FQuestTable GetQuestObjectByQuestId(int32 questId);

	UFUNCTION(BlueprintCallable, Category = "Quest Window", BlueprintCallable)
	FQuestStep GetQuestStepObjectByQuestIdAndStep(int32 questId, FString step);

	UFUNCTION(BlueprintCallable, Category = "Quest Window", BlueprintCallable)
	FItemTable GetItemTableObject(int32 item_id);

	UFUNCTION(BlueprintCallable, Category = "Quest Window", BlueprintCallable)
	UTexture2D* GetItemTexture(int32 item_id);

	UFUNCTION(BlueprintCallable, Category = "Quest Window", BlueprintCallable)
	FString GetItemName(int32 item_id);
};
