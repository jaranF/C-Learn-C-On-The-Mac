//
//  eg-__5a-switch-statement.c
//  chap-__6
//
//  Created by Jaran F on 11/01/2015.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//|--------> FN PROTOTYPES <--------|
uint main_switch_with_empty_case_statement();
void HardBoilThem( void );
void MakeAnOmelet( void );
void MakeFrenchToastForEveryone( void );
//|-------->      END      <--------|

uint main_switch_with_empty_case_statement()
{
    uint numberOfEggs;
    srand( (uint) time(NULL) );
    numberOfEggs = rand() % 4;
    //
    printf("numberOfEggs = %d\n", numberOfEggs);
    switch (numberOfEggs) {
        case 1:
        case 2:
            HardBoilThem();
            break;
        case 3:
            MakeAnOmelet();
            break;
        default:
            MakeFrenchToastForEveryone();
    }
    return numberOfEggs;
}

void HardBoilThem() {
    printf("Hardboil the eggs");
}

void MakeAnOmelet() {
    printf("Make an omelet");
}

void MakeFrenchToastForEveryone() {
    printf("Make French Toast for everyone");
}



