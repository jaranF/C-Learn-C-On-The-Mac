//
//  eg-__0a-seeArgs.c
//  chap-__9
//
//  Created by Jaran F on 25/01/2017.
//
#include <stdio.h>
#include <string.h>

//|--------> FN PROTOTYPES <--------|
int main_seeArgs( int, const char* argv[] );
//|------->      END      <--------|

int main_seeArgs(int argc, const char* argv[])
{
    // THE 'argv[]' ARRAY...
    // =====================
    // Is an array of 8-BYTE POINTERS, each element's pointer pointing to memory
    // containing a NULL terminated string for the argument. So for instance the
    // memory assigned to the 'argv' array variable may look like when the args
    // are '400' and 'eun' (remember that first arg on a Mac is always the path).:
    // -------------------------------------------
    /*
       0x7fff5fbff7a0:  28 F9 BF 5F  |  FF 7F 00 00  |  9E F9 BF 5F  |  FF 7F 00 00 » (ù¿_yy...ù¿_y..
       0x7fff5fbff7b0:  A2 F9 BF 5F  |  FF 7F 00 00  |  XX XX XX XX  |  XX XX XX XX » ¢ù¿_y..........
       argv[0]      r
       argv[1]      0x7fff5fbff99e
       argv[2]      0x7fff5fbff9a2
       0x7fff5fbff99e:  34 30 30 00  |  65 75 6e 00  |  XX XX XX XX  |  XX XX XX XX » 400.eun.........
       0x7fff5fbff9a2:  65 75 6e 00  |  XX XX XX XX  |  XX XX XX XX  |  XX XX XX XX » eun .............
    */
    char argsConcatted[300];
    char separator[2];
    strcpy(separator, ",");
    printf("%d  = number of args\n", argc);

    int i = 0;
    while (argc && *argv != '\0') {
        printf("\'%s\' passed as argument\n", *argv);
        strcat(argsConcatted, i++ > 0 ? "," : "");
        strcat(argsConcatted, *argv);
        argv++;
    }
    printf("\n------------------\n\'%s\'\n-----------------\n", argsConcatted );
    return 0;
}
