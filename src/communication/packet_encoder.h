#pragma once

#include <Arduino.h>
#include "../../include/packet.h"

class PacketEncoder
{
public:

    static uint16_t encode(
        const DisasterPacket& packet,
        uint8_t* buffer
    );

    static bool decode(
        const uint8_t* buffer,
        uint16_t length,
        DisasterPacket& packet
    );
};