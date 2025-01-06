#include "sensors.h"

void Sensors::setupSensors(){
    dht.begin();
}

std::pair<unsigned int, unsigned int> Sensors::getTemperature()
{
    unsigned long currentMillis = millis();

    if (currentMillis - lastTempReadMillis < 1000) {
        return std::make_pair(cachedTempTens, cachedTempOnes);
    }

    float temperature = dht.readTemperature();
    unsigned int tempTens = (unsigned int)(temperature / 10);
    if (tempTens > 9) { tempTens = 9; }
    unsigned int tempOnes = (int)temperature % 10;

    cachedTempTens = tempTens;
    cachedTempOnes = tempOnes;
    lastTempReadMillis = currentMillis;

    return std::make_pair(tempTens, tempOnes);
} 

std::pair<unsigned int, unsigned int> Sensors::getHumidity()
{
    unsigned long currentMillis = millis();
    if (currentMillis - lastHumidityReadMillis < 1000) {
        return std::make_pair(cachedHumTens, cachedHumOnes);
    }

    float humidity = dht.readHumidity();
    unsigned int humTens = (unsigned int)(humidity / 10);
    if (humTens > 9) { humTens = 9; }
    unsigned int humOnes = (int)humidity % 10;

    cachedHumTens = humTens;
    cachedHumOnes = humOnes;
    lastHumidityReadMillis = currentMillis;

    return std::make_pair(humTens, humOnes);
}

void Sensors::calibrateMQ9Sensor()
{
    float sensor_volt;  
    float RS_air; //  Rs in clean air 
    float R0;  // R0 in 1000 ppm LPG 
    float sensorValue; 
    
    //Average   
    for(int x = 0 ; x < 100 ; x++) 
    { 
        sensorValue = sensorValue + analogRead(MQ_PIN); 
    } 
    sensorValue = sensorValue/100.0; 
    
    sensor_volt = (sensorValue/1024) * 5.0; 
    RS_air = (5.0 - sensor_volt)/sensor_volt; // Depend on RL on yor module 
    R0 = RS_air/9.9; // According to MQ9 datasheet table 
    
    MQ9_R0 = R0;
}

float Sensors::getMQ9SensorData()
{
    int alarm = 0; 
    float sensor_volt; 
    float RS_gas; 
    float ratio; 
    //-Replace the name "R0" with the value of R0 in the demo of First Test -/ 
    float R0 = 0.91; 
    
    int sensorValue = analogRead(MQ_PIN); 
    sensor_volt = ((float)sensorValue / 4096) * 5.0; 
    RS_gas = (5.0 - sensor_volt) / sensor_volt; // Depend on RL on yor module 
    
    
    ratio = RS_gas / R0; // ratio = RS/R0 

    // Serial.print("Sensor value: ");
    // Serial.println(sensorValue);
    // Serial.print("sensor_volt = "); 
    // Serial.println(sensor_volt); 
    // Serial.print("RS_ratio = "); 
    // Serial.println(RS_gas); 
    // Serial.print("Rs/R0 = "); 
    // Serial.println(ratio); 
    
    // Serial.print("\n\n"); 

    return ratio;
}

bool Sensors::isGasLevelDangerous()
{
    if(getMQ9SensorData() < dangerGasLevel)
    {
        return true;
    }
    return false;
}
