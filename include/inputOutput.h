#pragma once
#include <Arduino.h>
#include <PCF8575.h>

#define SNOOZE_BUTTON 18
#define SWITCH_MODE_BUTTON 5
#define BUZZER 23
#define INBUILT_LED 2

class InputOutput {
    private:
        int diods[4] = {15, 4, 16, 17};
        bool alarmLEDsOn = false;
    public:
        /*! 
            * @brief Set correct pin mode for buttons, buzzer and diods
        */
        void setupIO();

        /*!
            * @brief Set correct pin mode for buttons
        */
        void setupButtons();

        /*!
            * @brief Set correct pin mode for buzzer
        */
        void setupBuzzer();

        /*!
            * @brief Set correct pin mode for diods
        */
        void setupDiods();

        /*!
            * @brief Turn on or off the buzzer
            * @param choice true for on, false for off
        */
        void buzzConstant(bool choice);
        
        /*!
            * @brief Turn on the buzzer for a specific amount of time
            * @param time time in milliseconds
        */
        void buzzForTime(unsigned int time);

        /*!
            * @brief Turn on the buzzer for a specific amount of time, then turn it off for a specific amount of time
            * @param timeOn time in milliseconds
            * @param timeOff time in milliseconds
            * @param choice true for on, false for off
        */
        void buzzPullse(unsigned int timeOn, unsigned int timeOff, bool choice);

        /*!
            * @brief Check if snooze button is pressed
            * @return true if button is pressed, false otherwise
        */
        bool isSnoozeButtonPressed();
        
        /*!
            * @brief Check if switch mode button is pressed
            * @return true if button is pressed, false otherwise
        */
        bool isSwitchModeButtonPressed();

        /*!
            * @brief Turn on or off the inbuilt led
            * @param choice true for on, false for off
        */
        void turnOnInbuiltLED(bool choice);

        /*!
            * @brief Turn on or off the specific diod
            * @param diodNumber number of the diod
            * @param choice true for on, false for off
        */
        void turnOnSingleLED(unsigned int diodNumber, bool choice);

        /*!
            * @brief Turn on or off selected diod
            * @param diodNumber number of the diod
            * @param choice true for on, false for off
        */
        void turnOnLED(unsigned int diodNumber, bool choice);

        /*!
            * @brief Blink all diods in interval
            * @param choice true for on, false for off
            * @param interval interval in milliseconds
        */
        void blinkLEDs(bool choice, unsigned int intervalMillis);
};