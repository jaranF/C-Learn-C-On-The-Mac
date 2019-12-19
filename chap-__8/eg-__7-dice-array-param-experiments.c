//
//  eg-__7-dice-array-param-experiments.c
//  chap-__8
//
//  Created by Jaran F on 11/01/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//|--------> FN PROTOTYPES <--------|
void main_dice_with_arrays_passed( void );
// NOTE how to specify when a function takes an array (more accurately a pointer to the array's memory)
// ALSO N.B.You have to pass the size of the array as well.
int doTallyRun( int[], size_t, int unsigned );
void PrintRollsParameterized( int[], size_t );
int  RollDice( int, int );
//|------->      END      <--------|

void main_dice_with_arrays_passed( void )
{
    size_t arraySize = 11;
    int duoDiceRollTallier[arraySize];
    doTallyRun(duoDiceRollTallier, arraySize, 1000);
    PrintRollsParameterized(duoDiceRollTallier, arraySize);
}

int doTallyRun(int array[], size_t size, int unsigned numOfThrows)
{
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    } // alternatively use calloc instead.
    for (int i = 0; i < numOfThrows; i++) {
        srand( (int unsigned)clock() );
        array[RollDice(2, 6) - 2]++;
    }
    return 0;
}

int RollDice(int dicePerRoll, int diceFaces)
{
    int i;
    int result = 0;
    for (i = 1; i <= dicePerRoll; i++) {
        result += (rand() % diceFaces) + 1;
    }
    return result;
}

void PrintRollsParameterized(int arrDiceThrowTallies[], size_t size)
{
    int i;
    for (i = 0; i < size; i++) {
        printf("%2.0d (%3d):    \n", i + 2, arrDiceThrowTallies[i]);
    }
}
