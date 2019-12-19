//
//  eg-__5-switch-statement.c
//  chap-__6
//
//  Created by Jaran F on 10/01/2015.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//|--------> FN PROTOTYPES <--------|
uint main_switch_statement( void );
//|-------->      END      <--------|

uint main_switch_statement()
{
    uint i, theYear;
    uint historicDates[4];
    historicDates[0] = 1066;
    historicDates[1] = 1492;
    historicDates[2] = 1776;
    historicDates[3] = 1984;
    srand( (uint) time(NULL) );
    i = rand() % 4;
    theYear = historicDates[i];
    //
    printf("theYear = %d\n", theYear);
    switch ( theYear ) {
        case 1066:
            printf("Battle of Hastings");
            break;
        case 1492:
            printf("Columbus sailed the ocean blue");
            break;
        case 1776:
            printf("Declaration of Independence\n");
            printf("A very important document!!!");
            break;
        default:
            printf("Don't know what happened during this year");
    }
    printf("\n");
    return i;
}


