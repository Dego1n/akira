#include "GameActor.h"
#include <Runtime/Engine/Classes/Components/StaticMeshComponent.h>
#include "NavigationSystem.h"
#include "DrawDebugHelpers.h"
#include "AIController.h"
#include "Kismet/KismetMathLibrary.h"
#include "Navigation/PathFollowingComponent.h"
#include "Engine/Engine.h"
#include "Classes/Components/SkeletalMeshComponent.h"
#include "Animation/AnimSequence.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "UserWidget/Base/BaseActorName.h"
#include "UserWidget/BaseActorTitle.h"
#include "Animation/CharacterAnimationInstance.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Animation/AnimBlueprintGeneratedClass.h"
#include "Animation/AnimBlueprint.h"
#include "Util/Math/2D/Math2d.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"
#include "Model/WorldInstance.h"
#include "Database/ItemRenderPropertiesBase.h"
#include "Database/Ability/AbilityTable.h"
#include "Database/Ability/AbilityAnimationTable.h"

/**
 * @author Dego1n
 */
AGameActor::AGameActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGameActor::UpdateName(FString newName, FString title)
{
	this->name = newName;
	
	//Обновляем виджет имени
	Cast<UBaseActorName>(actorNameWidget->GetUserWidgetObject())->actorName = newName;

	Cast<UBaseActorTitle>(actorTitleWidget->GetUserWidgetObject())->actorTitle = title;
}

void AGameActor::BeginPlay()
{
	//GetCharacterMovement()->MaxWalkSpeed = 300;
	Super::BeginPlay();

	//Получаем гейм инстанс
	UWorldGameInstance * wgi = Cast<UWorldGameInstance>(GetGameInstance());

	//Создаем новый Widget имени актора в мире
	actorNameWidget = NewObject<UWidgetComponent>(this, UWidgetComponent::StaticClass(), TEXT("Actor Name Widget"));
	actorNameWidget->SetWidgetClass(wgi->actorNameWidget);
	//Ставим виджет не на экране а в мире
	actorNameWidget->SetWidgetSpace(EWidgetSpace::Screen);
	//Присваем виджет нашему игроку, а не NPC 
	actorNameWidget->SetOwnerPlayer(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetLocalPlayer());
	//Показываем
	actorNameWidget->SetVisibility(true);
	//actorNameWidget->bVisible = true;
	//Атачим к мешу актора
	//TODO:Скорее всего из-за имя разворачивается вместе с Mesh. По-этому такие прыжки при развороте камеры.
	actorNameWidget->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform);
	//Регистрируем компонент, по идеи после этого метода имя начнет отображаться в мире
	actorNameWidget->RegisterComponent();
	//FIXME: спавнить по высоте капсулы
	actorNameWidget->SetRelativeLocation(FVector(0, 0, 200));

	//Создаем новый Widget имени актора в мире
	actorTitleWidget = NewObject<UWidgetComponent>(this, UWidgetComponent::StaticClass(), TEXT("Actor Title Widget"));
	actorTitleWidget->SetWidgetClass(wgi->actorTitleWidget);
	//Ставим виджет не на экране а в мире
	actorTitleWidget->SetWidgetSpace(EWidgetSpace::Screen);
	//Присваем виджет нашему игроку, а не NPC 
	actorTitleWidget->SetOwnerPlayer(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetLocalPlayer());
	//Показываем
	actorTitleWidget->SetVisibility(true);
	//actorTitleWidget->bVisible = true;
	//Атачим к мешу актора
	//TODO:Скорее всего из-за имя разворачивается вместе с Mesh. По-этому такие прыжки при развороте камеры.
	actorTitleWidget->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform);
	//Регистрируем компонент, по идеи после этого метода имя начнет отображаться в мире
	actorTitleWidget->RegisterComponent();
	//FIXME: спавнить по высоте капсулы
	actorTitleWidget->SetRelativeLocation(FVector(0, 0, 210));

	//PathFollowing компонент будет выполнять работу по ротейшену вовремя движения за нас
	bUseControllerRotationYaw = false;

	#if !UE_BUILD_SHIPPING
		//Если это дев билд - показываем капсулы
		GetCapsuleComponent()->bHiddenInGame = false;
	#endif


	//Навигация теперь билдится динамически.
	//Были изменены следующие настройки:
	/**
	First you will need to change some settings inside your project settings.

	Project settings -> Navigation Mesh -> Generation -> Advanced Dropdown -> Change Max simultaneous tile generation jobs count to 1.

	Project settings -> Navigation Mesh -> Runtime -> Runtime Generation to Dynamic.

	Project settings -> Navigation System -> Data Gathering Mode to Lazy.

	Project settings -> Navigation System -> Generate Navigation Only Around Navigation Invokers.
	*/
	//Дальше был добавлен NavMeshBounds (Выдает ошибку в логе что слишком большой, но работает).
	//Дальше этим кодом регистрируем инвокера. //TODO: Если отправить актора слишком далеко - все фейлится. Вроде можно где-то настроить рейндж в инвокере.
	auto navsys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
	navsys->bSkipAgentHeightCheckWhenPickingNavData = true;
	navsys->RegisterNavigationInvoker(this);

	questMark = NewObject<UStaticMeshComponent>(this, UStaticMeshComponent::StaticClass(), TEXT("Quest Mark"));
	UStaticMesh* questMarkMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Models/Misc/exclamation_mark.exclamation_mark'"));
	questMark->SetStaticMesh(questMarkMesh);
	questMark->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform);
	questMark->RegisterComponent();
	questMark->SetRelativeLocation(FVector(0, 0, 210));
	questMark->SetVisibility(false);


	lootBag = NewObject<UStaticMeshComponent>(this, UStaticMeshComponent::StaticClass(), TEXT("Loot Bag"));
	UStaticMesh* lootBagMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Models/Misc/LootBag.LootBag'"));
	lootBag->SetStaticMesh(lootBagMesh);
	lootBag->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform);
	lootBag->RegisterComponent();
	lootBag->SetRelativeLocation(FVector(0, 0, 210));
	lootBag->SetVisibility(false);
}

