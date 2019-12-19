//
//  eg-__1a-fgets-readfile_with_eof_encountered_before_size_limit.c
//  chap-11
//
//  Created by Jaran F on 13/09/2019.
//
// This fgets file reading function:
// fgets(myCharBuffPtr, [int]SIZE, fPtr);
//
// This exploration shows what happens when a EOF is encountered BEFORE the SIZE limiter's
// number of bytes to read limit is reached.
// A recap of the 'fgets' function: Reads the entire file's worth of ASCII chars until it
// encounters either an EOF or the maximum number of chars (as specified by the SIZE param)
// is read in; with all the letters placed in the memory pointed to by myCharBuffPtr with
// a terminating NULL automatically adds on the end of the chr array.
// Example
// 'My_short_DataFile.txt' only contains 'ABCZYX' (equals len of 7 with 0x0A at end)
// Whereas SIZE is a BIG number (say the maximum positive number of a long long int).
// type in:
// BEFORE *(charBuffPtr) IS ASSIGNED ANYTHING
// ------------------------------------------
// 0x102800000      00 00 00 00 | 00 00 00 00 | 4F 00 00 00     ........O...
// AFTER *(charBuffPtr) IS ASSIGNED DUMMY DATA
// -------------------------------------------
// 0x102800000      4d 4e 4f 50 | 51 52 53 54 | 55 00 00 00     MNOPQRSTU...
// AFTER fgets() READS TO EOF
// --------------------------
// 0x102800000      41 42 43 5A | 59 58 0A 00 | 55 00 00 00     ABCZYX .U...
// So 'fgets' does not barf if it gets to an EOF before expending the number of bytes
// it's allowed to read as a maximum (as supplied in the SIZE param). Interestingly
// this SIZE param accepts INT types BUT the type returned by 'getFileSize()' is the
// much larger 'off_t' type (i.e. 8 bytes length).
//
// Other file functions are:
// fgetc()   .. .. 1 char at time; Have to manually check for EOF, limits and newline.
// fputc()   .. .. 1 char at a time.
// fscanf()  .. .. like the keyboard reading function but applies to file streams.
//           .. .. Also captures newlines as part of the input.
// fread()   .. .. A type, array or struct N bytes big, (possibly read X times repeatedly) from current file position (see fseeko()).
#include "modularisationExample.h"
#include "eg-__3-get-home-directory.h"
#include <math.h>   // pow()

//|-----------> DEFINES <-----------|
#define bitsPerByte                 8
//|--------> FN PROTOTYPES <--------|
int main_fgets_readfile_with_eof_encountered_before_size_limit( void );
//|-------->      END      <--------|

int main_fgets_readfile_with_eof_encountered_before_size_limit()
{
    int retValue = 0;
    FILE *fp;
    off_t fSize;
    //
    SetHomeDirectory();
    fp = fopen( "./Documents/learning/c/Learn_C_On_The_Mac/chap-11/My_short_DataFile.txt", "r" );
    if ( NULL == fp ) {
        printf("Error opening file \'My Data File\'\n");
        printf("In file path...\n");
        printf("/Users/jaranf/Documents/learning/c/Learn_C_On_The_Mac/chap-11/\n");
        retValue = -1;
    } else {
        fSize = (int) ((powl(2.0, sizeof(int) * bitsPerByte) / 2) -2); // Pretty big number.
        char* charBuffPtr;
        charBuffPtr = (char *)malloc(++fSize);
        *charBuffPtr = 'M';
        *(charBuffPtr + 1) = 'N';
        *(charBuffPtr + 2) = 'O';
        *(charBuffPtr + 3) = 'P';
        *(charBuffPtr + 4) = 'Q';
        *(charBuffPtr + 5) = 'R';
        *(charBuffPtr + 6) = 'S';
        *(charBuffPtr + 7) = 'T';
        *(charBuffPtr + 8) = 'U';
        *(charBuffPtr + 9) = '\0';
        fgets(charBuffPtr, (int)fSize, fp);  // fgets
        printf(charBuffPtr, "%s");
        printf("\n");
        free(charBuffPtr);
        fclose( fp );
        
    }
    return retValue;
}

// eg-__1a-fgets-readfile_with_eof_encountered_before_size_limit.c
