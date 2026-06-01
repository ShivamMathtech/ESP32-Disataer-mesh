#pragma once

#include <Arduino.h>

#define FEATURE_SIZE 64

class FeatureExtractor
{
public:

    void extract(
        int16_t* audioBuffer,
        uint32_t samples,
        float* features
    );
};