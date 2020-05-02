//
//  eg-__3-separation-of-scopes.c
//  chap-__7
//
//  Created by Jaran F on 10/06/2016.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void DrawDots2( int numDots );
void DrawDots( int numDots );
//|-------->      END      <--------|

void DrawDots2(int numDots)
{
    int i;
    for ( i = 1; i <= 10; i++ ) {
      DrawDots(numDots);
      printf("\n");
    }
}
