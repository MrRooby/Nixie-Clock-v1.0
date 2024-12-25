#pragma once
#include <Arduino.h>

#define SNOOZE_BUTTON 18
#define SWITCH_MODE_BUTTON 5

class Buttons {
    public:
        /*!
            * @brief Set correct pin mode for buttons
        */
        void setupButtons();

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
};