#include <Arduino.h>
#include <Wire.h>
#include <config.h>
#include <PCF8575.h>

#include "lamps.h"
#include "sensors.h"
#include "inputOutput.h"
#include "program.h"
#include "timeMenager.h"
#include "BTCon.h"


Sensors sensors;
Lamps lamps;
InputOutput inputOutput;
Program program;
TimeMenager timeMenager;
BTCon btCon;

unsigned int option = 0;


void setup() 
{
  Serial.begin(9600);

  lamps.setupLamps();

  sensors.setupSensors();

  inputOutput.setupIO();

  btCon.setupBT();
}

void loop() 
{
  if(inputOutput.isSwitchModeButtonPressed())
  {
    option++;
    if(option > 3)
    {
      option = 0;
    }
  }
  
  program.displayOption(option);

  btCon.runBT(timeMenager);

  timeMenager.runAlarmClock();

  program.runGasLevelAlarm();
}
