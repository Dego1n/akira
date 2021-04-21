#include "UserInfo.h"

#include "Network/Game/Thread/GameSocketThread.h"
#include "Model/WorldInstance.h"
#include "Model/Item/EquipInfo.h"
/**
 * @author Dego1n
 */

UserInfo::UserInfo(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] UserInfo"));
#endif
	this->Handle();
}

UserInfo::~UserInfo()
{
}

void UserInfo::Handle()
{
	int32 id = ReadD();
	int16 raceId = ReadH();
	int16 characterClass = ReadH();
	int32 locationX = ReadD();
	int32 locationY = ReadD();
	int32 locationZ = ReadD();

	int32 collisionHeight = ReadD();
	int32 collisionRadius = ReadD();

	FVector locationVector;
	locationVector.X = locationX;
	locationVector.Y = locationY;
	locationVector.Z = locationZ;

	FString name = ReadS();
	FString title = ReadS();

	/* EquipInfo Start */
	FEquipInfo* equipInfo = new FEquipInfo;

	equipInfo->rightHand = ReadD();
	equipInfo->leftHand = ReadD();
	equipInfo->helmet = ReadD();
	equipInfo->upperArmor = ReadD();
	equipInfo->lowerArmor = ReadD();
	equipInfo->gloves = ReadD();
	equipInfo->boots = ReadD();
	equipInfo->belt = ReadD();
	equipInfo->earring1 = ReadD();
	equipInfo->earring2 = ReadD();
	equipInfo->ring1 = ReadD();
	equipInfo->ring2 = ReadD();
	equipInfo->necklace = ReadD();


	/* EquipInfo End */

	
	FFunctionGraphTask::CreateAndDispatchWhenReady([this, id, locationVector, name, title, raceId, collisionHeight, collisionRadius, equipInfo]() {
		APlayableCharacter* character = GameSocketThread::Runnable->world->SpawnActor<APlayableCharacter>(locationVector, FRotator(0,0,0));
		character->id = id;
		character->race = raceId;
		character->UpdateName(name, title);
		character->equipInfo = equipInfo;
		//character->SetActorLocation(locationVector);
		character->UserInfoUpdated();
		character->LoadAnimations();
		character->UpdateCollision(collisionHeight,collisionRadius);
		character->AutoPossessPlayer =  EAutoReceiveInput::Player0;
		GameSocketThread::Runnable->character = character;
		WorldInstance::GetInstance()->AddPlayerToWorld(character);
		UE_LOG(LogTemp, Error, TEXT("WAITING TILL STREAMING"));
		APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(GameSocketThread::Runnable->world, 0);
		CameraManager->UpdateCamera(0.1f);
		GEngine->BlockTillLevelStreamingCompleted(GameSocketThread::Runnable->world);
		UE_LOG(LogTemp, Error, TEXT("STREAMING END STREAMING"));
			
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);

}
