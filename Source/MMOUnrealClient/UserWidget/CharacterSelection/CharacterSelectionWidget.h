#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Model/Actor/PlayableCharacter.h"
	
#include "CharacterSelectionWidget.generated.h"

/**
 * @author Dego1n
 */
UCLASS()
class UCharacterSelectionWidget : public UUserWidget
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Character Selection")
	TArray<APlayableCharacter*> GetAvailableCharacterList();

	UFUNCTION(BlueprintCallable, Category = "Character Selection")
	void RequestCharacterSelected(int32 id);
};
