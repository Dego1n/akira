#include "RequestDialog.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

RequestDialog::RequestDialog(int32 objectId, FString dialog)
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] RequestDialog"));
	#endif

	this->objectId = objectId;
	this->dialog = dialog;

	Build();
	PrepareForSend();
}

void RequestDialog::Build()
{
	WriteH(ClientToGamePackets::Packet::REQUEST_DIALOG);

	WriteH(objectId);
	WriteS(dialog);
}
