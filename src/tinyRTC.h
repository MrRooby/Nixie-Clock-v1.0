#pragma once
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <cstring>
#include <tuple>


class TinyRTC {
    private:
    
    public:
        tmElements_t tm;
        /*!
            @brief  Get the current hour
            @param choice 't' for time, 'd' for date
            @return first digit of hour/day, second digit of hour/day, first digit of minute/month, second digit of minute/month
        */
        std::tuple<unsigned int, unsigned int, unsigned int, unsigned int> dateTimeForLamps(char choice);
};