#include "tinyRTC.h"

std::tuple<unsigned int, unsigned int, unsigned int, unsigned int> TinyRTC::dateTimeForLamps(char choice)
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