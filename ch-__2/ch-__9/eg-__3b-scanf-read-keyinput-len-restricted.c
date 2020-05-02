//
//  main_scanf_read_keyinput_len_restricted.c
//  chap-__9
//
//  Created by Jaran F on 23/01/2017.
//
// This scanf keyboard function:
// numOfOtemPickedUp = scanf(sPattern, charBuffer);
// Other keyboard scanning in functions are:
// getchar() .. .. 1 char at time; Have to manually check for EOF, limits and newline
// fgets()   .. .. Whole lines args are *buff, iLengthMax, stdin (or FileSteam pointer)
//           .. .. Also captures newlines as part of the input
// Final note: If you have successive 'scanf()' calls you have to flush the buffer between
// one usage of 'scanf' to the next. Otherwise, it's as if the most previous entry was ghosted
// (including the 'RETURN' key) so it automatically becomes the input for the next 'scanf'
// without giving you the chance to type anything. See http://c-faq.com/stdio/gets_flush1.html
#include <stdio.h>
#include <string.h>

//|--------> FN PROTOTYPES <--------|
 int main_scanf_read_keyinput_len_restricted( void );
//|------->      END      <--------|

int main_scanf_read_keyinput_len_restricted()
{
    int scanfRetVal;
    char myCharBuff[4];
    printf("Key in chars (only three characters [can be anything] will be picked out from the buffer to go into myCharBuff however)\n");
    scanfRetVal = scanf("%3s", myCharBuff);
    printf("%s was the \'scanf\' stdin caught input\n", myCharBuff);
    return scanfRetVal;
}
