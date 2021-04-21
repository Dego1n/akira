// MMOClient 2020

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class QuestRewardType : uint8
{
		UE_4_24_FIX = 0,
		EXPERIENCE = 1,
		SKILL_POINTS = 2,
		CHOICE_REWARD = 3
};
