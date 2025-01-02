#pragma once
#include "DHT.h"
#include <MQUnifiedsensor.h>
#include <utility>
#include <Adafruit_Sensor.h>

#define DHT11_PIN 19
#define DHTTYPE DHT11

#define MQ_PIN 36 // VP - Analog pin for MQ9 sensor

class Sensors {
    public:
        MQUnifiedsensor MQ9 = MQUnifiedsensor("esp32", "MQ9");
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
};