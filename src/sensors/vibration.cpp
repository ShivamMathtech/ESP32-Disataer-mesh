#include "vibration.h"

VibrationSensor::VibrationSensor(
    uint8_t pin)
{
    sensorPin = pin;
}

void VibrationSensor::begin()
{
    pinMode(
        sensorPin,
        INPUT_PULLUP
    );
}

bool VibrationSensor::detected()
{
    return digitalRead(
        sensorPin
    ) == LOW;
}