//
//  eg-__8-fprint-write-to-file.c
//  chap-11
//
//  Created by JaranF on 26/10/2019.
//  Program generates numbers (tab separated) for use in the exercise. Writes to filename called
//  'number_data_tab_separatedNN' (where is a number suffix than can be one or two digits long).
//  The file generated is used in the exercise.
//
#include <stdio.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>		/* chdir   */
#include <limits.h>		/* NAME_MAX */
#include <string.h>
#include <math.h>       /* pow */
#include "modularisationExample.h" /* Next_Free_Filename */
#include "eg-__3-get-home-directory.h"

//|-----------> DEFINES <-----------|
#define kBaseDataFileName           "number_data_tab_separated"
#define kPathInHomeDir              "./Documents/learning/c/Learn_C_On_The_Mac/chap-11/exercises/"
//|-----------> STRUCTS <-----------|
//|------> TYPEDEFS & ENUMS <-------|
//|--------> FN PROTOTYPES <--------|
void main_fprintf_write_to_file( void );
static size_t RepeatChars( char*, const char*, long long int );
static void Flush( void );
//|-------->      END      <--------|

void main_fprintf_write_to_file()
{
    FILE* fp;
    SetHomeDirectory();
    int errno = chdir( kPathInHomeDir );
    if (errno != 0) {
        fprintf(stderr, "Could not get directory");
    } else {
        char newFileNameBuf[ NAME_MAX + 1 ];
        strcpy(newFileNameBuf, Next_Free_Filename(kBaseDataFileName, ""));
        short int inputNumOfIntsPerLine;
        printf("This program writes out a file with file format is:\n\tBIGINT\\n\n\tn1->n2->n3->...nBIGINT\\n\nEach data line has BIGINT's worth of ints across it separated with a whitespace char (a tab separated is used when written to the file).");
        printf("\n\nEnter number of Ints per line (1 to 100): ");
        int numScanned = scanf("%hd", &inputNumOfIntsPerLine);
        if (numScanned != 1 || inputNumOfIntsPerLine < 1) {
            printf("Exiting...\n");
            return;
        }
        Flush();
        fp = fopen(newFileNameBuf, "w");
        fprintf(fp, "%hd", inputNumOfIntsPerLine);
        char scanfFormatStr[ 4 ] = "%d";   // later re-use this for "%d\t" hence why size is 4 not 3.
        char * scanfFormatStrPtr = (char *) calloc(1, ((sizeof(scanfFormatStr) - 1) * inputNumOfIntsPerLine) + 2);
        RepeatChars(scanfFormatStrPtr, scanfFormatStr, inputNumOfIntsPerLine);
        int arrNumbers[ 100 ];
        char addAnotherLine = 'y';
        do {
            int * arrNPtr = arrNumbers;
            printf("Enter %hd Ints each separated by a space: ", inputNumOfIntsPerLine);
            numScanned = scanf(scanfFormatStrPtr, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++, arrNPtr++);
            strcpy(scanfFormatStrPtr, "\n%d");
            strcpy(scanfFormatStr, "\t%d");
            RepeatChars(scanfFormatStrPtr, scanfFormatStr, inputNumOfIntsPerLine - 1);
            arrNPtr = arrNumbers;
            fprintf(fp, scanfFormatStrPtr, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++, *arrNPtr++);
            Flush();
            printf("Add another line (y/n)? ");
        } while ((scanf("%c", &addAnotherLine) == 1) && ((addAnotherLine) == 'y'));
        printf("/n");
        free(scanfFormatStrPtr);
        fclose(fp);
//        fp = fopen(newFileNameBuf, "w");
//        char strToWrite[6];
//        strcpy(strToWrite, generateRandomString(5));
//        int i = 0;
//        while (strToWrite[i] != '\0') {
//            fputc(strToWrite[i], fp);
//            i++;
//        }
//        fclose(fp);
//        printf("The next free filename from \'base\' is %s\n", newFileNameBuf);
//        printf("\n%s\n", strToWrite);
        numScanned *= 1;
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
