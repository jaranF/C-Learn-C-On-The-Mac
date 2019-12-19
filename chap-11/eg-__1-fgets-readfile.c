//
//  eg-__1-fgets-readfile.c
//  chap-11
//
//  Created by Jaran F on 20/02/2019.
//
// This fgets file reading function:
// fgets(myCharBuffPtr, [off_t]SIZE, fPtr);
//
// Reads the entire file's worth of ASCII chars until it encounters either an EOF or
// the maximum number of chars (as specified by the SIZE param) is read in; with all the
// letters placed in the memory pointed to by myCharBuffPtr with a terminating NULL auto -
// matically adds on the end of the char array.
// Note a trailing NEWLINE at the end of the file will be appended to the string buffer
// well.
// Other file functions are:
// fgetc()   .. .. 1 char at time; Have to manually check for EOF, limits and newline.
// fputc()   .. .. 1 char at a time.
// fscanf()  .. .. like the keyboard reading function but applies to file streams.
//           .. .. Also captures newlines as part of the input.
// fread()   .. .. A type, array or struct N bytes big, (possibly read X times repeatedly) from current file position (see fseeko()).
#include "modularisationExample.h"
#include "eg-__3-get-home-directory.h"

//|--------> FN PROTOTYPES <--------|
int main_fgets_readfile( void );

int main_fgets_readfile()
{
    int retValue = 0;
    FILE *fp;
    off_t fSize;
    //
    SetHomeDirectory();
    fp = fopen( "./Documents/learning/c/Learn_C_On_The_Mac/chap-11/My_Data_File", "r" );
    if ( NULL == fp ) {
        printf("Error opening file \'My_Data_File\'\n");
        printf("In file path...\n");
        printf("/Users/jaranf/Documents/learning/c/Learn_C_On_The_Mac/chap-11/\n");
        retValue = -1;
    } else {
        fSize = getFileSize(fp);
        char* charBuffPtr;
        charBuffPtr = (char *)malloc(++fSize);
        fgets(charBuffPtr, (int)fSize, fp);  // fgets
        printf(charBuffPtr, "%s");
        printf("\n");
        free(charBuffPtr);
        fclose( fp );
        
    }
  return retValue;
}
