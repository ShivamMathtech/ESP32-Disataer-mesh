#pragma once

#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

#include "../../include/config.h"
#include "../../include/pins.h"
#include "../../include/packet.h"

#include "routing.h"
#include "packet_encoder.h"

class LoRaMesh
{
public:

    bool begin();

    void update();

    bool sendPacket(
        DisasterPacket& packet
    );

    bool receivePacket(
        DisasterPacket& packet
    );

    RoutingTable&
    getRoutingTable();

private:

    RoutingTable routingTable;

    uint8_t rxBuffer[256];

    void processIncomingPacket(
        DisasterPacket& packet,
        int rssi
    );

    void sendHeartbeat();
};