#include "CharacterCreationWidget.h"
#include "Network/Game/Thread/GameSocketThread.h"

#include "Network/Packets/ClientToGame/RequestCreateCharacter.h"

/**
 * @author Dego1n
 */
void UCharacterCreationWidget::CreateCharacter(FString name, int32 race, int32 characterClass)
{
	GameSocketThread::Runnable->SendPacket(new RequestCreateCharacter(name,race,characterClass));
}

void UCharacterCreationWidget::UpdateCurrentWorld()
{
	GameSocketThread::Runnable->world = GetWorld();
}