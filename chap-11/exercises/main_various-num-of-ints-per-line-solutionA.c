//
//  main.c
//  RomanNumeral
//
//  Created by James Bucanek and David Mark on 8/13/12.
//  Copyright (c) 2012 Apress, Inc. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// TASKS
// OPEN FILE, (detect errors & exit gracefully)
// IF OK
//      TEST FIRST CHAR OF FILE (expect number, exit with warn if not)
//          IF OK
//              READ THE NUMBER WHICH IS FORMED BY FIRST CHARS OF FILE BEFORE \n (newline)
//              SET INT TO EXPECT n NUMBER OF NUMBER SEGMENTS PER LINE
//              WHILE NOT EOF READ IN FROM LINE 2 TO EOF
//                  READ IN n ints in LINE FILLING arrLine up
//                  PRINT out Line of INTS
//
// int myarr[] = {2, 4, 5, 8};
// printLineOfInts(myarr, 4);

//|-----------> DEFINES <-----------|
#define kBitsPerByte                8
#define kDataFileName               "number_data_tab_separated2"
#define kPathInHomeDir              "/Users/jaranf/Documents/learning/c/Learn_C_On_The_Mac/chap-11/exercises/"
#define FULLFILEURI(VOID) (#VOID kPathInHomeDir kDataFileName)
#define kScanDigitsToNewlinePattern       "%s"
//|-----------> STRUCTS <-----------|
//|------> TYPEDEFS & ENUMS <-------|
//|--------> FN PROTOTYPES <--------|
int main_various_num_of_ints_per_line_solutionA( int, const char * argv[] );
static void PrintNoFileError( void );
static void PrintFileFoundWithInvalidData( void );
static int ProcessNumbersInStream( FILE* stream );
static size_t GetAmountOfDigitsInInt( void );
static int GetLineOfNumbers( FILE* stream, int*, long long int );
static void PrintLineOfInts( int[], size_t );
//|-------->      END      <--------|

int main_various_num_of_ints_per_line_solutionA( int argc, const char * argv[] )
{
    int retValue = 0;
    FILE* fp = fopen( FULLFILEURI(), "r" );
    if ( fp != NULL ) {
        ProcessNumbersInStream( fp );
        fclose( fp );
    } else {
        PrintNoFileError();
        retValue = -1;
    }
    //    if ( argc == 1 )
    //        ReplaceNumbersInStream( stdin );
    //
    return retValue;
}

void PrintNoFileError()
{
    printf("Error opening file \'%s\'\n", kDataFileName);
    printf("In file path...\n");
    printf("%s\n", kPathInHomeDir);
}

void PrintFileFoundWithInvalidData()
{
    printf("File found but with invalid data\n");
}

int ProcessNumbersInStream( FILE* stream )
{
    int retValue = 0;
    int c;
    int returnedCode;
    c = fgetc(stream);
    long long int numIntsPerline = 0;
    if (c != EOF && isdigit(c)) {
        ungetc(c, stream);
        fscanf(stream, "%lld", &numIntsPerline);
        while ((c = fgetc(stream) != EOF)) {
            int* arrayForlinePtr = (int *)calloc(numIntsPerline, sizeof(int));
            returnedCode = GetLineOfNumbers(stream, arrayForlinePtr,  numIntsPerline);
            if (returnedCode > -1) {
                PrintLineOfInts(arrayForlinePtr, numIntsPerline);
            }
            free(arrayForlinePtr);
            if (returnedCode < 0) {
                PrintFileFoundWithInvalidData();
                retValue = returnedCode;
                break;
            }
            
        }
    } else {
        PrintFileFoundWithInvalidData();
        retValue = -1;
    }
    if (retValue > -1) {
        printf("All line of ints printed successfully; Number of ints per line = %lld\n", numIntsPerline);
    }
    return retValue;
}

int GetLineOfNumbers(FILE* stream, int* arrayForlinePtr, long long int perLine)
{
    int retValue = 0;
    long long int i;
    int amountOfScannedItems;
    char* lineIntItemBuffPtr = (char *) malloc(GetAmountOfDigitsInInt());
    for (i = 0; i < perLine; i++) {
        amountOfScannedItems = fscanf(stream, kScanDigitsToNewlinePattern, lineIntItemBuffPtr);
        if (amountOfScannedItems == EOF) {
            retValue = -1;
            break;
        }
        if (amountOfScannedItems < 1) {
            printf("Error in expected integer forming part of line of data: Int badly formed or not present.");
            retValue = -2;
            break;
        }
        // printf("\n to int = %d\n", atoi(lineIntItemBuff));
        (*arrayForlinePtr) = atoi(lineIntItemBuffPtr);
        arrayForlinePtr++;
    }
    return retValue;
}

size_t GetAmountOfDigitsInInt() {
    char strOfNumbersDigits[65];
    unsigned int highestIntNumber = pow(2, sizeof(int) * kBitsPerByte) - 1;
    sprintf(strOfNumbersDigits, "%u", highestIntNumber);         // Now 'strOfNumbersDigits' contains the integer as characters.
    return strlen(strOfNumbersDigits);
}

void PrintLineOfInts(int arr[], size_t len) {
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

