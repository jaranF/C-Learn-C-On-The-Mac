//
//  eg-__6-fputc-write-chars-to-file.c
//  chap-11
//
//  Created by Jaran F on 18/03/2019.
//
// Other file functions are:
// fgetc()   .. .. 1 char at time; Have to manually check for EOF, limits and newline.
// fgets()   .. .. Whole files at a time until either EOF or SIZE worth of bytes being read.
// fscanf()  .. .. like the keyboard reading function but applies to file streams.
// fread()   .. .. A type, array or struct N bytes big, (possibly read X times repeatedly) from current file position (see fseeko()).
#include <assert.h>
#include <stdio.h>
#include <unistd.h>		/* chdir   */
#include <limits.h>		/* NAME_MAX */
#include <string.h>
#include <time.h>       /* clock */
#include "modularisationExample.h"
#include "write-to-file-defines.h"

//|--------> FN PROTOTYPES <--------|
void main_fputc_write_chars_to_file( void );
char* generateRandomString( int len );
//|-------->      END      <--------|

void main_fputc_write_chars_to_file()
{
    FILE* fp;
    int errno = chdir( Executables_Path() );
    if (errno != 0) {
        fprintf(stderr, "Could not get directory");
    } else {
        char newFileNameBuf[ NAME_MAX + 1 ];
        strcpy(newFileNameBuf, Next_Free_Filename("base", "txt"));
        fp = fopen(newFileNameBuf, "w");
        char strToWrite[ 6 ];
        strcpy(strToWrite, generateRandomString(5));
        int i = 0;
        while (strToWrite[ i ] != '\0') {
            fputc(strToWrite[ i ], fp);
            i++;
        }
        fclose(fp);
        printf("The next free filename from \'base\' is %s\n", newFileNameBuf);
        printf("\n%s\n", strToWrite);
    }
    return;
}

char* generateRandomString(int len) {
    assert(len > 0);
    srand( (int unsigned)clock() );
    char* string = (char*)malloc(len + 1);
    int i;
    for(i = 0; i < len; i++) {
        string[ i ] = 65 + (rand() % 26);
    }
    string[i] = '\0';
    return string;
}
