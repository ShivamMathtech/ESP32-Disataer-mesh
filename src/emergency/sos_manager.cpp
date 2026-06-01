#include "sos_manager.h"

void SOSManager::begin(
    uint8_t pin)
{
    buttonPin = pin;

    pinMode(
        buttonPin,
        INPUT_PULLUP
    );
}

void SOSManager::update()
{
    bool pressed =
    !digitalRead(
        buttonPin
    );

    if(
        pressed &&
        millis() -
        debounceTimer >
        250
    )
    {
        triggered = true;

        state =
        SOS_TRIGGERED;

        debounceTimer =
        millis();
    }
}

bool SOSManager::isTriggered()
{
    return triggered;
}

SOSState SOSManager::getState()
{
    return state;
}

void SOSManager::reset()
{
    triggered = false;

    state = SOS_IDLE;
}