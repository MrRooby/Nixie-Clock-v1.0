#include "sensors.h"

void setupSensors(){
    dht.begin();
    MQ9.init();
}

std::pair<uint_least8_t, uint_least8_t> getTemperature(){
    float temperature = dht.readTemperature();
    uint_least8_t tempTens = (uint_least8_t)(temperature / 10);
    if(tempTens > 9){
        tempTens = 9;
    }
    uint_least8_t tempOnes = (int)temperature % 10;

    return std::pair<uint_least8_t, uint_least8_t>(tempTens, tempOnes);
} 

std::pair<uint_least8_t, uint_least8_t> getHumidity(){
    float humidity = dht.readHumidity();
    uint_least8_t humTens = (uint_least8_t)(humidity / 10);
    if(humTens > 9){
        humTens = 9;
    }
    uint_least8_t humOnes = (int)humidity % 10;
    
    return std::pair<uint_least8_t, uint_least8_t>(humTens, humOnes);
}