#pragma once

#include <Runtime/Engine/Classes/Engine/DataTable.h>
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UserWidget/Windows/CharacterStatus/BaseCharacterStatusWidget.h"
#include "WorldGameInstance.generated.h"

/**
 * @author Dego1n
 */

UCLASS()
class MMOUNREALCLIENT_API UWorldGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UWorldGameInstance();

	virtual void Init() override;

	UFUNCTION()
		virtual void BeginLoadingScreen(const FString& MapName);
	UFUNCTION()
		virtual void EndLoadingScreen(UWorld* InLoadedWorld);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Instance Widgets")
	TSubclassOf<class UUserWidget> actorNameWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Instance Widgets")
	TSubclassOf<class UUserWidget> actorTitleWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Instance Widgets")
	TSubclassOf<class UUserWidget> targetWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Instance Widgets")
	TSubclassOf<class UUserWidget> npcDialog;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Instance Widgets")
	TSubclassOf<class UUserWidget> chatBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Instance Widgets")
	TSubclassOf<class UUserWidget> inventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Instance Widgets")
	TSubclassOf<class UUserWidget> inventorySlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Instance Widgets")
	TSubclassOf<class UUserWidget> lootWindow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Instance Widgets")
	TSubclassOf<class UUserWidget> lootWindowSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Instance Widgets")
	TSubclassOf<class UUserWidget> abilityWindow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Instance Widgets")
	TSubclassOf<class UUserWidget> abilityWindowSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Instance Widgets")
	TSubclassOf<class UUserWidget> inGameInterface;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Instance Widgets")
	TSubclassOf<class UUserWidget> buyListWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Instance Widgets")
	TSubclassOf<class UUserWidget> actorInfoWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Instance Widgets")
	TSubclassOf<class UUserWidget> AcquireSkillListWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Instance Widgets")
	TSubclassOf<class UUserWidget> AcquireSkillListSlotWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Instance Widgets")
	TSubclassOf<class UUserWidget> QuestWindowWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Created Widgets")
	UBaseCharacterStatusWidget* characterStatusWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString buildRevision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString buildBranch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString buildVersion;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString buildDate;

	UFUNCTION(BlueprintCallable, Category = "WorldGameInstance")
	void UpdateBuildNumbers();

	UFUNCTION(BlueprintCallable, Category = "WorldGameInstance",meta=(WorldContext="WorldContextObject"))
	void WorldLevelLoaded(UObject* WorldContextObject);

	UFUNCTION(Exec)
	void EndPlay();

	/* DATA */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Instance")
    UDataTable* itemsTable;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Instance")
	UDataTable* itemsRenderPropertiesTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Instance")
	UDataTable* abilitiesData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Instance")
	UDataTable* abilityAnimations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Instance")
	UDataTable* questsTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Instance")
	UDataTable* questsStepsTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Instance")
	UDataTable* sounds2DTable;
};
