//
//  eg-__1-implicit-typecasting.c
//  chap-13
//
//  Created by Jaran F on 25/04/2019.
//
#include <stdio.h>
#include <assert.h>

//|--------> FN PROTOTYPES <--------|
void main_implicit_typecasting( void );
//|-------->      END      <--------|

void main_implicit_typecasting() {
    float f;
    int i;
    f = 3.5;
    i = f;
    printf( "i is equal to %d\n", i );
    assert(i == 3);
}
