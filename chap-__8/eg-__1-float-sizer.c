//
//  eg-__1-float-sizer.c
//  chap-__8
//
//  Created by Jaran F on 31/12/2016.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void main_float_sizer();
//|-------->      END      <--------|

void main_float_sizer( void )
{
  float myFloat;
  double myDouble;
  long double myLongDouble;
  //
  myFloat = 1234.567890123456789f;
  myDouble = 1234.567890123456789;
  myLongDouble = 1234.567890123456789L;
  //
  printf( "sizeof( float ) = %zu\n", sizeof (myFloat) );
  printf( "sizeof( myDouble ) = %zu\n", sizeof (myDouble) );
  printf( "sizeof( float ) = %zu\n", sizeof (myLongDouble) );
  //
  printf("     myFloat =       %f\n", myFloat);         // %f
  printf("    myDouble =       %f\n", myDouble);        // %f
  printf("myLongDouble =       %Lf\n\n", myLongDouble); // %Lf
}
