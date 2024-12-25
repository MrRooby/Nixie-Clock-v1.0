#include <Arduino.h>
#include <Wire.h>
#include "lamps.h"
#include "sensors.h"
#include "tinyRTC.h"
#include "app.h"
#include "buttons.h"
#include "program.h"

Sensors sensors;
Lamps lamps;
Buttons buttons;
TinyRTC tinyRTC;  
Program program;

unsigned int option = 0;

void setup() 
{
  Serial.begin(9600);

  lamps.setupLamps();

  sensors.setupSensors();

  buttons.setupButtons();
}

void loop() 
{
  if(buttons.isSwitchModeButtonPressed())
  {
    option++;
    if(option > 4)
    {
      option = 0;
    }
  }

  program.chooseOption(option);
}
