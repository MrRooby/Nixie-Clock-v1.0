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
    public:
        PCF8575 pcf = PCF8575(0x20); 

        char A[4] = {A1, A2, A3, A4};
        char B[4] = {B1, B2, B3, B4};
        char C[4] = {C1, C2, C3, C4};
        char D[4] = {D1, D2, D3, D4};

        /*!
            * @brief  Setup pinMode as OUTPUT for all the lamps, and begin the PCF8575
        */
        void setupLamps();

        /*!
            *  @brief  Display a digit on a specific lamp connected directly to the ESP32
            *  @param  digit
            *          The digit to display
            *  @param  lamp
            *          The lamp to display the digit on
        */
        void displayDigitNAT(uint_least8_t digit, uint_least8_t lamp);

        /*!
            *  @brief  Display a digit on a specific lamp connected to the PCF8575
            *  @param  digit
            *          The digit to display
            *  @param  lamp
            *          The lamp to display the digit on
        */
        void displayDigitPCF(uint_least8_t digit, uint_least8_t lamp);

        /*!
            *  @brief  Display the temperature on the Nixie tubes
            *          The tens digit is displayed on the 3rd lamp
            *          and the ones digit is displayed on the 4th lamp
            *  @param  tempTens
            *          The tens digit of the temperature
            *  @param  tempOnes
            *          The ones digit of the temperature
        */
        void displayTemperature(uint_least8_t tempTens, uint_least8_t tempOnes);

        /*!
            *  @brief  Display the humidity on the Nixie tubes. 
            *          The tens digit is displayed on the 3rd lamp 
            *          and the ones digit is displayed on the 4th lamp
            *  @param  humTens
            *          The tens digit of the humidity
            *  @param  humOnes
            *          The ones digit of the humidity
        */
        void displayHumidity(uint_least8_t humTens, uint_least8_t humOnes);
};

