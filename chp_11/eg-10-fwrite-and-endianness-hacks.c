//
//  eg-10-fwrite-and-endianness-hacks.c
//  chap-11
//
//  Created by JaranF on 29/10/2019.
//
#include <stdio.h>
#include "eg-__3-get-home-directory.h"
#include <string.h>
#include <libkern/OSByteOrder.h>
#include <stdbool.h>

//|-----------> DEFINES <-----------|
#define kDataFileName           "writing_out_binary.data"
#define kPathInHomeDir              "./Documents/learning/c/Learn_C_On_The_Mac/chap-11/"
#define FULLFILEURI(VOID) (#VOID kPathInHomeDir kDataFileName)
#define kMaxNumOfInts               20
//|-----------> STRUCTS <-----------|
//|------> TYPEDEFS & ENUMS <-------|
//|--------> FN PROTOTYPES <--------|
void main_fwrite_and_endianness_hacks( void );
static size_t RepeatChars( char*, const char*, long long int );
static void Flush( void );
//|-------->      END      <--------|

void main_fwrite_and_endianness_hacks()
{
    FILE* fp;
    SetHomeDirectory();
    int errno = chdir( kPathInHomeDir );
    if (errno != 0) {
        fprintf(stderr, "Could not get directory");
    } else {
        char endianPref[ 2 ] = "X";
        fp = fopen( kDataFileName, "w" );
        fseeko(fp, 0, SEEK_SET);
        short int inputNumOfIntsInData;
        printf("This program writes out N integers to a data file but does so by writing out the binary represenatation of the numbers (not ascii).\n You will be asked to specify the Endianness of way the ints are saved to file, how many Ints and finally the Ints themselves (space separated).");
        int numScanned;
        bool validInput;
        do {
            printf("\n\nInput Required Endianness ([b]ig / [l]ittle: ");
            numScanned = scanf("%1[bBlL]", endianPref);
            endianPref[ 0 ] &= 0xDF; // Convert to uppercase
            validInput = strcmp(endianPref, "B") == 0 || strcmp(endianPref, "L") == 0;
            if (!validInput) printf("...Please enter a \'L\' or \'B\'\n");
            Flush();
        } while (numScanned < 1 || !validInput);
        printf("\nEnter number of Ints (in hex) to comprise data (1 to 20): ");
        numScanned = scanf("%hd", &inputNumOfIntsInData);
        if (numScanned != 1 || inputNumOfIntsInData < 1) {
            printf("Exiting...\n");
            return;
        }
        Flush();
        int arrNumbers[ kMaxNumOfInts ];
        int * arrNPtr = arrNumbers;
        printf("Enter %d HEX Ints each separated by a space: ", kMaxNumOfInts);
        char scanfFormatStr[ (kMaxNumOfInts * 4) + 1 ];
        // char* scanfFormatStrPtr = scanfFormatStr; // same as &scanfFormatStr[0];
        RepeatChars(&scanfFormatStr[ 0 ], "%X ", inputNumOfIntsInData);
        scanfFormatStr[ strlen(scanfFormatStr) - 1 ] = '\0';  // Strip off trailing space separator after last '%X'.
        numScanned = scanf(scanfFormatStr, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++);
        arrNPtr = arrNumbers;
        for (int i = 0; i < inputNumOfIntsInData; i++) {
            int32_t safeInt;
            if (endianPref[ 0 ] == 'B') {
                safeInt = OSSwapHostToBigInt32(*arrNPtr);
            } else {
                safeInt = OSSwapHostToLittleInt32(*arrNPtr);
            }
            printf("\n%d\n", *arrNPtr);
            fwrite(&safeInt, sizeof(int32_t), 1, fp);
            arrNPtr++;
        }
        fclose(fp);
    }
}

static size_t RepeatChars(char* str, const char* strToRepeat, long long int howMany)
{
    for (long long int i = 1; i <= howMany; i++) {
        strcat(str, strToRepeat);
    }
    return strlen(str);;
}

static void Flush()
{
    while ( getchar() != '\n' )
        ;
}
