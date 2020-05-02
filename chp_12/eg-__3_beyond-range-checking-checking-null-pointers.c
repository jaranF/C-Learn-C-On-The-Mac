//
//  eg-__2-check-ranges.c
//  chap-12
//
//  Created by JaranF on 15/02/2020.
//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//|-----------> DEFINES <-----------|
#define kMaxTitleLength             256
//|-----------> STRUCTS <-----------|
//|------> TYPEDEFS & ENUMS <-------|
//|--------> FN PROTOTYPES <--------|
void main_beyond_range_checking_checking_null_pointers( void );
static bool Factor( int number, int *, int *);
//|-------->      END      <--------|
void main_beyond_range_checking_checking_null_pointers() {
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
    // Note, whilst being defensive, the below is overly protective as 'number' may be valid.
    // if (number < 1 || firstFactorPtr == NULL || secondFactorPtr == NULL) return false
    if (number < 1) {
        return false;
    }
    for ( factor = sqrt(number); factor > 1; factor-- ) {
        if ( (number % factor) == 0 ) {
            break;
        }
    }
    // Much more flexible as if either or both firstFactorPtr or secondPointerPtr then
    // this function can still do something of a meangingful job.
    if ( firstFactorPtr != NULL )
        *firstFactorPtr = factor;
    if ( secondFactorPtr != NULL )
        *secondFactorPtr = number / factor;
    return factor == 1;
}
