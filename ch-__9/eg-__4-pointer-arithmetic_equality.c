//
//  eg-__2-pointer-arithmetic.c
//  chap-__9
//
//  Created by Jaran F on 22/01/2017.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void main_pointer_arithmetic_equality( void );
//|------->      END      <--------|

void main_pointer_arithmetic_equality()
{
    int array[10];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    array[5] = 6;
    array[6] = 7;
    array[7] = 8;
    array[8] = 9;
    array[9] = 10;
    
    int *aPointer;
    int *bPointer;
    
    aPointer = &array[2];
    bPointer = &array[2];
    
    if ( aPointer == bPointer ) printf("Both \'* aPointer\' and \'* bPointer\' are the same memory address.\n");
    else
        printf("\'* aPointer\' and \'* bPointer\' are different.S");
    
}
