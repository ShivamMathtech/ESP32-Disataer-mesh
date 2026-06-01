#include "feature_extraction.h"

void FeatureExtractor::extract(
    int16_t* audioBuffer,
    uint32_t samples,
    float* features)
{
    uint32_t blockSize =
    samples / FEATURE_SIZE;

    for(uint32_t i=0;
        i<FEATURE_SIZE;
        i++)
    {
        uint64_t energy = 0;

        for(uint32_t j=0;
            j<blockSize;
            j++)
        {
            uint32_t idx =
            i * blockSize + j;

            energy += abs(
                audioBuffer[idx]
            );
        }

        features[i] =
        (float)energy /
        blockSize /
        32768.0f;
    }
}