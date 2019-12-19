//
//  eg-__2-logic-comparison-operators.c
//  chap-__6
//
//  Created by Jaran F on 01/01/2015.
//
#include <stdio.h>
#include <stdbool.h>

//|--------> FN PROTOTYPES <--------|
int main_logic_comparison_operators( void );
//|-------->      END      <--------|

int main_logic_comparison_operators()
{
    bool hasCar, hasTimeToGiveRide;
    //
    hasCar = true;
    hasTimeToGiveRide = true;
    //
    if ( hasCar && hasTimeToGiveRide )
        printf("Hop in - I'll give you a ride!\n");
    else
        printf("I've either got no car, no time, or both!\n");
    //
    //
    bool nothingElseOn, newEpisode, itsARerun;
    //
    nothingElseOn = true;
    newEpisode = true;
    //
    if (newEpisode || nothingElseOn)
        printf("Let's watch Family Guy!\n");
    else
        printf("Something else is on or I've seen this one.\n");
    //
    nothingElseOn = true;
    itsARerun = false;
    //
    if (nothingElseOn || (!itsARerun))
        printf("Let's watch Family Guy!\n");
    else
        printf("Something else is on or I've seen this one.\n");
    //
    return 0;
}


