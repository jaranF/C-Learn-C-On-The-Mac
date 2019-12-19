//
//  eg-__1c-scanf-read-in-alpha-chars-only.c
//  chap-__9
//
//  Created by Jaran F on 04/04/2019.
//
// This scanf keyboard function:
// numOfOtemPickedUp = scanf("%3[ABCDEFGHIJKLMNOPQRSTUVWXYZ]", myCharBuff);
// Allows three uppercase letters to be placed in myCharBuff AND automatically adds on NULL.
// Note the first NON-uppercase alphachar is where the input is stopped from being plucked
// from the buffer. ie. type in
// ABCD -> get -> ABC
// type in:
// A-BC -> get -> A
// Other keyboard scanning in functions are:
// getchar() .. .. 1 char at time; Have to manually check for EOF, limits and newline
// fgets()   .. .. Whole lines args are *buff, iLengthMax, stdin (or FileSteam pointer)
//           .. .. Also captures newlines as part of the input
// Final note: If you have successive 'scanf()' calls or even a 'getchar()' preceeding the 'scanf()'
// you have to flush the buffer between one usage of 'scanf' to the next. Otherwise, it's as if the
// most previous entry was ghosted (including the 'RETURN' key) so it automatically becomes the
// input for the next 'scanf' without giving you the chance to type anything. See
// http://c-faq.com/stdio/gets_flush1.html
#include <stdio.h>
#include <string.h>

//|--------> FN PROTOTYPES <--------|
int main_scanf_read_in_alpha_chars_only( void );
//|------->      END      <---------|

int main_scanf_read_in_alpha_chars_only()
{
    int scanfRetVal;
    char myCharBuff[4];
    // char c = getchar();
    printf("Key in chars (only three consecutive alpha characters will be picked out from the buffer to go into myCharBuff\n");
    scanfRetVal = scanf("%3[ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz]", myCharBuff);
    printf("%s was the \'scanf\' stdin caught input\n", myCharBuff);
    return scanfRetVal;
}
