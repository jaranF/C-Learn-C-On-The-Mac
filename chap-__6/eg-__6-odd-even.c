//
//  eg-__6-odd-even.c
//  chap-__6
//
//  Created by Jaran F on 09/02/2016.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
int main_odd_or_even( void );
//|-------->      END      <--------|

int main_odd_or_even()
{
    int i;
    //
    for (i = 1; i <= 20; i++) {
        printf("\nThe number %d is ", i);
        
        if ((i % 2) == 0) {
            printf("even");
            continue;
        }
        printf("odd");
        if ((i % 3) == 0)
            printf(" and is a multiple of 3");
    }
    return 0;
}


