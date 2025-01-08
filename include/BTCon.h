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
        /*!
            * @brief Setup the Bluetooth connection
        */
        void setupBT();

        /*!
            * @brief Get the alarm data from the app
            * @param timeMenager TimeMenager object for setting the alarm
        */
        void getAlarmDataFromApp(TimeMenager& timeMenager);

        /*!
            * @brief Run the Bluetooth connection
                     If the app is connected, the inbuilt LED will turn on
            * @param timeMenager TimeMenager object for setting the alarm
        */
        void runBT(TimeMenager& timeMenager);
};