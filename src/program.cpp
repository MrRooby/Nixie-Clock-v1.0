#include "program.h"

void Program::displayOption(unsigned int option, Sensors sensors)
{
    switch(option)
    {
        case 0:
            displayTime();
            inputOutput.turnOnLED(0, true);
            inputOutput.turnOnLED(1, false);
            inputOutput.turnOnLED(2, false);
            inputOutput.turnOnLED(3, false);
            // Serial.print("Time: ");
            // Serial.print(std::get<0>(timeMenager.dateTimeForLamps('t')));
            // Serial.print(std::get<1>(timeMenager.dateTimeForLamps('t')));
            // Serial.print(":");
            // Serial.print(std::get<2>(timeMenager.dateTimeForLamps('t')));
            // Serial.println(std::get<3>(timeMenager.dateTimeForLamps('t')));
            
            break;
        case 1:
            displayDate();
            inputOutput.turnOnLED(0, false);
            inputOutput.turnOnLED(1, true);
            inputOutput.turnOnLED(2, false);
            inputOutput.turnOnLED(3, false);
            // Serial.println("Date: ");
            // Serial.print(std::get<0>(timeMenager.dateTimeForLamps('d')));
            // Serial.print(std::get<1>(timeMenager.dateTimeForLamps('d')));
            // Serial.print("-");
            // Serial.print(std::get<2>(timeMenager.dateTimeForLamps('m')));
            // Serial.println(std::get<3>(timeMenager.dateTimeForLamps('m')));
            break;
        case 2:
            displayTemperature(sensors);
            inputOutput.turnOnLED(0, false);
            inputOutput.turnOnLED(1, false);
            inputOutput.turnOnLED(2, true);
            inputOutput.turnOnLED(3, false);
            // Serial.print("Temperature: ");
            // Serial.print(sensors.getTemperature().first);
            // Serial.println(sensors.getTemperature().second);
            break;
        case 3:
            displayHumidity(sensors);
            inputOutput.turnOnLED(0, false);
            inputOutput.turnOnLED(1, false);
            inputOutput.turnOnLED(2, false);
            inputOutput.turnOnLED(3, true);
            // Serial.print("Humidity: ");
            // Serial.print(sensors.getHumidity().first);
            // Serial.println(sensors.getHumidity().second);
            break;
        default:
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

void Program::displayTemperature(Sensors sensors)
{
    auto temperature = sensors.getTemperature();
    auto humidity = sensors.getHumidity();

    Serial.print("Temperature: ");
    Serial.print(temperature.first);
    Serial.print(temperature.second);
    Serial.println(" *C");

    Serial.print("Humidity: ");
    Serial.print(humidity.first);
    Serial.print(humidity.second);
    Serial.println(" %");

    lamps.displayOnTwoRightLamps(sensors.getTemperature().first, 
                                 sensors.getTemperature().second);
}

void Program::displayHumidity(Sensors sensors)
{
    lamps.displayOnTwoRightLamps(sensors.getHumidity().first, 
                                 sensors.getHumidity().second);
}

void Program::runGasLevelAlarm()
{
    if(sensors.isGasLevelDangerous())
    {
        inputOutput.buzzConstant(true);
        inputOutput.blinkLEDs(true, 500);
    }
    else
    {
        inputOutput.buzzConstant(false);
        inputOutput.blinkLEDs(false, 500);
    }
}