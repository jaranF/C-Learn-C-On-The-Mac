//
//  eg-__5-using-asserts-in-your-code.c
//  chap-12
//
//  Created by JaranF on 17/02/2020.
//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include "main_eg_entry_functions.h"

//|--------> FN PROTOTYPES <--------|
static bool Factor( int number, int *, int *);
//|-------->      END      <--------|

void main_using_asserts_in_your_code() {
    int firstFactor = 120;
    int secondFactor = 2;
    bool result = Factor(0, &firstFactor, &secondFactor);
    printf("RESULT = %s\n", result == 0 ? "False" : "True");
}

// This factor functions finds the two biggest factors (i.e. whole numbers that can divide into a
// number (given as 'number'. So where 2 and two are the smallest 15 and 16 are the biggest (i.e.
// what this function would return).
bool Factor( int number, int *firstFactorPtr, int *secondFactorPtr)
{
    int factor;
    assert(number >= 1);
    for ( factor = sqrt(number); factor > 1; factor-- ) {
        if ( (number % factor) == 0 ) {
            break;
        }
    }
    // Same non-NULL guard as 'eg-__3'.
    if ( firstFactorPtr != NULL )
        *firstFactorPtr = factor;
    if ( secondFactorPtr != NULL )
        *secondFactorPtr = number / factor;
    return factor == 1;
}
