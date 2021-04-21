#pragma once

#include "CoreMinimal.h"
#include "UMG/Public/Blueprint/UserWidget.h"
#include "Database/ItemRenderPropertiesBase.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API AssetDatabase
{
private:
	static AssetDatabase* instance;

	void LoadUserWidgets();
	void LoadCharacterRaces();
	void LoadCharacterAnimations();
	void LoadCharacterAnimationMontages();

	void LoadActorTemplates();
	void LoadItemRenderProperties();
public:
	AssetDatabase();
	~AssetDatabase();

	static AssetDatabase* GetInstance();

	struct ActorAnimations
	{
		int32 actorId;
		FString animationsPath;
	};

	struct ActorAnimationMontages
	{
		int32 actorId;
		FString animationName;
		FString animationsPath;
	};

	struct CharacterRaces
	{
		int32 raceId;
		FString skeletalMeshPath;
	};

	struct UserWidgets
	{
		FString name;
		FString userWidgetPath;
	};

	struct ActorTemplates
	{
		int32 templateId;
		FString skeletalMeshPath;
	};

	TArray<ActorAnimations> characterAnimations;
	TArray<ActorAnimationMontages> characterAnimationMontages;
	TArray<CharacterRaces> characterRaces;

	TArray<ActorTemplates> actorTemplates;

	TArray<UserWidgets> userWidgets;
	TArray<FItemRenderPropertiesBase*> itemRenderProperties;

	FString GetAnimationsForActor(int32 templateId);
	FString GetSkeletalMeshForCharacterRace(int32 raceId);

	FString GetSkeletalMeshForActor(int32 actorTemplate);
	TArray<AssetDatabase::ActorAnimationMontages> GetActorMontageAnimations(int32 actorTemplate);
	UUserWidget* GetUserWidgetByName(FString name);
	FItemRenderPropertiesBase* GetItemPropertiesByActorAndItem(int32 actorId, int32 itemId);
};
