//
//  eg-__7-static-vars-in-functions.c
//  chap-__7
//
//  Created by Jaran F on 09/08/2019.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void main_static_vars_in_functions( void );
static int StaticFunc( void ); // The static keyword here is just so I can have duplicate
                               // functions with the same name (see the other static var
                               // file, 'eg-__7a-static-complex-type-vars-in-functions.c').
                               // It has nothing to so with the static var 'myCounter'.
//|-------->      END      <--------|

void main_static_vars_in_functions()
{
    int	i=0;
    
    for ( i=1; i<=5; i++ )
        printf("%d\n", StaticFunc());
}

static int StaticFunc()
{
    static unsigned int myCounter = 5;
    return ++myCounter;
}
