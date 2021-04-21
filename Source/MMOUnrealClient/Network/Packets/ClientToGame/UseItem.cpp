// MMOClient 2019


#include "UseItem.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

UseItem::UseItem(int32 objId)
{
#if !UE_BUILD_SHIPPING
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] UseItem"));
#endif

    this->object_id = objId;

    Build();
    PrepareForSend();
}

void UseItem::Build()
{
    WriteH(ClientToGamePackets::Packet::USE_ITEM);
    WriteD(object_id);
    WriteH(1); //TODO: from inventory = true\false
}

