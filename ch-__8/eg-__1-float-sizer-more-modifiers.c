//
//  eg-__1-float-sizer-more-modifiers.c
//  chap-__8
//
//  Created by Jaran F on 31/12/2016.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void main_float_sizer_more_modifiers( void );
//|-------->      END      <--------|

void main_float_sizer_more_modifiers( void )
{
  float myFloat;
  myFloat = 1234.567890123456789f;
  //
  printf("myFloat = %10.1f\n", myFloat);  // %10.1f
  printf("myFloat = %.2f\n",   myFloat);  // %.2f
  printf("myFloat = %.12f\n",  myFloat);  // %.12f
  printf("myFloat = %.9f\n",   myFloat);  // %.9f
}

