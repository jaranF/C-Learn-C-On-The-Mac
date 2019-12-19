//
//  eg-__5-pointer-arithmetic-addition.c
//  chap-__9
//
//  Created by Jaran F on 22/01/2017.
//
#include <stdio.h>

//|-----------> DEFINES <-----------|
#define iSizeOfArray                10
//|--------> FN PROTOTYPES <--------|
void main_pointer_arithmetic_addition( void );
//|------->      END      <--------|

void main_pointer_arithmetic_addition( void )
{
    double array[iSizeOfArray];
    array[0] = 1.1;
    array[1] = 2.2;
    array[2] = 3.3;
    array[3] = 4.4;
    array[4] = 5.5;
    array[5] = 6.6;
    array[6] = 7.7;
    array[7] = 8.8;
    array[8] = 9.9;
    array[9] = 10.10;
    //
    double *aPointer;
    double *bPointer;
    double *cPointer;
    int i = 0;
    aPointer = &array[1];
    bPointer = aPointer + 1;
    printf("aPointer resolves to = %10.1f\n", (*aPointer));
    printf("float *bPointer = aPointer + 1 (i.e. \'array[2] should be 3.3\n");
    printf("bPointer resolves to = %10.1f\n", (*bPointer));
    cPointer = (array) - 1; // Note this equivalent to cPointer = &array[-1] i.e. is a boundary underrun. Experiment changing the number to - 0 and + 1
    printf("----ARRAY POINTER ARITHMETIC EXAMPLE----\n");
    //cPointer--;
    while (i < iSizeOfArray + 1) {
        if (i < 1) {
            printf("(iter) i = %2d;\'cPointer\' (remember \'cPointer)\' = &array[-1] = %5.1f\n", i, *cPointer);
        } else {
            printf("(iter) i = %2d; \'cPointer\' references into array[%d] whose Contents = %5.2f\n", i, i -1, *cPointer);
        }
        cPointer++;
        i++;
    }
    printf("%.1f\n", *(array+0));
}
