#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "EngineGlobals.h"
#include "WorldGameInstance.h"
#include "Database/AssetDatabase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/WidgetComponent.h"
#include "Model/Item/EquipInfo.h"
#include "Model/Struct/LootObjectStruct.h"

#include "GameActor.generated.h"


/**
 * @author Dego1n
 */
UCLASS()
class MMOUNREALCLIENT_API AGameActor : public ACharacter
{
	GENERATED_BODY()
private:
	TArray<AssetDatabase::ActorAnimations> animations;
public:
	AGameActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameActor")
	FVector goalLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameActor")
	bool isMoving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayableCharacter")
	int32 id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayableCharacter")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayableCharacter")
	int32 race;
	
	UStaticMeshComponent* questMark;
	UStaticMeshComponent* lootBag;

	int32 templateId;

	AGameActor* target;

	FEquipInfo* equipInfo;

	bool isNpc = false;
	bool isFriendly = false;

	double currentHp;
	double maxHp;
	bool isDead = false;
	TArray<LootObjectStruct> loot;

	AGameActor* faceTarget;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayableCharacter")
	int32 characterClass;

	void UpdateName(FString name, FString title = "");

	UStaticMeshComponent* rightHand;


	//Переместить это в отдельный класс
	TArray<FString> attack1HandMontages;
	TArray<FString> dieMontages;
	TArray<FString> skillMontages;

	//Stats
	FString className;
	int32 level;
	float percentHp;
	float currentMp;
	float maxMp;
	float percentMp;
	int32 currentExperience;
	int32 startLevelExperience;
	int32 experienceToNextLevel;
	float percentExperience;
	float percentExperienceToShow;
	int32 skillPoints;
	int32 physAttack;
	int32 physDefence;
	int32 physAccuracy;
	int32 physEvasion;
	int32 physCritical;
	int32 attackSpeed;
	int32 moveSpeed;
	int32 magicAttack;
	int32 magicDefence;
	int32 magicAccuracy;
	int32 magicEvasion;
	int32 magicCritical;
	int32 castingSpeed;
	int32 str;
	int32 con;
	int32 dex;
	int32 _int;
	int32 wit;
	int32 men;

protected:
	virtual void BeginPlay() override;

	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere)
	UWidgetComponent* actorNameWidget;
	UWidgetComponent* actorTitleWidget;

public:	
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void LoadAnimations();
	void MoveActorToLocation(FVector target);
	void AbortMove();
	void UpdateMoving(bool isMoving);
	void MoveToPawn(AGameActor* actor, int32 radius);
	void UpdateSkeletalMesh();
	void UpdateCollision(int32 collisionHeight, int32 collisionRadius);
	void MontageAttack(AGameActor* target);
	void DieMontage();
	void PauseMontageInTime(float inTime);
	void PauseMontage();
	void UseAbility(AGameActor* target, int32 abilityId, float castTime);
	void DestroyInTime(int seconds);
	void DestroyActor();

	void RenderEquipInfo();

	void ShowExclamationMark(bool show = true);
	void ShowLootBag(bool show = true);
};
