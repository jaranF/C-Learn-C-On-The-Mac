//
//  eg-__1a-if-experiments.c
//  chap-__6
//
//  Created by Jaran F on 31/12/2014.
//
#include <stdio.h>
#include <stdbool.h>

//|--------> FN PROTOTYPES <--------|
int main_if_experiments( void );
//|-------->      END      <--------|

int main_if_experiments()
{
    int myInt = 5;
    bool b = true;
    if (((myInt == 5) * (-1)) + (myInt == 5) && b)
        printf("true\n");
    else
        printf("false\n");
    if (myInt != (5 >= 5) && b )    //is the same as... myInt != (5 >= 5) && b
        printf("true\n");           //...or when bool cast to number  myInt != (1) && b
    else
        printf("false\n");
    //
    return 0;
}


