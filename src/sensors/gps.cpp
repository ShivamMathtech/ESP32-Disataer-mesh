#include "gps.h"

bool GPSModule::begin(
    HardwareSerial& serial)
{
    gpsSerial = &serial;

    return true;
}

void GPSModule::update()
{
    while(gpsSerial->available())
    {
        gps.encode(
            gpsSerial->read()
        );
    }
}

bool GPSModule::hasFix()
{
    return gps.location.isValid();
}

double GPSModule::latitude()
{
    return gps.location.lat();
}

double GPSModule::longitude()
{
    return gps.location.lng();
}

double GPSModule::altitude()
{
    return gps.altitude.meters();
}

uint32_t GPSModule::satellites()
{
    return gps.satellites.value();
}