#include "alarm_manager.h"

void AlarmManager::begin(
    uint8_t buzzer,
    uint8_t led)
{
    buzzerPin = buzzer;

    ledPin = led;

    pinMode(
        buzzerPin,
        OUTPUT
    );

    pinMode(
        ledPin,
        OUTPUT
    );
}

void AlarmManager::trigger(
    AlarmLevel level)
{
    currentLevel =
    level;
}

AlarmLevel AlarmManager::level()
{
    return currentLevel;
}

void AlarmManager::stop()
{
    currentLevel =
    ALARM_NONE;

    digitalWrite(
        ledPin,
        LOW
    );

    noTone(
        buzzerPin
    );
}

void AlarmManager::update()
{
    switch(currentLevel)
    {
        case ALARM_NONE:

            digitalWrite(
                ledPin,
                LOW
            );

            noTone(
                buzzerPin
            );

            break;

        case ALARM_INFO:

            if(
                millis() -
                lastBlink > 1000
            )
            {
                digitalWrite(
                    ledPin,
                    !digitalRead(
                        ledPin
                    )
                );

                lastBlink =
                millis();
            }

            break;

        case ALARM_WARNING:

            if(
                millis() -
                lastBlink > 500
            )
            {
                digitalWrite(
                    ledPin,
                    !digitalRead(
                        ledPin
                    )
                );

                tone(
                    buzzerPin,
                    1000,
                    100
                );

                lastBlink =
                millis();
            }

            break;

        case ALARM_CRITICAL:

            if(
                millis() -
                lastBlink > 200
            )
            {
                digitalWrite(
                    ledPin,
                    !digitalRead(
                        ledPin
                    )
                );

                tone(
                    buzzerPin,
                    2000
                );

                lastBlink =
                millis();
            }

            break;
    }
}