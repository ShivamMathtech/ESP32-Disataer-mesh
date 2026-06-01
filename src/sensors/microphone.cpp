#include "microphone.h"
#include "../../include/pins.h"

#include <math.h>

bool Microphone::begin()
{
    i2s_config_t config =
    {
        .mode =
        (i2s_mode_t)
        (
            I2S_MODE_MASTER |
            I2S_MODE_RX
        ),

        .sample_rate = 16000,

        .bits_per_sample =
        I2S_BITS_PER_SAMPLE_32BIT,

        .channel_format =
        I2S_CHANNEL_FMT_ONLY_LEFT,

        .communication_format =
        I2S_COMM_FORMAT_STAND_I2S,

        .intr_alloc_flags = 0,

        .dma_buf_count = 8,

        .dma_buf_len = 256,

        .use_apll = false,

        .tx_desc_auto_clear = false,

        .fixed_mclk = 0
    };

    i2s_pin_config_t pins =
    {
        .bck_io_num =
        I2S_BCLK_PIN,

        .ws_io_num =
        I2S_WS_PIN,

        .data_out_num =
        I2S_PIN_NO_CHANGE,

        .data_in_num =
        I2S_DIN_PIN
    };

    i2s_driver_install(
        PORT,
        &config,
        0,
        nullptr
    );

    i2s_set_pin(
        PORT,
        &pins
    );

    return true;
}

uint32_t Microphone::capture(
    int16_t* buffer)
{
    size_t bytesRead = 0;

    i2s_read(
        PORT,
        buffer,
        AUDIO_BUFFER_SIZE *
        sizeof(int16_t),
        &bytesRead,
        portMAX_DELAY
    );

    return bytesRead /
           sizeof(int16_t);
}

float Microphone::rms(
    int16_t* buffer,
    uint32_t samples)
{
    double sum = 0;

    for(uint32_t i=0;
        i<samples;
        i++)
    {
        sum +=
        (double)buffer[i] *
        buffer[i];
    }

    return sqrt(
        sum / samples
    );
}