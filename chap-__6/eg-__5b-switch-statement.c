//
//  eg-__5b-switch-statement.c
//  chap-__6
//
//  Created by Jaran F on 11/01/2015.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//|--------> FN PROTOTYPES <--------|
uint main_switch_with_empty_case_fixed_statement( void );
void Hard_BoilThem( void );
void Make_AnOmelet( void );
void Make_FrenchToastForEveryone( void );
void MakeCereal( void );
void GoOutForBreakfast( void ) ;
//|-------->      END      <--------|

bool hasMilk = true;

uint main_switch_with_empty_case_fixed_statement()
{
    uint numberOfEggs;
    srand( (uint) time(NULL) );
    numberOfEggs = rand() % 4;
    //
    printf("numberOfEggs = %d\n", numberOfEggs);
    switch (numberOfEggs) {
        case 0:
            if (hasMilk)
                MakeCereal();
            else
                GoOutForBreakfast();
            break;
        case 1:
        case 2:
            Hard_BoilThem();
            break;
        case 3:
            Make_AnOmelet();
            break;
        default:
            Make_FrenchToastForEveryone();
    }
    return numberOfEggs;
}

void Hard_BoilThem()
{
    printf("Hardboil the eggs");
}

void Make_AnOmelet()
{
    printf("Make an omelet");
}

void Make_FrenchToastForEveryone()
{
    printf("Make French Toast for everyone");
}

void MakeCereal()
{
    printf("Make cereal");
}

void GoOutForBreakfast()
{
    printf("Go out for breakfast");
}