// Called every frame
void AGameActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Если персонаж двигается
	if(isMoving)
	{
		//Добарлся до нужного вектора?
		if(Math2d::Find2dDistanceBetween3DVectors(GetActorLocation(),goalLocation) < 50)
		{
			UpdateMoving(false);
		}
	}

	if (faceTarget != nullptr)
	{
		FVector MyLoc = GetActorLocation();
		FVector TargetLoc = faceTarget->GetActorLocation();
		FVector Dir = (TargetLoc - MyLoc);
		Dir.Normalize();
		SetActorRotation(FMath::Lerp(GetActorRotation(), FRotator(0, Dir.Rotation().Yaw,0), 0.05f));
	}

}

void AGameActor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGameActor::LoadAnimations()
{
	int32 id = isNpc ? templateId : race;

	//Загружаем BP анинмации и обновляем инстанс
	FString AnimClassString = AssetDatabase::GetInstance()->GetAnimationsForActor(id);
	UClass* AnimClass = LoadObject<UClass>(NULL, *AnimClassString);
	GetMesh()->SetAnimInstanceClass(AnimClass);

	//Загружаем все типы анимаций
	TArray<AssetDatabase::ActorAnimationMontages> actorAnimationMontages = AssetDatabase::GetInstance()->GetActorMontageAnimations(id);
	for (AssetDatabase::ActorAnimationMontages montage : actorAnimationMontages)
	{
		if (montage.animationName.Equals("Attack_1HandSword"))
		{
			attack1HandMontages.Add(*montage.animationsPath);
		}
		else if (montage.animationName.Equals("Die"))
		{
			dieMontages.Add(*montage.animationsPath);
		}
		else if (montage.animationName.StartsWith("Skill"))
		{
			skillMontages.Add(*montage.animationsPath);
		}
	}

}
void AGameActor::MontageAttack(AGameActor* target)
{
	//Если это NPC, то смотрим на цель.
	if (isNpc) 
	{
		faceTarget = target;
	}
	//Если анимации есть - выбираем рандомную и играем
	if (attack1HandMontages.Num() > 0)
	{
		int32 randomIndex = FMath::RandRange(0, attack1HandMontages.Num() - 1);
		UAnimMontage* montage = LoadObject<UAnimMontage>(NULL, *attack1HandMontages[randomIndex]);
		#if !UE_BUILD_SHIPPING
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, *attack1HandMontages[randomIndex]);
		#endif
		//UE_LOG(LogTemp, Warning, TEXT("Attack Speed: %D"), attackSpeed);
		//UE_LOG(LogTemp, Warning, TEXT("Fors: %D"), attackSpeed);
		//UE_LOG(LogTemp, Warning, TEXT("calculated playrate: %f"), montage->SequenceLength / (1.0 / (attackSpeed / 1000)));
		//UE_LOG(LogTemp, Warning, TEXT("calculated playrate: %f"), montage->SequenceLength / (1.0 / (attackSpeed / 1000)));
		UE_LOG(LogTemp, Warning, TEXT("calculated playrate: %f"), montage->SequenceLength / (1.0 / (attackSpeed / 1000.0)));
			
		GetMesh()->GetAnimInstance()->Montage_Play(montage, montage->SequenceLength / (1.0 / (attackSpeed/1000.0)));
	}
}
void AGameActor::DieMontage()
{
	//Удаляем капсулу, чтобы не было коллизий у трупа
	GetCapsuleComponent()->DestroyComponent();

	//Если анимации есть - выбираем рандомную и играем
	if (dieMontages.Num() > 0)
	{
		int32 randomIndex = FMath::RandRange(0, dieMontages.Num() - 1);
		UAnimMontage* anim = LoadObject<UAnimMontage>(NULL, *dieMontages[randomIndex]);
		PauseMontageInTime(anim->GetPlayLength() - 0.5f);
		GetMesh()->GetAnimInstance()->Montage_Play(anim, 1.f);
	}
}

