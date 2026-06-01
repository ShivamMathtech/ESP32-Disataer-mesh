#pragma once

#include <Arduino.h>

#define MAX_ROUTES 32

struct RouteEntry
{
    uint16_t nodeId;

    int8_t rssi;

    uint8_t hops;

    uint32_t lastSeen;
};

class RoutingTable
{
public:

    void begin();

    void updateNode(
        uint16_t nodeId,
        int8_t rssi,
        uint8_t hops
    );

    bool exists(
        uint16_t nodeId
    );

    RouteEntry* getRoute(
        uint16_t nodeId
    );

    void removeExpired(
        uint32_t timeoutMs
    );

    uint8_t size();

private:

    RouteEntry routes[MAX_ROUTES];

    uint8_t count = 0;
};