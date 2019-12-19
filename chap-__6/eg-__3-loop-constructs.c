//
//  eg-__3-loop-constructs.c
//  chap-__6
//
//  Created by Jaran F on 01/01/2015.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
//|-------->      END      <--------|
int main_while_and_for_statements();

int main_while_and_for_statements()
{
    int i;
    //
    i = 0;
    //
    while ( i++ < 4 )
        printf("while: i=%d\n",i);
    printf("after while loop, i=%d\n\n",i);
    //
    for ( i = 0; i < 4; i++ )
        printf("first for: i=%d\n",i);
    printf("after first for loop, i=%d\n\n",i);
    //
    for ( i = 1; i <= 4; i++ )
        printf("second for: i=%d\n",i);
    printf("after second for loop, i=%d\n\n",i);
    return 0;
}


