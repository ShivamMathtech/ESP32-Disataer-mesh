#include <Arduino.h>

#include "../include/config.h"
#include "../include/pins.h"
#include "../include/system_state.h"

SystemState systemState;

// Forward declarations

void initializeHardware();

void initializeTasks();

void printSystemBanner();

void initializeHardware()
{
    pinMode(
        STATUS_LED_PIN,
        OUTPUT
    );

    pinMode(
        SOS_BUTTON_PIN,
        INPUT_PULLUP
    );

    digitalWrite(
        STATUS_LED_PIN,
        LOW
    );
}

void printSystemBanner()
{
    Serial.println();
    Serial.println(
        "================================="
    );

    Serial.println(
        "AI Disaster Response Mesh Network"
    );

    Serial.println(
        "ESP32-S3 Rescue Node"
    );

    Serial.print(
        "Node ID: "
    );

    Serial.println(
        NODE_ID
    );

    Serial.println(
        "================================="
    );
}

void initializeTasks()
{
    /*
        Phase 8

        sensorTask
        gpsTask
        aiTask
        loraTask
        displayTask
        emergencyTask
    */
}

void setup()
{
    Serial.begin(115200);

    delay(1000);

    printSystemBanner();

    initializeHardware();

    initializeTasks();

    Serial.println(
        "System Ready"
    );
}

void loop()
{
    static uint32_t heartbeatTimer = 0;

    if(millis() - heartbeatTimer >
       HEARTBEAT_INTERVAL_MS)
    {
        digitalWrite(
            STATUS_LED_PIN,
            !digitalRead(
                STATUS_LED_PIN
            )
        );

        Serial.println(
            "[HEARTBEAT] Node Alive"
        );

        heartbeatTimer = millis();
    }

    systemState.sosPressed =
        !digitalRead(
            SOS_BUTTON_PIN
        );

    delay(10);
}