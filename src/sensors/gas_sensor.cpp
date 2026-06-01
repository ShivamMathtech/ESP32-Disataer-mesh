#include "gas_sensor.h"

GasSensor::GasSensor(
    uint8_t pin)
{
    adcPin = pin;
}

void GasSensor::begin()
{
    pinMode(
        adcPin,
        INPUT
    );
}

uint16_t GasSensor::readRaw()
{
    return analogRead(
        adcPin
    );
}

float GasSensor::readVoltage()
{
    return (
        readRaw() *
        3.3f
    ) / 4095.0f;
}

bool GasSensor::hazardous()
{
    return readRaw() > 2200;
}