#include "lora_mesh.h"

bool LoRaMesh::begin()
{
    SPI.begin();

    LoRa.setPins(
        LORA_CS_PIN,
        LORA_RST_PIN,
        LORA_IRQ_PIN
    );

    if(!LoRa.begin(
        LORA_FREQUENCY))
    {
        Serial.println(
            "LoRa Init Failed"
        );

        return false;
    }

    LoRa.setSpreadingFactor(12);

    LoRa.setSignalBandwidth(
        125E3
    );

    LoRa.setCodingRate4(5);

    LoRa.enableCrc();

    routingTable.begin();

    Serial.println(
        "LoRa Started"
    );

    return true;
}

bool LoRaMesh::sendPacket(
    DisasterPacket& packet)
{
    uint8_t buffer[256];

    uint16_t size =
        PacketEncoder::encode(
            packet,
            buffer
        );

    LoRa.beginPacket();

    LoRa.write(
        buffer,
        size
    );

    LoRa.endPacket();

    return true;
}

bool LoRaMesh::receivePacket(
    DisasterPacket& packet)
{
    int packetSize =
        LoRa.parsePacket();

    if(packetSize <= 0)
        return false;

    uint16_t index = 0;

    while(LoRa.available())
    {
        rxBuffer[index++] =
        LoRa.read();
    }

    return PacketEncoder::decode(
        rxBuffer,
        index,
        packet
    );
}

void LoRaMesh::processIncomingPacket(
    DisasterPacket& packet,
    int rssi)
{
    routingTable.updateNode(
        packet.sourceNode,
        rssi,
        packet.hopCount
    );

    switch(packet.type)
    {
        case PACKET_HEARTBEAT:

            Serial.printf(
                "[NODE %u ONLINE]\n",
                packet.sourceNode
            );

            break;

        case PACKET_SENSOR_DATA:

            Serial.printf(
                "[SENSOR DATA] %u\n",
                packet.sourceNode
            );

            break;

        case PACKET_SURVIVOR_ALERT:

            Serial.printf(
                "[SURVIVOR ALERT] %u\n",
                packet.sourceNode
            );

            break;

        case PACKET_SOS_ALERT:

            Serial.printf(
                "[SOS ALERT] %u\n",
                packet.sourceNode
            );

            break;

        default:
            break;
    }
}

void LoRaMesh::sendHeartbeat()
{
    DisasterPacket packet;

    memset(
        &packet,
        0,
        sizeof(packet)
    );

    packet.sourceNode =
    NODE_ID;

    packet.destinationNode =
    GATEWAY_NODE_ID;

    packet.type =
    PACKET_HEARTBEAT;

    packet.timestamp =
    millis();

    packet.hopCount = 0;

    sendPacket(packet);
}

void LoRaMesh::update()
{
    static uint32_t heartbeatTimer = 0;

    if(millis() - heartbeatTimer >
       HEARTBEAT_INTERVAL_MS)
    {
        sendHeartbeat();

        heartbeatTimer =
        millis();
    }

    DisasterPacket packet;

    if(receivePacket(packet))
    {
        processIncomingPacket(
            packet,
            LoRa.packetRssi()
        );
    }

    routingTable.removeExpired(
        30000
    );
}

RoutingTable&
LoRaMesh::getRoutingTable()
{
    return routingTable;
}