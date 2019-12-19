//
//  File.c
//  chap-__8
//
//  Created by Jaran F on 02/01/2017.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void PrintChars ( int from, int to);
//|------->      END      <--------|

void PrintChars ( int startChar, int intEndChar)
{
    signed i;
    char c;
    intEndChar = intEndChar - startChar;    // Delta.
    for (i = 0; i <= intEndChar; i++) {
        c = startChar + i;
        printf("i (iterator) = %d, ascii char %c\n", startChar + i, c);
    }
}
