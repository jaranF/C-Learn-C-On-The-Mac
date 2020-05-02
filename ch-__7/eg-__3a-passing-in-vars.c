//
//  eg-__3a-passing-in-vars.c
//  chap-__7
//
//  Created by Jaran F on 10/06/2016.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void DrawDots3( int i );
void DrawDots( int numDots );
//|-------->      END      <--------|

void DrawDots3(int i)
{
    while (i > 0) {
        DrawDots(30);
        printf("\n");
        i++;
    }
    printf("\nDot printing complete\n");
}
