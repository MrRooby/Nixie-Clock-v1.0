#include "program.h"

void Program::chooseOption(unsigned int option)
{
    switch(option)
    {
        case 0:
            displayTime();
            break;
        case 1:
            displayDate();
            break;
        case 2:
            displayTemperature();
            break;
        case 3:
            displayHumidity();
            break;
        case 4:
            displayCO2Level();
            break;
    }
}

void Program::displayTime()
{
    lamps.displayOnAllLamps(std::get<0>(tinyRTC.dateTimeForLamps('t')), std::get<1>(tinyRTC.dateTimeForLamps('t')), std::get<2>(tinyRTC.dateTimeForLamps('t')), std::get<3>(tinyRTC.dateTimeForLamps('t')));
}

void Program::displayDate()
{
    lamps.displayOnAllLamps(std::get<0>(tinyRTC.dateTimeForLamps('d')), std::get<1>(tinyRTC.dateTimeForLamps('d')), std::get<2>(tinyRTC.dateTimeForLamps('d')), std::get<3>(tinyRTC.dateTimeForLamps('d')));
}

void Program::displayTemperature()
{
    lamps.displayOnTwoRightLamps(sensors.getTemperature().first, sensors.getTemperature().second);
}

void Program::displayHumidity()
{
    lamps.displayOnTwoRightLamps(sensors.getHumidity().first, sensors.getHumidity().second);
}

void Program::displayCO2Level()
{
    //TODO: Implement this function
}