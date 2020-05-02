//
//  eg-__5b-roman-numerals.c
//  chap-__9
//
//  Created by Jaran F on 26/01/2017.
//
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>             // atoi()

//|-----------> DEFINES <-----------|
#define kMaxToConvert            3999
#define kCardinalOfDigits           4
#define kASCIIOfsetToIntValue      48
#define kRomanNumeralDivisorPoints 13
#define kMaxConsecutiveCharRepeats  3
//|--------> FN PROTOTYPES <--------|
char* main_roman_numerals_5b( void );
char* ConvertToRoman2( int, char*, const int[kRomanNumeralDivisorPoints][2][3], int );
char* ConvertIntArrayToChar2( const int*, int, char*, int );
//|------->      END      <--------|

// This version differs insofar that instead of going through all the char positions from
// right to left and power-of-ten-erzing accordingly in the while loop you can instead do
// 'atoi()' call (part of standard stdlib.h)

char* main_roman_numerals_5b( void )
{
    char numToConvert[kCardinalOfDigits +1];  //Four chars for the integer positions plus one for NUL terminating char
    char resultingRomanNumber[14]; //Longest r.numeral < 4000 is 3488 =  MMMCDLXXXVIII (13 chars long + 1 for NUL terminaing char)
    int  decimalToConvert = 0;
    unsigned long i, toConvertLen;
    char* buffPointer;
    char c;
    // int charConvertedToInt;
    const int romanNumerals[kRomanNumeralDivisorPoints][2][3] = {
        {{'M',  0,  0},  1000},
        {{'C',  'M',  0},  900},
        {{'D',  0,  0}, 500},
        {{'C', 'D', 0}, 400},
        {{'C',  0,  0}, 100},
        {{'X', 'C', 0}, 90},
        {{'L',  0,  0}, 50},
        {{'X', 'L', 0}, 40},
        {{'X',  0,  0}, 10},
        {{'I', 'X', 0}, 9},
        {{'V',  0,  0}, 5},
        {{'I', 'V', 0}, 4},
        {{'I',  0,  0}, 1}
        
    };
    // memset(resultingRomanNumber, '\0', sizeof(resultingRomanNumber));
    // strcat(resultingRomanNumber, "A"); this will be added in at to the left of the first \0 char in string buffer array
    strcpy(numToConvert, "0199");
    //needs to be 0199 i.e. zero padded not "199"
    buffPointer = &numToConvert[0] + strlen(numToConvert);
    toConvertLen = strlen(numToConvert);
    i = toConvertLen < kCardinalOfDigits ? toConvertLen : kCardinalOfDigits;
    while ( i > 0 ) {
        c = *(--buffPointer);
        if ( c == '\0' ) { c = '0'; }
        c -= kASCIIOfsetToIntValue;
        // decimalToConvert += (int)pow(10, (double)(toConvertLen - i)) * c;
        i--;
    }
    // printf("\n----%d----\n", atoi(buffPointer));
    decimalToConvert = atoi(buffPointer);
    printf("\n----%d----\n", decimalToConvert);
    ConvertToRoman2(decimalToConvert, resultingRomanNumber, romanNumerals, 0);
    printf("\n----%s----\n", resultingRomanNumber);
    buffPointer = resultingRomanNumber;
    //   for (i = 0; i < kCardinalOfDigits; i++) {
    //       toIntExploded[i] = buff[i] - kASCIIOfsetToIntValue;
    //       //printf("- %d -\n", toIntExploded[i]);
    //   }
    //   memset(romanNumeralResult,' ',13);
    //   romanNumeralResult[13] = '\0';
    //   puts(romanNumeralResult);
    return buffPointer;
}

char* ConvertToRoman2(int toConvert, char* resultingRomanNumber, const int romanNumerals[kRomanNumeralDivisorPoints][2][3], int numeralOrdinal )
{
    char romanBuffer[kMaxConsecutiveCharRepeats + 1];
    int numberTimesNumeralRepeats = 1;
    int digitPositionValue = romanNumerals[numeralOrdinal][1][0];
    if ( toConvert == 0) return resultingRomanNumber;
    int divisorResult = toConvert / romanNumerals[numeralOrdinal][1][0];
    memset(romanBuffer, '\0', kMaxConsecutiveCharRepeats + 1);
    printf("++%d++z\n", divisorResult);
    if (divisorResult > 0) {
        ConvertIntArrayToChar2(&(romanNumerals[numeralOrdinal][0][0]), 3, romanBuffer, kMaxConsecutiveCharRepeats + 1);
        if (strlen(romanBuffer) == 1) {
            numberTimesNumeralRepeats = divisorResult;
        }
        memset(romanBuffer, romanBuffer[0], numberTimesNumeralRepeats);
        strcat(resultingRomanNumber, romanBuffer);
        if (digitPositionValue != 1) {
            ConvertToRoman2(toConvert - (divisorResult * digitPositionValue), resultingRomanNumber,
                           romanNumerals, ++numeralOrdinal);
        }
    } else {
        ConvertToRoman2(toConvert, resultingRomanNumber, romanNumerals, ++numeralOrdinal);
    } // end if
    return resultingRomanNumber;
}

char* ConvertIntArrayToChar2(const int* pointerToArray, int intArraySize, char* charArrayResult, int charArraySize)
{
    int i = 0;
    while (*pointerToArray != '\0' && i < intArraySize) {
        charArrayResult[i] = *pointerToArray;
        i++;
        printf("- %d -\n", *pointerToArray);
        pointerToArray++;
    }
    return charArrayResult;
}
// ret romanStringBuilder, incrementable pointer to char array, incrementalable pointer to int array of Numeral values 1000, 500, 100, incrementalble pointer to cooresponding int value of numerals

