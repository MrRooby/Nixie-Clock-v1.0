#include <Arduino.h>
#include <Wire.h>
#include "lamps.h"
#include "sensors.h"

void setup() {
  Serial.begin(115200);

  // Lamps
  setupLamps();

  // Sensors
  setupSensors();
}

void loop() {
  // Temperature
  std::pair<uint_least8_t, uint_least8_t> temperature = getTemperature();
  displayDigitNAT(temperature.first, 0);
  displayDigitNAT(temperature.second, 1);

  // Humidity
  std::pair<uint_least8_t, uint_least8_t> humidity = getHumidity();
  displayDigitNAT(humidity.first, 2);
  displayDigitNAT(humidity.second, 3);

  delay(1000);
}



