//
//  eg-__8-dice2.c
//  chap-__8
//
//  Created by Jaran F on 06/09/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//|-----------> DEFINES <-----------|
#define kDiceSides                  6
#define kLowestRoll                 (1*2)
#define kHighestRoll                (kDiceSides*2)
#define kRollArraySize              (kHighestRoll+1)
#define kRolls                      1000
//|--------> FN PROTOTYPES <--------|
void main_dice3( void );
static void PrintRolls2( int[], long long, size_t );
static void PrintX2( int );
//|-------->      END      <--------|

void main_dice3()
{
    int  i, twoDice;
    //rolls = (int*)calloc(kRolls, sizeof(int));
    int* rolls;
    // int rolls[kRolls];
    //
    rolls = (int*)calloc(kRolls, sizeof(int));
    for (i = 1; i <= kRolls; i++) {
        srand( (int unsigned)clock() );
        twoDice = ( ((rand() % kDiceSides) + 1) + ((rand() % kDiceSides) + 1));
        rolls[twoDice]++;
    }
    PrintRolls2(rolls, kLowestRoll, kRollArraySize);
}

void PrintRolls2(int arrDiceThrowTallies[], long long startAt, size_t size)
{
    long long i;
    //
    for (i = startAt; i < size; i++) {
        printf("%2.0lld (%3d):  ", i, arrDiceThrowTallies[i]);
        PrintX2( arrDiceThrowTallies[ i ] / 10 );
        putchar('\n');
    }
}

void PrintX2 (int howMany)
{
    for (int i = 1; i <= howMany; i++)
        putchar( 'X' );
}
