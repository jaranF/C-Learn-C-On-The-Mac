//
//  eg-__2-function-parameters.c
//  chap-__7
//
//  Created by Jaran F on 07/06/2016.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void DrawDots( int numDots );
//|-------->      END      <--------|

void DrawDots(int numDots)
{
    int i;
    for ( i = 1; i <= numDots; i++ ) {
        printf( "." );
    }
}
