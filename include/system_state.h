#pragma once

struct SystemState
{
    float latitude = 0.0f;

    float longitude = 0.0f;

    float temperature = 0.0f;

    float humidity = 0.0f;

    float gasLevel = 0.0f;

    float batteryVoltage = 0.0f;

    bool gpsLock = false;

    bool survivorDetected = false;

    bool sosPressed = false;

    uint8_t aiConfidence = 0;

    bool loraConnected = false;

    bool wifiConnected = false;
};

extern SystemState systemState;