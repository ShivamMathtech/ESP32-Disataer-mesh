#pragma once

#include <Arduino.h>

enum PacketType
{
    PACKET_HEARTBEAT = 0,

    PACKET_SENSOR_DATA,

    PACKET_SURVIVOR_ALERT,

    PACKET_SOS_ALERT,

    PACKET_ROUTE_UPDATE
};

struct DisasterPacket
{
    uint16_t sourceNode;

    uint16_t destinationNode;

    PacketType type;

    float latitude;

    float longitude;

    float temperature;

    float humidity;

    float gasLevel;

    float batteryVoltage;

    bool survivorDetected;

    bool sosPressed;

    uint8_t aiConfidence;

    uint8_t hopCount;

    uint32_t timestamp;
};