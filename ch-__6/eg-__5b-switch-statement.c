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
uint main_switch_with_chars();
//|-------->      END      <--------|

uint main_switch_with_chars()
{
    uint letterOfAlphabet;
    srand( (uint) time(NULL) );
    letterOfAlphabet = 65 + (rand() % 26);
    //
    printf("Randomly picked Letter Of Alphabet = %c\n", letterOfAlphabet);
    switch (letterOfAlphabet) {
        case 'A':
            printf("A is a vowel!");
            break;
        case 'E':
            printf("E is a vowel!");
            break;
        case 'I':
            printf("I is a vowel!");
            break;
        case 'O':
            printf("O is a vowel!");
            break;
        case 'U':
            printf("U is a vowel!");
            break;
    }
    return letterOfAlphabet;
}


