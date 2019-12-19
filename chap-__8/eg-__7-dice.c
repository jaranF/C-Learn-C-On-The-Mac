//
//  eg-__7-dice.c
//  chap-__8
//
//  Created by Jaran F on 03/01/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//|--------> FN PROTOTYPES <--------|
void main_dice( void );
void PrintRolls(int[], size_t);
void PrintX(int);
//|------->      END      <--------|

void main_dice()
{
    int  i, twoDice;
    int rolls[1000];
    //
    for (i = 0; i < 1000; i++ ) {
        rolls[i] = 0; // alternatively use calloc instead.
    }
    //
    for (i = 1; i <= 1000; i++) {
        srand( (int unsigned)clock() );
        twoDice = ( ((rand() % 6) + 1) + ((rand() % 6) + 1)) - 2;
        rolls[twoDice]++;
    }
    //
    PrintRolls(rolls, 10);
}

void PrintRolls(int arrDiceThrowTallies[], size_t size)
{
    int i;
    for (i = 0; i <= size; i++) {
        printf("%2.0d (%3d):  ", i + 2, arrDiceThrowTallies[i]);
        PrintX( arrDiceThrowTallies[ i ] / 10);
        putchar('\n');
    }
}

void PrintX (int howMany)
{
    for (int i = 1; i <= howMany; i++)
        putchar( 'X' );
}
