//
//  eg-__0-error-proofing-your-code.c
//  chap-13
//
//  Created by JaranF on 07/11/2019.
//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <errno.h>
#include <err.h>
#ifndef GCC_COMPILER_MACRO_DEFINED_WITH_HYPEN_D
  #define kMaxTitleLength             1
  #define NDEBUG
#endif
#ifdef GCC_COMPILER_MACRO_DEFINED_WITH_HYPEN_D
  #define NDEBUG
  #define kMaxTitleLength             2
#endif
#include <assert.h>

//|-----------> DEFINES <-----------|

//|-----------> STRUCTS <-----------|
//|------> TYPEDEFS & ENUMS <-------|
//|--------> FN PROTOTYPES <--------|
void main_test_error_proofed_factor( void );
bool Factor( int number, int *firstFactorPtr, int *secondFactorPtr);
//|-------->      END      <--------|

void main_test_error_proofed_factor() {
    warn("WARNING");
    printf("--------%d----------\n++++++errno = %d+++++++++\n", kMaxTitleLength, errno);
    int num1 = 2;
    int num2 = 4;
    Factor(0, &num1, &num2);
    printf("FirstFactor number = %d, Second Factor number = %d\n", num1, num2);
}

bool Factor( int number, int *firstFactorPtr, int *secondFactorPtr) {
    assert(number >= 1);
    if (number < 1) err(33, "Divide by zero error");
    int factor;
    for ( factor = sqrt(number); factor > 1; factor-- ) {
        if ( (number % factor) == 0 ) {
            break;
        }
    }
    // *firstFactorPtr = factor;
    // *secondFactorPtr = number / factor;
    // Replaced with more defensive code
    if ( firstFactorPtr != NULL)
        *firstFactorPtr = factor;
    if ( secondFactorPtr != NULL)
        *secondFactorPtr = number / factor;
    return factor == 1;
}


