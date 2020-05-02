//
//  eg-__4-do-statement.c
//  chap-__6
//
//  Created by Jaran F on 10/01/2015.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
int main_do_statement( void );
//|-------->      END      <--------|

int main_do_statement()
{
    int i;
    do {
        printf("%d\n", i);
        i++;
    } while (i < 3);
    printf("We are now passed the do loop.");
    //
    return i;
}


