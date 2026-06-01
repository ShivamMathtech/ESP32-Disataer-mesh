#pragma once

#include <Arduino.h>

enum SOSState
{
    SOS_IDLE = 0,

    SOS_TRIGGERED,

    SOS_BROADCASTING
};

class SOSManager
{
public:

    void begin(uint8_t buttonPin);

    void update();

    bool isTriggered();

    SOSState getState();

    void reset();

private:

    uint8_t buttonPin;

    SOSState state =
    SOS_IDLE;

    bool triggered =
    false;

    uint32_t debounceTimer =
    0;
};