/**
 * Фризим анимацию через опредленное время
 * Используется при смерти
 */ 
void AGameActor::PauseMontageInTime(float inTime)
{

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &AGameActor::PauseMontage, inTime, false);
}

void AGameActor::PauseMontage()
{
	GetMesh()->GetAnimInstance()->Montage_Pause();
}

void AGameActor::UseAbility(AGameActor* target, int32 abilityId, float castTime)
{
	UE_LOG(LogTemp, Warning, TEXT("REQUESTED CAST TIME: %f"), castTime)
	UWorldGameInstance* wgi = Cast<UWorldGameInstance>(GetGameInstance());


	for (auto abilityAnimation : wgi->abilityAnimations->GetRowMap())
	{
		int32 id = isNpc ? templateId : race;
		FAbilityAnimationTable* row = (FAbilityAnimationTable*)abilityAnimation.Value;
		UE_LOG(LogTemp, Warning, TEXT("Iterating animationName %s"), *row->animation);
		UE_LOG(LogTemp, Warning, TEXT("Iterating key %s"), *abilityAnimation.Key.ToString());
		UE_LOG(LogTemp, Warning, TEXT("Comparing to key %s"), *FString::FromInt(abilityId));
		UE_LOG(LogTemp, Warning, TEXT("Iterating templateId %s"), *FString::FromInt(row->actorTemplate));
		UE_LOG(LogTemp, Warning, TEXT("To id %s"), *FString::FromInt(id));
		if (abilityAnimation.Key.ToString().Equals(FString::FromInt(abilityId)) && row->actorTemplate == id)
		{
			UAnimMontage* montage = LoadObject<UAnimMontage>(NULL, *row->animation);
			UE_LOG(LogTemp, Warning, TEXT("DOING IN PLAY RATE: %f"), montage->SequenceLength / castTime)
			GetMesh()->GetAnimInstance()->Montage_Play(montage, montage->SequenceLength / castTime);
		}

	}
}

/**
 * Уничтожение актора через определенное время
 */
void AGameActor::DestroyInTime(int seconds)
{
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &AGameActor::DestroyActor, seconds, false);
}

/**
 * Удаление Актора из мира
 */
void AGameActor::DestroyActor()
{
	WorldInstance::GetInstance()->RemoveActorFromWorld(this);
	this->Destroy();
}

