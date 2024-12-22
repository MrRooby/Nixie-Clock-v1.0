#include "DHT.h"
#include <MQUnifiedsensor.h>
#include <utility>

#define DHT11_PIN 19
#define DHTTYPE DHT11

#define MQ_PIN 34

extern DHT dht(DHT11_PIN, DHTTYPE);
extern MQUnifiedsensor MQ9("esp32", "MQ9");

/*!
    * @brief  Setup pins, objects and run sensor for the DHT11 and MQ9 sensors
*/
void setupSensors();

/*!
    *  @brief  Get the temperature from the DHT11 sensor to display on the Nixie tubes
    *  @return Pair of uint_least8_t values representing the tens and ones of the temperature
*/
std::pair<uint_least8_t, uint_least8_t> getTemperature();  

/*!
    *  @brief  Get the humidity from the DHT11 sensor to display on the Nixie tubes
    *  @return Pair of uint_least8_t values representing the tens and ones of the humidity
*/
std::pair<uint_least8_t, uint_least8_t> getHumidity();