#include "program.h"

void Program::displayOption(unsigned int option)
{
    switch(option)
    {
        case 0:
            displayTime();
            inputOutput.turnOnLED(0, true);
            inputOutput.turnOnLED(1, false);
            inputOutput.turnOnLED(2, false);
            inputOutput.turnOnLED(3, false);
            // Serial.println("Time");
            break;
        case 1:
            displayDate();
            inputOutput.turnOnLED(0, false);
            inputOutput.turnOnLED(1, true);
            inputOutput.turnOnLED(2, false);
            inputOutput.turnOnLED(3, false);
            // Serial.println("Date");
            break;
        case 2:
            displayTemperature();
            inputOutput.turnOnLED(0, false);
            inputOutput.turnOnLED(1, false);
            inputOutput.turnOnLED(2, true);
            inputOutput.turnOnLED(3, false);
            // Serial.println("Temperature");
            break;
        case 3:
            displayHumidity();
            inputOutput.turnOnLED(0, false);
            inputOutput.turnOnLED(1, false);
            inputOutput.turnOnLED(2, false);
            inputOutput.turnOnLED(3, true);
            // Serial.println("Humidity");
            break;
        default:
            displayTime();
            inputOutput.turnOnLED(0, true);
            inputOutput.turnOnLED(1, false);
            inputOutput.turnOnLED(2, false);
            inputOutput.turnOnLED(3, false);
            // Serial.println("Time");
            break;
    }
}

void Program::displayTime()
{
    lamps.displayOnAllLamps(std::get<0>(timeMenager.dateTimeForLamps('t')), 
                            std::get<1>(timeMenager.dateTimeForLamps('t')),     
                            std::get<2>(timeMenager.dateTimeForLamps('t')), 
                            std::get<3>(timeMenager.dateTimeForLamps('t')));
}

void Program::displayDate()
{
    lamps.displayOnAllLamps(std::get<0>(timeMenager.dateTimeForLamps('d')), 
                            std::get<1>(timeMenager.dateTimeForLamps('d')), 
                            std::get<2>(timeMenager.dateTimeForLamps('d')), 
                            std::get<3>(timeMenager.dateTimeForLamps('d')));
}

void Program::displayTemperature()
{
    lamps.displayOnTwoRightLamps(sensors.getTemperature().first, 
                                 sensors.getTemperature().second);
}

void Program::displayHumidity()
{
    lamps.displayOnTwoRightLamps(sensors.getHumidity().first, 
                                 sensors.getHumidity().second);
}

void Program::displayCO2Level()
{
    //TODO: Implement this function
}