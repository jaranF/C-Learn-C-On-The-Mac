//
//  eg-__2-operators-mdas.c
//  chap-__4
//
//  Created by Jaran F on 29/12/2014.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
int main_Multiplication_Division_Addition_Subtraction( int argc );
//|-------->      END      <--------|

int main_Multiplication_Division_Addition_Subtraction(int argc)
{
    int myInt;
    //
    myInt = 26 % 6 * 5;
    printf( "myInt 26 mod 6 times 5---> %d\n", myInt);
    myInt = 3 * 2;
    printf( "myInt ---> %d\n", myInt );
    //
    myInt += 1;
    printf( "myInt ---> %d\n", myInt );
    //
    myInt -=5;
    printf( "myInt ---> %d\n", myInt );
    //
    myInt *= 10;
    printf( "myInt ---> %d\n", myInt );
    //
    myInt /= 4;
    printf( "myInt ---> %d\n", myInt );
    //
    myInt /= 2;
    printf( "myInt ---> %d\n", myInt );
    //
    return myInt;
}

