// MMOClient 2019


#include "ChatBoxWidget.h"
#include "Network/Packets/ClientToGame/Say.h"
#include "Network/Packets/ClientToGame/RequestCommand.h"
#include "Network/Game/Thread/GameSocketThread.h"

void UChatBoxWidget::SendMessage(const FString message)
{
	if (message.StartsWith("//"))
	{
		GameSocketThread::Runnable->SendPacket(new RequestCommand(message.Mid(2, message.Len())));
	}
	else
	{
		GameSocketThread::Runnable->SendPacket(new Say(message));
	}
}
