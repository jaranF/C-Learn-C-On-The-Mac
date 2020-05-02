//
//  eg-__5-factorial-pointers-as-function-arguments.c
//  chap-__7
//
//  Created by Jaran F on 13/06/2016.
//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//|--------> FN PROTOTYPES <--------|
bool Factor( int number, int *firstFactorPtr, int *secondFactorPtr );
//|-------->      END      <--------|

bool Factor( int number, int *firstFactorPtr, int *secondFactorPtr)
{
    int factor;
    for ( factor = sqrt(number); factor > 1; factor-- ) {
        if ( (number % factor) == 0 ) {
            break;
        }
    }
    
    *firstFactorPtr = factor;
    *secondFactorPtr = number / factor;
    return factor == 1;
}
