#pragma once
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <cstring>
#include <tuple>

#include "inputOutput.h"

class TimeMenager {
    private:
        tmElements_t tm;
        InputOutput inputOutput;

        unsigned int alarmHour;
        unsigned int alarmMinute;

        bool alarmArmed = false;
    public:
        /*! 
            @brief  Set the time for the alarm
            @param hour hour
            @param minute minute
        */
        void setupAlarm(unsigned int hour, unsigned int minute);
        
        /*! 
            @brief  Arm or disarm
            @param choice true for arm, false for disarm
        */
        void armAlarm(bool choice);

        /*! 
            @brief Run the alarm clock
        */
        void runAlarmClock();
        
        /*!
            @brief  Get the current hour
            @param choice 't' for time, 'd' for date
            @return first digit of hour/day, second digit of hour/day, first digit of minute/month, second digit of minute/month
        */
        std::tuple<unsigned int, unsigned int, unsigned int, unsigned int> dateTimeForLamps(char choice);

        /*!
            @brief Print the current time in the serial monitor
        */
        void printTimeInSerial();
};