#include "buttons.h"

void Buttons::setupButtons()
{
    pinMode(SNOOZE_BUTTON, INPUT);
    pinMode(SWITCH_MODE_BUTTON, INPUT);
}

bool Buttons::isSnoozeButtonPressed()
{
    if(digitalRead(SNOOZE_BUTTON) == HIGH)
    {
        delay(100);
        if(digitalRead(SNOOZE_BUTTON) == HIGH)
        {
            return true;
        }
    }
    return false;
}

bool Buttons::isSwitchModeButtonPressed()
{    
    if(digitalRead(SWITCH_MODE_BUTTON) == HIGH)
    {
        delay(100);
        if(digitalRead(SWITCH_MODE_BUTTON) == HIGH)
        {
            return true;
        }
    }
    return false;
}
