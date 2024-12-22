#include <Arduino.h>
#include <Wire.h>
#include "lamps.h"
#include "sensors.h"

Sensors sensors;
Lamps lamps;

void setup() {
  Serial.begin(115200);

  // Lamps
  lamps.setupLamps();

  // Sensors
  sensors.setupSensors();
}

void loop() {
  // Temperature
  std::pair<uint_least8_t, uint_least8_t> temperature = sensors.getTemperature();
  lamps.displayDigitNAT(temperature.first, 0);
  lamps.displayDigitNAT(temperature.second, 1);

  // Humidity
  std::pair<uint_least8_t, uint_least8_t> humidity = sensors.getHumidity();
  lamps.displayDigitNAT(humidity.first, 2);
  lamps.displayDigitNAT(humidity.second, 3);

  delay(1000);
}



