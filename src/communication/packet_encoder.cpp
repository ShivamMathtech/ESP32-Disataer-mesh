#include "packet_encoder.h"

uint16_t PacketEncoder::encode(
    const DisasterPacket& packet,
    uint8_t* buffer)
{
    memcpy(
        buffer,
        &packet,
        sizeof(DisasterPacket)
    );

    return sizeof(DisasterPacket);
}

bool PacketEncoder::decode(
    const uint8_t* buffer,
    uint16_t length,
    DisasterPacket& packet)
{
    if(length != sizeof(DisasterPacket))
        return false;

    memcpy(
        &packet,
        buffer,
        sizeof(DisasterPacket)
    );

    return true;
}