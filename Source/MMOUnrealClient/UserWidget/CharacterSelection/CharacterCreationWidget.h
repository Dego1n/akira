#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "CharacterCreationWidget.generated.h"

/**
 * @author Dego1n
 */
UCLASS()
class MMOUNREALCLIENT_API UCharacterCreationWidget : public UUserWidget
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Character Creation")
	void CreateCharacter(FString name, int32 race, int32 characterClass);

	UFUNCTION(BlueprintCallable, Category = "Character Creation")
	void UpdateCurrentWorld();
};
