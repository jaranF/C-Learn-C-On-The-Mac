//
//  eg-__3-operators-postfix.c
//  chap-__4
//
//  Created by Jaran F on 29/12/2014.
//
#include <stdio.h>
//|--------> FN PROTOTYPES <--------|
int main_Postfix_Prefix_Addition_Subtraction( int argc );
//|-------->      END      <--------|

int main_Postfix_Prefix_Addition_Subtraction(int argc)
{
    int myInt = 5;
    //
    myInt *= 3;
    //
    printf( "myInt ---> %d\n", myInt );
    printf( "myInt ---> %d\n", myInt++ );
    printf( "myInt ---> %d\n", ++myInt );
    return 0;
}
