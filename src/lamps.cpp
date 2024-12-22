#include "lamps.h"

void Lamps::setupLamps(){
    pinMode(A[0], OUTPUT);
    pinMode(B[0], OUTPUT);
    pinMode(C[0], OUTPUT);
    pinMode(D[0], OUTPUT);

    pinMode(A[1], OUTPUT);
    pinMode(B[1], OUTPUT);
    pinMode(C[1], OUTPUT);
    pinMode(D[1], OUTPUT);

    pcf.pinMode(A[2], OUTPUT);
    pcf.pinMode(B[2], OUTPUT);
    pcf.pinMode(C[2], OUTPUT);
    pcf.pinMode(D[2], OUTPUT);

    pcf.pinMode(A[3], OUTPUT);
    pcf.pinMode(B[3], OUTPUT);
    pcf.pinMode(C[3], OUTPUT);
    pcf.pinMode(D[3], OUTPUT);

    pcf.begin();
}

void Lamps::displayDigitNAT(uint_least8_t digit, uint_least8_t lamp){
  switch(digit) {
    case 0:
        digitalWrite(A[lamp], LOW);
        digitalWrite(B[lamp], LOW);
        digitalWrite(C[lamp], LOW);
        digitalWrite(D[lamp], LOW);
        break;
    case 1:
        digitalWrite(A[lamp], HIGH);
        digitalWrite(B[lamp], LOW);
        digitalWrite(C[lamp], LOW);
        digitalWrite(D[lamp], LOW);
        break;
    case 2:
        digitalWrite(A[lamp], LOW);
        digitalWrite(B[lamp], HIGH);
        digitalWrite(C[lamp], LOW);
        digitalWrite(D[lamp], LOW);
        break;
    case 3:
        digitalWrite(A[lamp], HIGH);
        digitalWrite(B[lamp], HIGH);
        digitalWrite(C[lamp], LOW);
        digitalWrite(D[lamp], LOW);
        break;
    case 4:
        digitalWrite(A[lamp], LOW);
        digitalWrite(B[lamp], LOW);
        digitalWrite(C[lamp], HIGH);
        digitalWrite(D[lamp], LOW);
        break;
    case 5:
        digitalWrite(A[lamp], HIGH);
        digitalWrite(B[lamp], LOW);
        digitalWrite(C[lamp], HIGH);
        digitalWrite(D[lamp], LOW);
        break;
    case 6:
        digitalWrite(A[lamp], LOW);
        digitalWrite(B[lamp], HIGH);
        digitalWrite(C[lamp], HIGH);
        digitalWrite(D[lamp], LOW);
        break;
    case 7:
        digitalWrite(A[lamp], HIGH);
        digitalWrite(B[lamp], HIGH);
        digitalWrite(C[lamp], HIGH);
        digitalWrite(D[lamp], LOW);
        break;
    case 8:
        digitalWrite(A[lamp], LOW);
        digitalWrite(B[lamp], LOW);
        digitalWrite(C[lamp], LOW);
        digitalWrite(D[lamp], HIGH);
        break;
    case 9:
        digitalWrite(A[lamp], HIGH);
        digitalWrite(B[lamp], LOW);
        digitalWrite(C[lamp], LOW);
        digitalWrite(D[lamp], HIGH);
        break;
    default:
        break;
  }
}

void Lamps::displayDigitPCF(uint_least8_t digit, uint_least8_t lamp){
  switch(digit) {
    case 0:
        pcf.digitalWrite(A[lamp], LOW);
        pcf.digitalWrite(B[lamp], LOW);
        pcf.digitalWrite(C[lamp], LOW);
        pcf.digitalWrite(D[lamp], LOW);
        break;
    case 1:
        pcf.digitalWrite(A[lamp], HIGH);
        pcf.digitalWrite(B[lamp], LOW);
        pcf.digitalWrite(C[lamp], LOW);
        pcf.digitalWrite(D[lamp], LOW);
        break;
    case 2:
        pcf.digitalWrite(A[lamp], LOW);
        pcf.digitalWrite(B[lamp], HIGH);
        pcf.digitalWrite(C[lamp], LOW);
        pcf.digitalWrite(D[lamp], LOW);
        break;
    case 3:
        pcf.digitalWrite(A[lamp], HIGH);
        pcf.digitalWrite(B[lamp], HIGH);
        pcf.digitalWrite(C[lamp], LOW);
        pcf.digitalWrite(D[lamp], LOW);
        break;
    case 4:
        pcf.digitalWrite(A[lamp], LOW);
        pcf.digitalWrite(B[lamp], LOW);
        pcf.digitalWrite(C[lamp], HIGH);
        pcf.digitalWrite(D[lamp], LOW);
        break;
    case 5:
        pcf.digitalWrite(A[lamp], HIGH);
        pcf.digitalWrite(B[lamp], LOW);
        pcf.digitalWrite(C[lamp], HIGH);
        pcf.digitalWrite(D[lamp], LOW);
        break;
    case 6:
        pcf.digitalWrite(A[lamp], LOW);
        pcf.digitalWrite(B[lamp], HIGH);
        pcf.digitalWrite(C[lamp], HIGH);
        pcf.digitalWrite(D[lamp], LOW);
        break;
    case 7:
        pcf.digitalWrite(A[lamp], HIGH);
        pcf.digitalWrite(B[lamp], HIGH);
        pcf.digitalWrite(C[lamp], HIGH);
        pcf.digitalWrite(D[lamp], LOW);
        break;
    case 8:
        pcf.digitalWrite(A[lamp], LOW);
        pcf.digitalWrite(B[lamp], LOW);
        pcf.digitalWrite(C[lamp], LOW);
        pcf.digitalWrite(D[lamp], HIGH);
        break;
    case 9:
        pcf.digitalWrite(A[lamp], HIGH);
        pcf.digitalWrite(B[lamp], LOW);
        pcf.digitalWrite(C[lamp], LOW);
        pcf.digitalWrite(D[lamp], HIGH);
        break;
    default:
        break;
  }
}

void Lamps::displayTemperature(uint_least8_t tempTens, uint_least8_t tempOnes){
    displayDigitPCF(tempTens, 2);  // Display the tens digit of the temperature
    displayDigitPCF(tempOnes, 3); // Display the ones digit of the temperature
}

void Lamps::displayHumidity(uint_least8_t humTens, uint_least8_t humOnes){
    displayDigitPCF(humTens, 2);  // Display the tens digit of the humidity
    displayDigitPCF(humOnes, 3); // Display the ones digit of the humidity
}