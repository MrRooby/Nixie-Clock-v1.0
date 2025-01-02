#include "BTCon.h"

void BTCon::setupBT()
{
    SerialBT.begin("Nixie Clock");
}

void BTCon::getAlarmDataFromApp(TimeMenager &timeMenager)
{
    incoming = SerialBT.read();

    if(incoming / 100 == 1)
    {
        hour = incoming % 100;
    }
    else if(incoming / 100 == 2)
    {
        minute = incoming % 200;
    }
    else
    {
        Serial.print("Alarm armed: ");
        if(incoming == 1)
        {
            alarmArmed = true;
        }
        else if (incoming == 0)
        {
            alarmArmed = false;
        }
    }

    timeMenager.setupAlarm(hour, minute);
    timeMenager.armAlarm(alarmArmed);
}

void BTCon::runBT(TimeMenager &timeMenager)
{
    if(SerialBT.available())
    {
        inputOutput.turnOnInbuiltLED(true);

        getAlarmDataFromApp(timeMenager);
    }
}
