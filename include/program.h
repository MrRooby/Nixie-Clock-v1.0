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
        void displayOption(unsigned int option);

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
        void displayTemperature();

        /*!
            * @brief Display the humidity on two right Nixie tubes
        */
        void displayHumidity();
        
        //TODO: Implement this function
        void displayCO2Level();
};