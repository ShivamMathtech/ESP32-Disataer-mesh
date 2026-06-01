#pragma once

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "../../include/system_state.h"

enum DisplayPage
{
    PAGE_STATUS = 0,

    PAGE_GPS,

    PAGE_SENSORS,

    PAGE_NETWORK,

    PAGE_ALERTS
};

class OLEDDisplay
{
public:

    bool begin();

    void update();

    void nextPage();

private:

    Adafruit_SSD1306 display =
        Adafruit_SSD1306(
            128,
            64,
            &Wire,
            -1
        );

    DisplayPage currentPage =
        PAGE_STATUS;

    uint32_t pageTimer = 0;

    void drawStatusPage();

    void drawGPSPage();

    void drawSensorPage();

    void drawNetworkPage();

    void drawAlertPage();
};