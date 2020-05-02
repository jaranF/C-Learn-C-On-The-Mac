//
//  eg-__9-understanding-passing-arrays-and-strings.c
//  chap-__8
//
//  Created by Jaran F on 09/03/2019.
//
#include <stdio.h>
#include <string.h>  // strlen & strcpy
#include <stdlib.h>  // malloc

//|--------> FN PROTOTYPES <--------|
void main_understanding_passing_arrays_and_strings( void );
void print_number_sequence( int[], size_t );
char* str_copy_and_reverse( const char* );
char* str_accept_input_and_scramble( void );
//|-------->      END      <--------|

/* BELOW SYNTAX INVALID BECAUSE ARRAYS CAN'T BE RETURNED

char[] str_copy_and_reverse( const char* );

... Instead pass back pointer

char* str_copy_and_reverse( const char* immutableInput );
*/

void main_understanding_passing_arrays_and_strings()
{
    int fibonnaci[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    print_number_sequence(fibonnaci, 10);
    // printf("result = %s \n", str_copy_and_reverse("abcdef" ));
    printf("result = %s \n", str_copy_and_reverse(("GOODBYE")) );
}

void print_number_sequence(int numbers[], size_t arrLen)   // Passing an array in as param.
{                                                          // Note you have to pass the len
    size_t i = arrLen;                                     // of the array in as there isn't
    while (i > 0) {                                        // a '.length' you can use.
        printf("[%zu.] %d\n", i, numbers[i -1 ]);
        i--;
    }
}

/* The function below returns a char pointer for a newly minted string that originates in 
   this function but one that had to be defined with 'malloc' because it's length at compile
   time was unknown and is dependent on the size of the string passed in. */
char* str_copy_and_reverse( const char* immutableInput )
{
    size_t i = strlen(immutableInput) + 1; // +1 to allow for terminating NULL char.
    char* buffPtr = (char*)(malloc(i--));  // Take off one so that when gets to while loop
    int j = 0;                             // pointer points to last actual char of the
                                           // immutableInput not it's termimating NULL char.
    while (i > 0) {                        // Remember array indexes are zero-based so have
        buffPtr[j] = immutableInput[--i];  // to subtract one to get correct char from
        j++;                               // 'immutableInput' index BEFORE accessing it.
    }
    buffPtr[j] = '\0';
    return buffPtr;
}

char* str_accept_input_and_scramble()
{
    static char buff[4];
    printf("Enter a three char long country code\n");
    scanf("%3[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMOPQRSTUVWXYZ]", buff);
    buff[3] = '\0';
    int i = 0;
    char c;         //  8421 8421
    // A =  65 = 0x41 | 0100 0001
    // a =  97 = 0x61 | 0110 0001
    // Z =  90 = 0x5a | 0101 1010
    // z = 122 = 0x7a | 0111 1010
    while ((c = buff[i])) {
        if (c == 'z' || c == 'Z') {
            c -= 25;
        } else {
            c++;
        }
        i++;
    }
    return buff;  // Note the shorthand here; there is no intermediary:
                  // char* buffPtr = buff; // or longhand char* buffPtr = &buff[0];
}                 // ... blah de blah
                  // return buffPtr;
/*
 char* str_copy_and_reverse( const char* immutableInput ) {
 // What we learn here is that strcpy puts on the trailing NUL char for you but
 // you have to account for it in the size of the char buff[6] array size
 // Also by going from "hello" (memory = 67 64 6C 6C 6F) to "hel" places the NUL
 // i.e. \0 char at the end of "hel" but doesn't bother filling in the extra bytes
 // from where the new string's NUL appears up to the array size i.e. so.
 // before:
 // 67 64 6C 6C 6F 00
 // after:
 // 67 64 6C 00 6F 00
 
 char buff[6];
 strcpy(buff, "hello");
 strcpy(buff,"hel");
 printf("len = %zu", strlen(buff));
 //return buff;
 
 char* buffPtr = buff; // Shorthand for buffPtr = &buff[0];
 return buffPtr;
 
 }

*/

