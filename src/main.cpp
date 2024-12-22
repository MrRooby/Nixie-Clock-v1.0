#include <Arduino.h>
#include <Wire.h>
#include "lamps.h"
#include "sensors.h"
#include "tinyRTC.h"

Sensors sensors;
Lamps lamps;
TinyRTC tinyRTC;  

void setup() 
{
  Serial.begin(115200);

  // Lamps
  lamps.setupLamps();

  // Sensors
  sensors.setupSensors();
}

void loop() 
{
}