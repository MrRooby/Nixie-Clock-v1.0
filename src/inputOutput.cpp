#include "inputOutput.h"

void InputOutput::setupIO()
{
    setupButtons();
    setupBuzzer();
    setupDiods();
}

void InputOutput::setupButtons()
{
    pinMode(SNOOZE_BUTTON, INPUT_PULLUP);
    pinMode(SWITCH_MODE_BUTTON, INPUT_PULLUP);
}

void InputOutput::setupBuzzer()
{
    pinMode(BUZZER, OUTPUT);
    digitalWrite(BUZZER, LOW);
}

void InputOutput::setupDiods()
{
    pinMode(INBUILT_LED, OUTPUT);
    digitalWrite(INBUILT_LED, LOW);

    for(int i = 0; i < 4; i++)
    {
        pinMode(diods[i], OUTPUT);
        digitalWrite(diods[i], LOW);
    }
}

void InputOutput::buzzConstant(bool choice)
{
    if(choice)
    {
        digitalWrite(BUZZER, HIGH);
    }
    else
    {
        digitalWrite(BUZZER, LOW);
    }
}

void InputOutput::buzzForTime(unsigned int time)
{
    digitalWrite(BUZZER, HIGH);
    delay(time);
    digitalWrite(BUZZER, LOW);
}

void InputOutput::buzzPullse(unsigned int timeOn, unsigned int timeOff, bool choice)
{
    if(choice)
    {
        digitalWrite(BUZZER, HIGH);
        delay(timeOn);
        digitalWrite(BUZZER, LOW);
        delay(timeOff);
    }
    else
    {
        digitalWrite(BUZZER, LOW);
    }
}

bool InputOutput::isSnoozeButtonPressed()
{
    static bool buttonWasPressed = false;

    if(digitalRead(SNOOZE_BUTTON) == LOW)
    {
        if(!buttonWasPressed)
        {
            delay(100); // debouncing
            if(digitalRead(SNOOZE_BUTTON) == LOW)
            {
                buttonWasPressed = true;
                return true;
            }
        }
    }
    else
    {
        buttonWasPressed = false;
    }
    return false;
}

bool InputOutput::isSwitchModeButtonPressed()
{
    static bool buttonWasPressed = false;

    if(digitalRead(SWITCH_MODE_BUTTON) == LOW)
    {
        if(!buttonWasPressed)
        {
            delay(100); // debouncing
            if(digitalRead(SWITCH_MODE_BUTTON) == LOW)
            {
                buttonWasPressed = true;
                return true;
            }
        }
    }
    else
    {
        buttonWasPressed = false;
    }
    return false;
}

void InputOutput::turnOnInbuiltLED(bool choice)
{
    if (choice) { digitalWrite(INBUILT_LED, HIGH); }
    else        { digitalWrite(INBUILT_LED, LOW); }
}

void InputOutput::turnOnSingleLED(unsigned int diodNumber, bool choice)
{
    if (choice) 
    { 
        digitalWrite(diods[diodNumber], HIGH); 
        for(int i = 0; i < sizeof(diods); i++)
        {
            if(i != diodNumber)
            {
                digitalWrite(diods[i], LOW);
            }
        }
    }
    else        
    { 
        for(int i = 0; i < 4; i++)
        {
            digitalWrite(diods[i], LOW);
        }
    }
}

void InputOutput::turnOnLED(unsigned int diodNumber, bool choice)
{
    if (choice) { digitalWrite(diods[diodNumber], HIGH); }
    else        { digitalWrite(diods[diodNumber], LOW); }
}
