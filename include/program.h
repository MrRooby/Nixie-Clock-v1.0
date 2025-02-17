#pragma once
#include "lamps.h"
#include "sensors.h"
#include "timeMenager.h"
#include <utility>

class Program {
    private:
        Sensors sensors;
        Lamps lamps;
        TimeMenager timeMenager;
        InputOutput inputOutput;

    public:
        /*!
            * @brief Choose the option to display
            * @param option
            *        First option is time, second is date, third is temperature, fourth is humidity, fifth is CO2 level
        */
        void displayOption(unsigned int option, Sensors sensors);

        /*!
            * @brief Display the time on the Nixie tubes
        */
        void displayTime();
        
        /*!
            * @brief Display the date on the Nixie tubes
        */
        void displayDate();
        
        /*!
            * @brief Display the temperature on two right Nixie tubes
        */
        void displayTemperature(Sensors sensors);

        /*!
            * @brief Display the humidity on two right Nixie tubes
        */
        void displayHumidity(Sensors sensors);
        
        /*!
            * @brief Keep watch on the gas level and trigger
                     the alarm if the gas level is above the danger level
                     (buzzing sound and blinking LEDs)
        */
        void runGasLevelAlarm();
};