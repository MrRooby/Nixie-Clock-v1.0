#include "PCF8575.h"

// FROM THE LEFT
// Lamp 1
#define A1 26
#define B1 25
#define C1 33
#define D1 32

// Lamp 2
#define A2 13
#define B2 12
#define C2 14
#define D2 27

// Lamp 3 - PCF8575
#define A3 P3
#define B3 P2
#define C3 P1
#define D3 P0

// Lamp 4 - PCF8575 - checked
#define A4 P7
#define B4 P5
#define C4 P4
#define D4 P6

extern char A[4] = {A1, A2, A3, A4};
extern char B[4] = {B1, B2, B3, B4};
extern char C[4] = {C1, C2, C3, C4};
extern char D[4] = {D1, D2, D3, D4};

extern PCF8575 pcf(0x20);

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