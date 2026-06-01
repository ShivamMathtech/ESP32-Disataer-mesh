#include "routing.h"

void RoutingTable::begin()
{
    count = 0;
}

bool RoutingTable::exists(
    uint16_t nodeId)
{
    for(uint8_t i=0;i<count;i++)
    {
        if(routes[i].nodeId == nodeId)
            return true;
    }

    return false;
}

void RoutingTable::updateNode(
    uint16_t nodeId,
    int8_t rssi,
    uint8_t hops)
{
    for(uint8_t i=0;i<count;i++)
    {
        if(routes[i].nodeId == nodeId)
        {
            routes[i].rssi = rssi;
            routes[i].hops = hops;
            routes[i].lastSeen = millis();

            return;
        }
    }

    if(count >= MAX_ROUTES)
        return;

    routes[count].nodeId = nodeId;
    routes[count].rssi = rssi;
    routes[count].hops = hops;
    routes[count].lastSeen = millis();

    count++;
}

RouteEntry* RoutingTable::getRoute(
    uint16_t nodeId)
{
    for(uint8_t i=0;i<count;i++)
    {
        if(routes[i].nodeId == nodeId)
            return &routes[i];
    }

    return nullptr;
}

void RoutingTable::removeExpired(
    uint32_t timeoutMs)
{
    uint8_t i = 0;

    while(i < count)
    {
        if(millis() - routes[i].lastSeen >
           timeoutMs)
        {
            for(uint8_t j=i;
                j<count-1;
                j++)
            {
                routes[j] =
                routes[j+1];
            }

            count--;
        }
        else
        {
            i++;
        }
    }
}

uint8_t RoutingTable::size()
{
    return count;
}