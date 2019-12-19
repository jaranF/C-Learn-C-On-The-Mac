//
//  main.c
//  chap-__7
//
//  Created by Jaran F on 10/02/2016.
//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//|--------> FN PROTOTYPES <--------|
bool Factor( int number, int *firstFactorPtr, int *secondFactorPtr);
int main_pointers_to_vars_in_memory(void);
void DrawDots(int numDots);
void DrawDots2(int numDots);
void DrawDots3(int numDots);
int Average(int a, int b);
int main_demonstrate_need_for_global( void );
void main_static_vars_in_functions( void );
void main_static_complex_type_vars_in_functions( void );
//|-------->      END      <--------|

int main(int argc, const char * argv[])
{
    // printf("args len %d\n", argc);
    // printf("arg[0] = %s\n", argv[0]);
    // Use Product > Scheme > Edit Scheme ['Run' tab from lhs nav]...Args passed on launch
    // printf("arg[1] = %s\n", argv[1]);;

    // main_pointers_to_vars_in_memory();
    // DrawDots(5);
    // DrawDots2(1);
    // printf("Average is %d\n", Average(4, 8));
    int firstFactor = __FINITE_MATH_ONLY__;     // Start off with non-sensicaly values as the purpose
    int secondFactor = __FINITE_MATH_ONLY__;    // is for these vars to contain return values.
    Factor(32, &firstFactor, &secondFactor);
    printf("First Factor is %d\nSecondFactor is %d\n", firstFactor, secondFactor);
    // Another factorial demo below (using pointers again for multiple return values)
    /*
        int n;
        for ( n = 2; n <= 20; n++ ) {
            bool isPrime;
            int factor1, factor2;
     
            isPrime = Factor(n, &factor1, &factor2);
            if ( isPrime )
                printf( "the number %d is prime\n", n);
            else
                printf( "the number %d has %d and %d as factorials\n", n, factor1, factor2 );
     
        }
     */
    // main_demonstrate_need_for_global();
    // main_static_vars_in_functions();
    main_static_complex_type_vars_in_functions();
    return 0;
}

