#include "NPCDialog.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Model/Actor/PlayableCharacter.h"

/**
 * @author Dego1n
 */
void UNPCDialog::CloseDialog()
{
	APlayableCharacter* pc = GameSocketThread::Runnable->character;
	pc->CloseDialog();
}
