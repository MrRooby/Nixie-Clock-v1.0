#include "PCF8575.h"
#include "sensors.h"

// FROM THE LEFT
// Lamp 1
#define A1 26
#define B1 33
#define C1 32
#define D1 25

// Lamp 2
#define A2 13
#define B2 14
#define C2 27
#define D2 12

// Lamp 3 - PCF8575
#define A3 P3
#define B3 P1
#define C3 P0
#define D3 P2

// Lamp 4 - PCF8575
#define A4 P7
#define B4 P5
#define C4 P4
#define D4 P6


class Lamps {
    private:
        PCF8575 pcf = PCF8575(0x20); 
        
        char A[4] = {A1, A2, A3, A4};
        char B[4] = {B1, B2, B3, B4};
        char C[4] = {C1, C2, C3, C4};
        char D[4] = {D1, D2, D3, D4};

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
};
