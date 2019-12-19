//
//  eg-__1-float-sized-exponential-format.c
//  chap-__8
//
//  Created by Jaran F on 31/12/2016.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void main_float_sizer_exponential_format( void );
//|-------->      END      <--------|

void main_float_sizer_exponential_format( void )
{
  float myFloat;
  double myFloat_G_format;
  float myFloatLarge;
  double myDouble;
  long double myDoubleFloat;
  //
  myFloat = 1234.5678e+04;       //12345678.000
  myFloat_G_format = 12345.6789;
  myFloatLarge = 123456789.0;
  //
  printf("         myFloat = %.3f\n", myFloat);
  printf("myFloat_G_format = %g\n", myFloat_G_format);
  printf("    myFloatLarge = %g\n", myFloatLarge);
  printf("    myFloatLarge = %.8g\n", myFloatLarge);
  printf("    myFloatLarge = %.7g\n", myFloatLarge);
  printf("    myFloatLarge = %.6g\n", myFloatLarge);
  printf("    myFloatLarge = %.5g\n", myFloatLarge);
  printf("    myFloatLarge = %.4g\n", myFloatLarge);
  printf("    myFloatLarge = %.3g\n", myFloatLarge);
  printf("\n\n");
  myFloat = 1234.567890123456789f;
  myDouble = 1234.567890123456789;
  myDoubleFloat = 1234.567890123456789L;
  //
  printf("     myFloat  = %.20g\n", myFloat);
  printf("     myDouble = %.20g\n", myDouble);
  printf("myDoubleFloat = %Lf", myDoubleFloat);
  printf("\n\n");
}

