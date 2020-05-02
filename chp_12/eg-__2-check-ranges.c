//
//  eg-__2-check-ranges.c
//  chap-12
//
//  Created by JaranF on 15/02/2020.
//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "main_eg_entry_functions.h"

//|-----------> DEFINES <-----------|
#define kMaxTitleLength             256
//|--------> FN PROTOTYPES <--------|
static bool Factor( int number, int *, int *);
//|-------->      END      <--------|
void main_check_ranges() {
    int firstFactor = 120;
    int secondFactor = 2;
    bool result = Factor(240, &firstFactor, &secondFactor);
    printf("RESULT = %s\n", result == 0 ? "False" : "True");
}

// This factor functions finds the two biggest factors (i.e. whole numbers that can divide into a
// number (given as 'number'. So where 2 and two are the smallest 15 and 16 are the biggest (i.e.
// what this function would return).
bool Factor( int number, int *firstFactorPtr, int *secondFactorPtr)
{
    int factor;
    // Note, how this defensive guard prevents sqrt() being executed on a nagative number
    if (number < 1) {
        return false;
    }
    for ( factor = sqrt(number); factor > 1; factor-- ) {
        if ( (number % factor) == 0 ) {
            break;
        }
    }
    //
    *firstFactorPtr = factor;
    *secondFactorPtr = number / factor;
    return factor == 1;
}
