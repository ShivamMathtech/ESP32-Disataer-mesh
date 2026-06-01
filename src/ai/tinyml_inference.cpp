#include "tinyml_inference.h"

bool TinyMLInference::begin()
{
    return true;
}

AIClass TinyMLInference::classify(
    float* features)
{
    float score = 0;

    for(int i=0;
        i<64;
        i++)
    {
        score += features[i];
    }

    score /= 64.0f;

    if(score < 0.05f)
    {
        lastConfidence = 90;
        return AI_NOISE;
    }

    if(score < 0.15f)
    {
        lastConfidence = 82;
        return AI_HUMAN_VOICE;
    }

    if(score < 0.30f)
    {
        lastConfidence = 87;
        return AI_CRY_FOR_HELP;
    }

    lastConfidence = 95;

    return AI_SURVIVOR_DETECTED;
}

uint8_t TinyMLInference::confidence()
{
    return lastConfidence;
}