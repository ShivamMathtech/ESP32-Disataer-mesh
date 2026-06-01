#pragma once

#include <Arduino.h>

enum AIClass
{
    AI_NOISE = 0,

    AI_HUMAN_VOICE,

    AI_CRY_FOR_HELP,

    AI_SURVIVOR_DETECTED
};

class TinyMLInference
{
public:

    bool begin();

    AIClass classify(
        float* features
    );

    uint8_t confidence();

private:

    uint8_t lastConfidence = 0;
};