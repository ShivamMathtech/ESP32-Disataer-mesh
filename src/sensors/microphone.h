#pragma once

#include <Arduino.h>
#include <driver/i2s.h>

#define AUDIO_BUFFER_SIZE 1024

class Microphone
{
public:

    bool begin();

    uint32_t capture(
        int16_t* buffer
    );

    float rms(
        int16_t* buffer,
        uint32_t samples
    );

private:

    static constexpr i2s_port_t PORT =
    I2S_NUM_0;
};