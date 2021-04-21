// MMOClient 2019


#include "BaseAbilityWindow.h"
#include "Model/Ability/Ability.h"
#include "WorldGameInstance.h"
#include "Network/Game/Thread/GameSocketThread.h"

void UBaseAbilityWindow::Fill()
{
	UWorldGameInstance* wgi = Cast<UWorldGameInstance>(GetGameInstance());

	if (GameSocketThread::Runnable != nullptr)
	{
		TArray<FAbility> abilities =  GameSocketThread::Runnable->character->characterAbilities;
		for (FAbility ability : abilities)
		{
			UBaseAbilitySlot* slot = CreateWidget<UBaseAbilitySlot>(GetWorld(), wgi->abilityWindowSlot);
			ability.abilityTexture = slot->GetTexture(ability.ability_id);
			slot->ability = ability;
			this->abilitySlots.Add(slot);
		}
	}
	else
	{
		for (int i = 1; i <= 5; i++)
		{
			UBaseAbilitySlot* slot = CreateWidget<UBaseAbilitySlot>(GetWorld(), wgi->abilityWindowSlot);
			FAbilityTable abilityData = slot->GetAbilityTableObject(i);
			FAbility ability;
			ability.ability_id = i;
			ability.ability_level = abilityData.level;
			ability.ability_name = abilityData.name;
			ability.ability_description = abilityData.description;
			ability.ability_mana_cost = abilityData.manaCost;
			ability.abilityTexture = slot->GetTexture(ability.ability_id);
			slot->ability = ability;
			this->abilitySlots.Add(slot);
		}
	}
	this->AbilityListUpdated();
}
