#pragma once

#include <TinyGPSPlus.h>
#include <HardwareSerial.h>

class GPSModule
{
public:

    bool begin(
        HardwareSerial& serial
    );

    void update();

    bool hasFix();

    double latitude();

    double longitude();

    double altitude();

    uint32_t satellites();

private:

    TinyGPSPlus gps;

    HardwareSerial* gpsSerial;
};