/**
 * Движение актора в Location
 */
void AGameActor::MoveActorToLocation(FVector target)
{
	goalLocation = target;

	UPathFollowingComponent* PathFollowingComp = nullptr;

	//Ищем компонент
	PathFollowingComp = GetController()->FindComponentByClass<UPathFollowingComponent>();

	//Если не нашли, создаем новый
	if (PathFollowingComp == nullptr)
	{
		PathFollowingComp = NewObject<UPathFollowingComponent>(GetController());
		PathFollowingComp->RegisterComponentWithWorld(GetWorld());
		PathFollowingComp->Initialize();
	}

	//Вытаскиваем систему навигации из мира
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
		
	//Если персонаж двигается, завершаем текущее движение
	if (PathFollowingComp->GetStatus() != EPathFollowingStatus::Idle || isMoving)
	{
		PathFollowingComp->AbortMove(*NavSys, FPathFollowingResultFlags::ForcedScript | FPathFollowingResultFlags::NewRequest
			, FAIRequestID::AnyRequest, isMoving ? EPathFollowingVelocityMode::Reset : EPathFollowingVelocityMode::Keep);
		PathFollowingComp->AbortMove(*NavSys, FPathFollowingResultFlags::ForcedScript | FPathFollowingResultFlags::NewRequest);
		
	}

	//?
	const ANavigationData* NavData = NavSys->GetNavDataForProps(GetNavAgentPropertiesRef());

	if (NavData)
	{

		//Строим путь
		FPathFindingQuery Query(this, *NavData, GetNavAgentLocation(), goalLocation);
		FPathFindingResult Result = NavSys->FindPathSync(Query);

		//Если путь успешно построен
		if (Result.IsSuccessful())
		{
			//Получаем вектор разворота
			FVector Dir = (goalLocation - GetActorLocation());
			Dir.Normalize();

			//Разворачиваем
			SetActorRotation(FMath::VInterpTo(GetActorLocation(), FVector(Dir.X,Dir.Y,0), 1, 10.0).Rotation());


			PathFollowingComp->RequestMove(FAIMoveRequest(goalLocation), Result.Path);

			UpdateMoving(true);
		}
	}
	
}

void AGameActor::AbortMove()
{
	//Вытаскиваем PathFollowing компонент
	//TODO: Проверять, может компонент не существует. В данном случае завершаем AbortMove
	UPathFollowingComponent* PathFollowingComp = GetController()->FindComponentByClass<UPathFollowingComponent>();
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	
	//Если персонаж в данный момент двигается
	if (PathFollowingComp->GetStatus() != EPathFollowingStatus::Idle || isMoving)
	{
		//Прерываем движение
		PathFollowingComp->AbortMove(*NavSys, FPathFollowingResultFlags::ForcedScript | FPathFollowingResultFlags::NewRequest
			, FAIRequestID::AnyRequest, isMoving ? EPathFollowingVelocityMode::Reset : EPathFollowingVelocityMode::Keep);
		PathFollowingComp->AbortMove(*NavSys, FPathFollowingResultFlags::ForcedScript | FPathFollowingResultFlags::NewRequest);
		
		UpdateMoving(false);
	}
}

void AGameActor::UpdateMoving(bool updateIsMoving)
{
	if (updateIsMoving)
	{
		Cast<UCharacterAnimationInstance>(GetMesh()->GetAnimInstance())->speed = 100;
		if (this == GameSocketThread::Runnable->character)
		{
			//Тригерим дополнительные ивенты об начале движения
			Cast<APlayableCharacter>(this)->OnStartMoving();
		}
	}
	else
	{
		Cast<UCharacterAnimationInstance>(GetMesh()->GetAnimInstance())->speed = 0;
		if (this == GameSocketThread::Runnable->character)
		{
			//Тригерим дополнительные ивенты об начале движения
			Cast<APlayableCharacter>(this)->OnStopMoving();
		}
	}
}

