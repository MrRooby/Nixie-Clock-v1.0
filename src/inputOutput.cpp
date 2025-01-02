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

    for(int i = 0; i < sizeof(diods); i++)
    {
        pcf.pinMode(diods[i], OUTPUT);
        pcf.digitalWrite(diods[i], HIGH);
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
    if(digitalRead(SNOOZE_BUTTON) == LOW)
    {
        delay(100);
        if(digitalRead(SNOOZE_BUTTON) == LOW) { return true; }
    }
    return false;
}

bool InputOutput::isSwitchModeButtonPressed()
{    
    if(digitalRead(SWITCH_MODE_BUTTON) == LOW)
    {
        delay(100); // debouncing
        if(digitalRead(SWITCH_MODE_BUTTON) == LOW) { return true; }
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
        pcf.digitalWrite(diods[diodNumber], LOW); 
        for(int i = 0; i < sizeof(diods); i++)
        {
            if(i != diodNumber)
            {
                pcf.digitalWrite(diods[i], HIGH);
            }
        }
    }
    else        
    { 
        for(int i = 0; i < sizeof(diods); i++)
        {
            pcf.digitalWrite(diods[i], HIGH);
        }
    }
}

void InputOutput::turnOnLED(unsigned int diodNumber, bool choice)
{
    if (choice) { pcf.digitalWrite(diods[diodNumber], LOW); }
    else        { pcf.digitalWrite(diods[diodNumber], HIGH); }
}
