#pragma once
#include "DHT.h"
#include <utility>
#include <Adafruit_Sensor.h>

#define DHT11_PIN 19
#define DHTTYPE DHT11

#define MQ_PIN 36 // VP - Analog only

class Sensors {
    private:
        unsigned long lastTempReadMillis = 0;
        unsigned int cachedTempTens = 0;
        unsigned int cachedTempOnes = 0;
    
        unsigned long lastHumidityReadMillis = 0;
        unsigned int cachedHumTens = 0;
        unsigned int cachedHumOnes = 0;

        float MQ9_R0 = 0.91; // Value to be changed after calibration
        float dangerGasLevel = 1.1;
    public:

        DHT dht = DHT(DHT11_PIN, DHTTYPE);


        /*!
            * @brief  Setup pins, objects and run sensor for the DHT11 and MQ9 sensors
        */
        void setupSensors();

        /*!
            *  @brief  Get the temperature from the DHT11 sensor to display on the Nixie tubes
            *  @return Pair of unsigned int values representing the tens and ones of the temperature
        */
        std::pair<unsigned int, unsigned int> getTemperature();  

        /*!
            *  @brief  Get the humidity from the DHT11 sensor to display on the Nixie tubes
            *  @return Pair of unsigned int values representing the tens and ones of the humidity
        */
        std::pair<unsigned int, unsigned int> getHumidity();

        /*!
            *  @brief  Get average R0 value for proper calibration of the MQ9 sensor
                       For this function to return the correct value, the MQ9 sensor must be exposed to clean air
                       and run after 48h heating up period
        */
        void calibrateMQ9Sensor();
        
        /*!
            *  @brief  Get the RS/R0 ratio value of the gas from the MQ9 sensor
            *  @param choice 'c' for CO, 'l' for LPG, 'm' for Methane
            *  @return Integer value representing the sensor data
        */
        float getMQ9SensorData();

        /*!
            *  @brief  Check if the gas level is dangerous
            *  @return True if the gas level is dangerous
        */
        bool isGasLevelDangerous();

};