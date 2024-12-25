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

    // Turn off all lamps
    displayDigitNAT(10, 0); // 10 is the blank digit
    displayDigitNAT(10, 1); // 10 is the blank digit
    displayDigitPCF(10, 2); // 10 is the blank digit
    displayDigitPCF(10, 3); // 10 is the blank digit
}

void Lamps::displayDigitNAT(unsigned int digit, unsigned int lamp){
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
        digitalWrite(A[lamp], HIGH);
        digitalWrite(B[lamp], HIGH);
        digitalWrite(C[lamp], HIGH);
        digitalWrite(D[lamp], HIGH);
        break;
  }
}

void Lamps::displayDigitPCF(unsigned int digit, unsigned int lamp){
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
        pcf.digitalWrite(A[lamp], HIGH);
        pcf.digitalWrite(B[lamp], HIGH);
        pcf.digitalWrite(C[lamp], HIGH);
        pcf.digitalWrite(D[lamp], HIGH);
        break;
  }
}

void Lamps::displayOnTwoLeftLamps(unsigned int first, unsigned int second){
    displayDigitNAT(first, 0);
    displayDigitNAT(second, 1);
    displayDigitPCF(10, 2); // 10 is the blank digit
    displayDigitPCF(10, 3); // 10 is the blank digit
}

void Lamps::displayOnTwoRightLamps(unsigned int first, unsigned int second){
    displayDigitNAT(10, 0); // 10 is the blank digit
    displayDigitNAT(10, 1); // 10 is the blank digit
    displayDigitPCF(first, 2);
    displayDigitPCF(second, 3);
}

void Lamps::displayOnAllLamps(unsigned int first, unsigned int second, unsigned int third, unsigned int fourth){
    displayDigitNAT(first, 0);
    displayDigitNAT(second, 1);
    displayDigitPCF(third, 2);
    displayDigitPCF(fourth, 3);
}

void Lamps::testAllCombination(unsigned int number, unsigned int lamp)
{
    switch(number){
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
        case 10:
            digitalWrite(A[lamp], LOW);
            digitalWrite(B[lamp], HIGH);
            digitalWrite(C[lamp], LOW);
            digitalWrite(D[lamp], HIGH);
            break;  
        case 11:
            digitalWrite(A[lamp], HIGH);
            digitalWrite(B[lamp], HIGH);
            digitalWrite(C[lamp], LOW);
            digitalWrite(D[lamp], HIGH);
            break;
        case 12:
            digitalWrite(A[lamp], LOW);
            digitalWrite(B[lamp], LOW);
            digitalWrite(C[lamp], HIGH);
            digitalWrite(D[lamp], HIGH);
            break;
        case 13:
            digitalWrite(A[lamp], HIGH);
            digitalWrite(B[lamp], LOW);
            digitalWrite(C[lamp], HIGH);
            digitalWrite(D[lamp], HIGH);
            break;
        case 14:
            digitalWrite(A[lamp], LOW);
            digitalWrite(B[lamp], HIGH);
            digitalWrite(C[lamp], HIGH);
            digitalWrite(D[lamp], HIGH);
            break;
        case 15:
            digitalWrite(A[lamp], HIGH);
            digitalWrite(B[lamp], HIGH);
            digitalWrite(C[lamp], HIGH);
            digitalWrite(D[lamp], HIGH);
            break;
        default:
            digitalWrite(A[lamp], HIGH);
            digitalWrite(B[lamp], HIGH);
            digitalWrite(C[lamp], HIGH);
            digitalWrite(D[lamp], HIGH);
            break;
    }
}
