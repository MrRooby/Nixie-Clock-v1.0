#include "timeMenager.h"

void TimeMenager::setupAlarm(unsigned int hour, unsigned int minute)
{
    alarmHour = hour;
    alarmMinute = minute;
    Serial.print("Alarm set for: ");
    Serial.print(alarmHour);
    Serial.print(":");
    Serial.println(alarmMinute);
}

void TimeMenager::armAlarm(bool choice) 
{ 
    alarmArmed = choice; 
    if(alarmArmed)
    {
        Serial.println("Alarm armed");
    }
    else
    {
        Serial.println("Alarm disarmed");
    }
}

void TimeMenager::runAlarmClock()
{
    if (alarmArmed 
        && RTC.read(tm) 
        && tm.Hour == alarmHour 
        && tm.Minute == alarmMinute )
    {
        inputOutput.buzzConstant(true);
        if(inputOutput.isSnoozeButtonPressed())
        {
            alarmArmed = false;
            inputOutput.buzzConstant(false);
        }
    }

    Serial.print("Time: ");
    Serial.print(alarmHour);
    Serial.print(":");
    Serial.println(alarmMinute);
}

std::tuple<unsigned int, unsigned int, unsigned int, unsigned int> TimeMenager::dateTimeForLamps(char choice)
{
    if(RTC.read(tm))
    {
        if (choice == 't')
        {
            unsigned int hrTens = tm.Hour / 10;
            unsigned int hrOnes = tm.Hour % 10;
            unsigned int minTens = tm.Minute / 10;
            unsigned int minOnes = tm.Minute % 10;

            return std::tuple<unsigned int, unsigned int, unsigned int, unsigned int>(hrTens, hrOnes, minTens, minOnes);
        }
        else if (choice == 'd')
        {
            unsigned int dayTens = tm.Day / 10;
            unsigned int dayOnes = tm.Day % 10;
            unsigned int monthTens = tm.Month / 10;
            unsigned int monthOnes = tm.Month % 10;

            return std::tuple<unsigned int, unsigned int, unsigned int, unsigned int>(dayTens, dayOnes, monthTens, monthOnes);
        }
        else
        {
            return std::tuple<unsigned int, unsigned int, unsigned int, unsigned int>(0, 0, 0, 0);
        }
    }
}

void TimeMenager::printTimeInSerial()
{
    if(RTC.read(tm))
    {
        Serial.print("Time: ");
        Serial.print(tm.Hour);
        Serial.print(":");
        Serial.print(tm.Minute);
        Serial.print(":");
        Serial.print(tm.Second);
        Serial.print(" Date: ");
        Serial.print(tm.Day);
        Serial.print("/");
        Serial.print(tm.Month);
        Serial.print("/");
        Serial.println(tm.Year);
    }
}
