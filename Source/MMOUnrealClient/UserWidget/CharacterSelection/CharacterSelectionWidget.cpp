#include "CharacterSelectionWidget.h"
#include "Network/Game/Thread/GameSocketThread.h"

#include "Network/Packets/ClientToGame/CharacterSelected.h"

/**
 * @author Dego1n
 */
TArray<APlayableCharacter*> UCharacterSelectionWidget::GetAvailableCharacterList()
{
	GameSocketThread::Runnable->world = GetWorld();
	return GameSocketThread::Runnable->availableCharacters;
}

void UCharacterSelectionWidget::RequestCharacterSelected(FString characterId)
{
	GameSocketThread::Runnable->SendPacket(new CharacterSelected(characterId));
}