//
//  eg-__2-fgetc-readchar.c
//  chap-11
//
//  Created by Jaran F on 20/02/2019.
//
// This fgetc file reading function:
// {int} character = fgetc(fPtr);
//
// Other file functions are:
// fgets()   .. .. Whole files at a time until either EOF or SIZE worth of bytes being read.
// fputc()   .. .. 1 char at a time.
// fscanf()  .. .. like the keyboard reading function but applies to file streams.
//           .. .. Also captures newlines as part of the input.
// fread()   .. .. A type, array or struct N bytes big, (possibly read X times repeatedly) from current file position (see fseeko()).
#include "modularisationExample.h"

//|--------> FN PROTOTYPES <--------|
int main_fgetc_readchar( void );
//|-------->      END      <--------|

int main_fgetc_readchar()
{
    int retValue = 0;
    FILE *fp;
    fp = fopen( "/Users/jaranf/Library/Developer/Xcode/DerivedData/chap-11-bzzsbhhjbupdxjafgcxnnovuycqq/Build/Products/Debug/advTime-line_memory", "r" );
    if ( NULL == fp ) {
        printf("Error opening file \'advTime-line_memory\'\n");
        printf("In file path...\n");
        printf("/Users/jaranf/Library/Developer/Xcode/DerivedData/chap-11-bzzsbhhjbupdxjafgcxnnovuycqq/Build/Products/Debug/\n");
        retValue = -1;
    } else {
        int c;
        int i;
        int c_complemented;
        i = 0;
        while ( (c = fgetc( fp )) != EOF ) {
            c_complemented = c ^ 255;
            //printf("%c", c); //putchar( c ); ))
            //printf("0x%x ", c_complemented);
            if (c_complemented > 31 && c_complemented < 128) {
                i++;
                printf("%c", c_complemented);
                if (i % 64 == 0) printf("\n");
            }
        }
        putchar('\n');
        fclose( fp );
        
    }
    return retValue;
}
