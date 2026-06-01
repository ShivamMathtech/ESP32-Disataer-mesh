#pragma once

#include <Arduino.h>

enum AlarmLevel
{
    ALARM_NONE = 0,

    ALARM_INFO,

    ALARM_WARNING,

    ALARM_CRITICAL
};

class AlarmManager
{
public:

    void begin(
        uint8_t buzzerPin,
        uint8_t ledPin
    );

    void update();

    void trigger(
        AlarmLevel level
    );

    void stop();

    AlarmLevel level();

private:

    uint8_t buzzerPin;

    uint8_t ledPin;

    AlarmLevel currentLevel =
    ALARM_NONE;

    uint32_t lastBlink =
    0;
};