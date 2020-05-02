//
//  eg-__1-float-sizer-format-modifiers.c
//  chap-__8
//
//  Created by Jaran F on 31/12/2016.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void main_float_sizer_format_modifiers( void );
//|-------->      END      <--------|

void main_float_sizer_format_modifiers( void )
{
  float myFloat;
  double myDouble;
  long double myLongDouble;
  //
  myFloat = 1234.567890123456789f;
  myDouble = 1234.567890123456789;
  myLongDouble = 1234.567890123456789L;
  //
  printf("     myFloat =       %25.16f\n", myFloat);            // %f
  printf("    myDouble =       %25.16f\n", myDouble);           // %f
  printf("myLongDouble =       %25.16Lf\n\n", myLongDouble);    // %25.16Lf
}

