// MMOClient 2019


#include "PCActorInfo.h"
#include "Model/Actor/GameActor.h"
#include "Model/WorldInstance.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "GameFramework/CharacterMovementComponent.h"

PCActorInfo::PCActorInfo(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] PCActorInfo"));
#endif
	this->Handle();
}

PCActorInfo::~PCActorInfo()
{
}

void PCActorInfo::Handle()
{
	//int32 templateId = ReadD();

	int32 locationX = ReadD();
	int32 locationY = ReadD();
	int32 locationZ = ReadD();

	int32 collisionHeight = ReadD();
	int32 collisionRadius = ReadD();

	bool isFriendly = ReadH() == 0 ? false : true;
	//int32 currentHp = ReadD();
	//int32 maxHp = ReadD();

	FVector locationVector;
	locationVector.X = locationX;
	locationVector.Y = locationY;
	locationVector.Z = locationZ;

	FString name = ReadS();
	FString title = ReadS();

	int32 con = ReadD();
	int32 str = ReadD();
	int32 dex = ReadD();
	int32 _int = ReadD();
	int32 wit = ReadD();
	int32 men = ReadD();

	int32 physAttack = ReadD();
	int32 physDefence = ReadD();
	int32 evasion = ReadD();
	int32 accuracy = ReadD();
	int32 attackSpeed = ReadD();
	int32 moveSpeed = ReadD();
	int32 critical = ReadD();

	/* EquipInfo Start */
	FEquipInfo* equipInfo = new FEquipInfo;

	equipInfo->rightHand = ReadD();
	ReadD();
	equipInfo->leftHand = ReadD();
	ReadD();
	equipInfo->helmet = ReadD();
	ReadD();
	equipInfo->upperArmor = ReadD();
	ReadD();
	equipInfo->lowerArmor = ReadD();
	ReadD();
	equipInfo->gloves = ReadD();
	ReadD();
	equipInfo->boots = ReadD();
	ReadD();
	equipInfo->belt = ReadD();
	ReadD();
	equipInfo->earring1 = ReadD();
	ReadD();
	equipInfo->earring2 = ReadD();
	ReadD();
	equipInfo->ring1 = ReadD();
	ReadD();
	equipInfo->ring2 = ReadD();
	ReadD();
	equipInfo->necklace = ReadD();
	ReadD();

	/* EquipInfo End */

	FFunctionGraphTask::CreateAndDispatchWhenReady([this, locationVector, name, title, isFriendly, collisionHeight, collisionRadius, equipInfo, con,str,dex,_int,wit,men, physAttack, physDefence, evasion, accuracy, attackSpeed, moveSpeed, critical]() {

		APlayableCharacter* actor = GameSocketThread::Runnable->character;

		if (actor != nullptr)
		{
			//actor->UpdateCollision(collisionHeight, collisionRadius);
			actor->UpdateName(name, title);
			actor->equipInfo = equipInfo;
			actor->RenderEquipInfo();
			
			actor->con = con;
			actor->str = str;
			actor->dex = dex;
			actor->_int = _int;
			actor->wit = wit;
			actor->men = men;

			actor->physAttack = physAttack;
			actor->physDefence = physDefence;
			actor->physEvasion = evasion;
			actor->physAccuracy = accuracy;
			actor->attackSpeed = attackSpeed;
			actor->moveSpeed = moveSpeed;
			actor->physCritical = critical;
			actor->GetCharacterMovement()->MaxWalkSpeed = moveSpeed;
			actor->CharacterInfoWidget(true);
		}
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
}
