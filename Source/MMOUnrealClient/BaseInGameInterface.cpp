// MMOClient 2019


#include "BaseInGameInterface.h"
#include "Network/Game/Thread/GameSocketThread.h"
//#include "Network/Packets/ClientToGame/RequestInventory.h"

//void UBaseInGameInterface::Inventory()
//{
//	GameSocketThread::Runnable->SendPacket(new RequestInventory());
//}
void UBaseInGameInterface::CharacterInfo()
{
	GameSocketThread::Runnable->character->CharacterInfoWidget();
}