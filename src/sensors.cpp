#include "sensors.h"

void Sensors::setupSensors(){
    dht.begin();
    MQ9.init();
}

std::pair<unsigned int, unsigned int> Sensors::getTemperature(){
    float temperature = dht.readTemperature();
    unsigned int tempTens = (unsigned int)(temperature / 10);
    if(tempTens > 9){
        tempTens = 9;
    }
    unsigned int tempOnes = (int)temperature % 10;

    return std::pair<unsigned int, unsigned int>(tempTens, tempOnes);
} 

std::pair<unsigned int, unsigned int> Sensors::getHumidity(){
    float humidity = dht.readHumidity();
    unsigned int humTens = (unsigned int)(humidity / 10);
    if(humTens > 9){
        humTens = 9;
    }
    unsigned int humOnes = (int)humidity % 10;
    
    return std::pair<unsigned int, unsigned int>(humTens, humOnes);
}