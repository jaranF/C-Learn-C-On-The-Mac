//
//  eg-__3-implicit-typecasting-and-function-signatures.c
//  chap-13
//
//  Created by Jaran F on 22/06/2019.
//
#include <stdio.h>
#include <math.h>

//|--------> FN PROTOTYPES <--------|
void main_implicit_typecasting_and_function_signatures( void );
double exp2proxyFn( double a);
//|-------->      END      <--------|

void main_implicit_typecasting_and_function_signatures() {
    double z = exp2(1.0);
    printf("Without typecasting, straightup \'exp2(1.0)\' = %10.8f\n", z);
    unsigned long ulong = exp2proxyFn(3.1412);
    printf("With typecasting \'int i = exp2(3.1412)\' = %zu\n", ulong); // Expect 8
}

double exp2proxyFn( double a) {
    double e = exp2(a);
    return e;
}