void AGameActor::MoveToPawn(AGameActor* pawn, int32 radius)
{
	//Вычисляем конечную точку
	//Формула в читабельном виде лежит в: /Formulas/3D/Closest Point on a Sphere to Another Point.png
	FVector actorLocation = GetActorLocation();
	FVector pawnLocation = pawn->GetActorLocation();

	float distance = FMath::Sqrt(
						FMath::Square(actorLocation.X - pawnLocation.X) +
						FMath::Square(actorLocation.Y - pawnLocation.Y) +
						FMath::Square(actorLocation.Z - pawnLocation.Z)
					);

	FVector* targetLocation = new FVector(
		pawnLocation.X + ((radius * (actorLocation.X - pawnLocation.X)) / (distance)),
		pawnLocation.Y + ((radius * (actorLocation.Y - pawnLocation.Y)) / (distance)),
		pawnLocation.Z + ((radius * (actorLocation.Z - pawnLocation.Z)) / (distance))
	);

	//Выполняем обычный MoveActorToLocation к вычисленной точке
	MoveActorToLocation(*targetLocation);
}

void AGameActor::UpdateSkeletalMesh()
{
	if(isNpc)
	{
		GetMesh()->SetSkeletalMesh(LoadObject<USkeletalMesh>(nullptr, *AssetDatabase::GetInstance()->GetSkeletalMeshForActor(templateId)));
	}
	else
	{
		GetMesh()->SetSkeletalMesh(LoadObject<USkeletalMesh>(nullptr, *AssetDatabase::GetInstance()->GetSkeletalMeshForCharacterRace(race)));
		
	}
	GetMesh()->SetRelativeRotation(FRotator(0, 270, 0)); //TODO: почему-то это фиксит стандартный разворот всех акторов

}

void AGameActor::UpdateCollision(int32 collisionHeight, int32 collisionRadius)
{
	//Фиксим капсулу
	//Важно сначала ставить радиус, а потом высоту
	GetCapsuleComponent()->SetCapsuleRadius(collisionRadius);
	GetCapsuleComponent()->SetCapsuleHalfHeight(collisionHeight);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	FVector loc = GetMesh()->GetComponentLocation();
	loc.Z -= GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
	GetMesh()->SetWorldLocation(loc);
}

void AGameActor::RenderEquipInfo()
{
	int32 rightHand = equipInfo->rightHand;
	if (rightHand != 0)
	{ 

		auto* wgi = Cast<UWorldGameInstance>(GetGameInstance());
		auto row =  *(wgi->itemsTable->FindRow<FItemTable>(FName(*FString::FromInt(rightHand)), "", true));
		
		if (this->rightHand == nullptr)
		{
			this->rightHand = NewObject<UStaticMeshComponent>(GetMesh(), UStaticMeshComponent::StaticClass(), TEXT("RightHandComponent"));
			this->rightHand->RegisterComponentWithWorld(GetWorld());
			//AddOwnedComponent(this->rightHand);
			this->rightHand->SetSimulatePhysics(false);
			this->rightHand->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

			this->rightHand->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

			this->rightHand->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("RightHandSocket"));
			//this->rightHand->AttachRootComponentToActor(this, "hand_rSocket", EAttachLocation::SnapToTarget, false);

		}
		auto Object = LoadObject<UStaticMesh>(nullptr, *FString(row.model.ToString()));
		this->rightHand->SetStaticMesh(Object);
		FItemRenderPropertiesBase* renderProperties = AssetDatabase::GetInstance()->GetItemPropertiesByActorAndItem(templateId, rightHand);
		if (renderProperties != nullptr)
		{
			this->rightHand->SetRelativeLocation(
				FVector(
					renderProperties->locationX,
					renderProperties->locationY,
					renderProperties->locationZ
				)
			);
			this->rightHand->SetRelativeScale3D(FVector(renderProperties->scaleX, renderProperties->scaleY, renderProperties->scaleZ));
			this->rightHand->SetRelativeRotation(FRotator(renderProperties->rotationY, renderProperties->rotationZ, renderProperties->rotationX));
		}

	}
}

void AGameActor::ShowExclamationMark(bool show)
{
	questMark->SetVisibility(show);
}
void AGameActor::ShowLootBag(bool show)
{
	lootBag->SetVisibility(show);
}
