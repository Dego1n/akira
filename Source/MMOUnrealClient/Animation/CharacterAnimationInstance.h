#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimationInstance.generated.h"

/**
 * @author Dego1n
 */

UCLASS()
class MMOUNREALCLIENT_API UCharacterAnimationInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//bool isMoving;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//float attackSpeed = 0.8f;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//bool isAttacking;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//float attackRemainingTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float speed;
};
