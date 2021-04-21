// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * 
 */
class MMOUNREALCLIENT_API UseItem : public AbstractSendablePacket
{
private:
    int32 object_id;
public:
    UseItem(int32 obj_id);
    void Build() override;
};
