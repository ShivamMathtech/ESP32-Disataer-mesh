#pragma once

#include <Arduino.h>

class GasSensor
{
public:

    explicit GasSensor(
        uint8_t pin
    );

    void begin();

    uint16_t readRaw();

    float readVoltage();

    bool hazardous();

private:

    uint8_t adcPin;
};