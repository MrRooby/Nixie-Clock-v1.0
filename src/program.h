#pragma once
#include "lamps.h"
#include "sensors.h"
#include "tinyRTC.h"
#include <utility>

class Program {
    private:
        Sensors sensors;
        Lamps lamps;
        TinyRTC tinyRTC;

    public:
        /*!
            * @brief Choose the option to display
            * @param option
            *        First option is time, second is date, third is temperature, fourth is humidity, fifth is CO2 level
        */
        void chooseOption(unsigned int option);

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