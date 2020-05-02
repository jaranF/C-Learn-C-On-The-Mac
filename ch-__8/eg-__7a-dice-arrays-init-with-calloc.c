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
#define kRollArraySize              (kHighestRoll+1)  // +1 because used as if were a start-index-at-one-based array (i.e. ele[0] disregarded)
#define kNumOfRolls                 1000
//|--------> FN PROTOTYPES <--------|
void main_dice3( void );
static void PrintRolls2( int[], long long, size_t );
static void PrintX2( int );
//|-------->      END      <--------|

void main_dice3()
{
    int  i, twoDice;
    //rolls = (int*)calloc(kNumOfRolls, sizeof(int));
    int* rollTallies;
    // int rolls[kNumOfRolls];
    //
    rollTallies = (int*)calloc(kRollArraySize, sizeof(int));
    for (i = 0; i < kNumOfRolls; i++) {
        srand( (int unsigned)clock() );
        twoDice = ( ((rand() % kDiceSides) + 1) + ((rand() % kDiceSides) + 1));
        rollTallies[twoDice]++;
    }
    PrintRolls2(rollTallies, kLowestRoll, kRollArraySize);
    free(rollTallies);
}

void PrintRolls2(int arrDiceThrowTallies[], long long startAt, size_t size)
{
    long long i;
    //
    for (i = startAt; i < size; i++) {
        printf("%2.0lld (%6d):  ", i, arrDiceThrowTallies[i]);
        PrintX2( arrDiceThrowTallies[ i ] / (kNumOfRolls <= 100 ? 1 : kNumOfRolls / 100));
        putchar('\n');
    }
}

void PrintX2 (int howMany)
{
    for (int i = 1; i <= howMany; i++)
        putchar( 'X' );
}
