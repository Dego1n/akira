// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Model/Actor/GameActor.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/AudioComponent.h"
#include "Camera/CameraComponent.h"

#include "UserWidget/Base/TargetWidget.h"
#include "UserWidget/Base/NPCDialog/NPCDialog.h"
#include "UserWidget/Base/ChatBox/ChatBoxWidget.h"

#include "UserWidget/Windows/Inventory/BaseInventory.h"
#include "UserWidget/Windows/BaseInventorySlot.h"
#include "UserWidget/Windows/Loot/BaseLootWindow.h"
#include "UserWidget/Windows/Loot/BaseLootWindowSlot.h"
#include "UserWidget/Windows/ActorInfo/BaseActorInfoWidget.h"
#include "UserWidget/Windows/AcquireSkillList/BaseAcquireSkillList.h"
#include "UserWidget/Windows/AcquireSkillList/BaseAcquireSkillListSlot.h"
#include "UserWidget/Windows/Quest/BaseQuestListWindow.h"

#include "Model/Item/InventoryItem.h"
#include "Model/Item/EquipInfo.h"
#include "Model/Ability/Ability.h"
#include "Model/Quest/QuestProgression.h"
#include "BaseInGameInterface.h"
#include "UserWidget/Windows/Dialogs/Buylist/BaseBuyList.h"

#include "PlayableCharacter.generated.h"

UCLASS()
class MMOUNREALCLIENT_API APlayableCharacter : public AGameActor
{
	GENERATED_BODY()
private:
	float validatedLocationTime;
	void CameraTurn(float value);
	void CameraLookUp(float value);
	void EventLeftMouseButton();
	void EventMouseWheelUp();
	void EventMouseWheelDown();
	void EventShiftPressed();
	void EventShiftReleased();

	bool isShiftPressed = false;
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* OurCameraSpringArm;

	UPROPERTY(EditAnywhere)
	UAudioComponent* AudioComponent;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> targetWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> dialogWidget;

	//TSubclassOf

	UTargetWidget* instantiatedTargetWidget;
	UNPCDialog* instantiatedNPCDialogWidget;
	UChatBoxWidget* instantiatedChatBoxWidget;
	UBaseInventory* instantiatedInventoryWidget;
	UBaseLootWindow* instantiatedLootWindow;
	UBaseInGameInterface* instantiatedInGameInterface;
	UBaseBuyList* instantiatedBuyListWidget;
	UBaseActorInfoWidget* instantiatedActorInfoWidget;
	UBaseAcquireSkillList* instantiatedAcquireSkillListWidget;
	UBaseQuestListWindow* instantiatedQuestListWidget;


public:
	APlayableCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void InventoryUpdated();
	void ShowInventory();
	void ShowQuestList();
	void TargetSelected(AGameActor* actor);
	void TargetUnselected();
	void onLootDataUpdated(AGameActor* actor);
	AGameActor* GetCurrentTarget();
	void ReceivedChatMessage(FString actorName, FString actorMessage);
	void ReceivedSystemMessage(FString message);
	void ShowDialog(FString dialog);
	void CloseDialog();
	void GetDialog(int32 objectId, FString dialog);
	void OnQuestTalk(int32 objectId, int32 questId, FString ref);
	void UpdateAbilities(TArray<FAbility> abilities);
	void ShowBuyList(TMap<FInventoryItem, int32> buyItems, TMap<FInventoryItem, int32> sellItems, int32 currencyId, int32 buylistId);
	void UpdateStatusInfo(int32 level, float currentHp, float maxHp, float currentMp, float maxMp, int32 startLevelExperience, int32 currentExperience, int32 experienceToNextLevel);
	void CharacterInfoWidget(bool update = false);
	void CloseCharacterInfoWidget();
	void SpecialCharacterInfoWidget(FString name, int32 level, int32 currentHp, int32 maxHp, int32 currentMp, int32 maxMp, int32 pAtk, int32 pDef);
	void AcquireSkillList(TArray<FAbility> abilities);
	void updateQuestList(TArray<FQuestProgression> questProgression);
	void PlaySound(int32 soundId);

	UPROPERTY(EditAnywhere)
    UCameraComponent* OurCamera;

	void RequestMoveToLocation(FVector origin, FVector target);

	int32 GetItemAmount(int32 itemId);

	/** ������ */
	void OnStartMoving();
	void OnStopMoving();
	void UserInfoUpdated();

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void Turn(float AxisValue);


	/** ��������������� ������ **/
	UFUNCTION(BlueprintCallable, Category = "PlayableCharacter")
	FString GetRaceName(int32 characterRace);

	UFUNCTION(BlueprintCallable, Category = "PlayableCharacter")
	FString GetCharacterClassName(int32 chracterClass);

	TArray<FAbility> characterAbilities;
	TArray<FInventoryItem> inventoryItems;
	TArray<FQuestProgression> quests;
};
