#include "BluetoothSerial.h"
#include "inputOutput.h"
#include "timeMenager.h"

class BTCon {
    private:
        BluetoothSerial SerialBT;
        InputOutput inputOutput;
        int hour = 0;
        int minute = 0;
        bool alarmArmed = false;

        bool connected = false;
        int incoming;
    public:
        void setupBT();

        void getAlarmDataFromApp(TimeMenager& timeMenager);
        void runBT(TimeMenager& timeMenager);
};