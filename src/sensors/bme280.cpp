#include "bme280.h"

bool BME280Sensor::begin()
{
    return bme.begin(0x76);
}

float BME280Sensor::temperature()
{
    return bme.readTemperature();
}

float BME280Sensor::humidity()
{
    return bme.readHumidity();
}

float BME280Sensor::pressure()
{
    return bme.readPressure() / 100.0f;
}