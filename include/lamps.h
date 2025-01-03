#pragma once
#include "PCF8575.h"
#include "sensors.h"

class Lamps {
    private:
        PCF8575 pcf = PCF8575(0x20);
        
        char A[4] = {P7, P3, 13, 26};
        char B[4] = {P5, P1, 14, 33};
        char C[4] = {P4, P0, 27, 32};
        char D[4] = {P6, P2, 12, 25};

    public:
        /*!
            * @brief  Setup pinMode as OUTPUT for all the lamps, and begin the PCF8575, and turn off all lamps
        */
        void setupLamps();

        /*!
            *  @brief  Display a digit on a specific lamp connected directly to the ESP32
            *  @param  digit
            *          The digit to display
            *  @param  lamp
            *          The lamp to display the digit on
        */
        void displayDigitNAT(unsigned int digit, unsigned int lamp);

        /*!
            *  @brief  Display a digit on a specific lamp connected to the PCF8575
            *  @param  digit
            *          The digit to display
            *  @param  lamp
            *          The lamp to display the digit on
        */
        void displayDigitPCF(unsigned int digit, unsigned int lamp);

        /*!
            *  @brief  Display digits on first and second Nixie tubes. 
            *  @param  first
            *          Digit to display on the first lamp
            *  @param  second
            *          Digit to display on the second lamp
        */
        void displayOnTwoLeftLamps(unsigned int first, unsigned int second);

        /*!
            *  @brief  Display digits on third and fourth Nixie tubes. 
            *  @param  first
            *          Digit to display on the third lamp
            *  @param  second
            *          Digit to display on the fourth lamp
        */
        void displayOnTwoRightLamps(unsigned int first, unsigned int second);

        /*!
            *  @brief  Display numbers on all of the Nixie tubes
            *  @param  first
            *          Digit to display on the first lamp
            *  @param  second
            *          Digit to display on the second lamp
            *  @param  third
            *          Digit to display on the third lamp
            *  @param  fourth
            *          Digit to display on the fourth lamp
        */
        void displayOnAllLamps(unsigned int first, unsigned int second, unsigned int third, unsigned int fourth);

        /*!
            *  @brief  Test all combinations of the lamps
            *  @param  number
            *          The number to display on the lamp
            *  @param  lamp
            *          The lamp to display the number on
        */
        void testAllCombination(unsigned int number, unsigned int lamp );
};
