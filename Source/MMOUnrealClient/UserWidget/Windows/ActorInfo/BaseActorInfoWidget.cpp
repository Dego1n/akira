// MMOClient 2019


#include "BaseActorInfoWidget.h"
#include "Network/Game/Thread/GameSocketThread.h"


void UBaseActorInfoWidget::CloseCharacterInfo()
{
	GameSocketThread::Runnable->character->CloseCharacterInfoWidget();
}