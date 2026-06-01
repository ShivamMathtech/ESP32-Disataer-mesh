#pragma once

#include <Adafruit_BME280.h>

class BME280Sensor
{
public:

    bool begin();

    float temperature();

    float humidity();

    float pressure();

private:

    Adafruit_BME280 bme;
};