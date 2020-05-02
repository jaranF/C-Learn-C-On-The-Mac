//
//  eg-__1a-float-sizer_accuracy.c
//  chap-__8
//
//  Created by Jaran F on 31/12/2016.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void main_float_accuracy();
//|-------->      END      <--------|

void main_float_accuracy( void )
{
    float myFloat;
    double myDouble;
    long double myLongDouble;      // 3.1415926535897932384626433832795028841972
    //
    myFloat = 3.1f;
    myDouble = 30000.1415926535897;
    myLongDouble = 30000.1415926535897L;    // NB The 'L' as end of literal.
    //
    printf("     myFloat =       %f\n", myFloat);
    printf("    myDouble =       %f\n", myDouble);
    printf("myLongDouble =       %Lf\n\n", myLongDouble);
    printf( "sizeof( float ) = %zu\n", sizeof (myFloat) );
    printf( "sizeof( myDouble ) = %zu\n", sizeof (myDouble) );
    printf( "sizeof( float ) = %zu\n", sizeof (myLongDouble) );
    printf("     myFloat - 3.141592 =       %25.16f\n", myFloat - 3.1);
    printf("    myDouble - 3.141592 =       %f\n", myDouble - 30000.1415926535897);
    printf("myLongDouble - 3.141592 =       %Lf\n\n", myLongDouble - 30000.1415926535897);
}
