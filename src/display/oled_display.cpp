#include "oled_display.h"

#include <Wire.h>

#include "../../include/config.h"
#include "../../include/pins.h"

extern SystemState systemState;

bool OLEDDisplay::begin()
{
    Wire.begin(
        OLED_SDA_PIN,
        OLED_SCL_PIN
    );

    if(
        !display.begin(
            SSD1306_SWITCHCAPVCC,
            0x3C
        )
    )
    {
        return false;
    }

    display.clearDisplay();

    display.setTextSize(1);

    display.setTextColor(
        SSD1306_WHITE
    );

    display.display();

    return true;
}

void OLEDDisplay::nextPage()
{
    currentPage =
    (DisplayPage)
    (
        (currentPage + 1) % 5
    );
}

void OLEDDisplay::update()
{
    if(
        millis() -
        pageTimer >
        4000
    )
    {
        nextPage();

        pageTimer =
        millis();
    }

    display.clearDisplay();

    switch(currentPage)
    {
        case PAGE_STATUS:
            drawStatusPage();
            break;

        case PAGE_GPS:
            drawGPSPage();
            break;

        case PAGE_SENSORS:
            drawSensorPage();
            break;

        case PAGE_NETWORK:
            drawNetworkPage();
            break;

        case PAGE_ALERTS:
            drawAlertPage();
            break;
    }

    display.display();
}