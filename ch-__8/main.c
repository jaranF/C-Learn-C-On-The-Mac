//
//  main.c
//  chap-__8
//
//  Created by Jaran F on 31/12/2016.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void main_float_sizer();
void main_float_accuracy();
void main_float_sizer_format_modifiers( void );
void main_float_sizer_more_modifiers( void );
void main_float_sizer_exponential_format( void );
void PrintChars ( int from, int to );
void main_dice( void );
void main_dice2( void );
void main_dice3( void );
void main_dice_with_arrays_passed( void );
void main_understanding_passing_arrays_and_strings( void );
void main_strings_PrintFullName( char* firstName, char* lastName );
void main_strings_PrintFullName_boundary_check( char* firstName, char* lastName );
void main_strings_strncpy_expermiments( void );
//|------->      END      <--------|

int main(int argc, const char * argv[]) {
    // main_float_sizer();
    // main_float_accuracy();
    // main_float_sizer_format_modifiers();
    // main_float_sizer_more_modifiers();
    // main_float_sizer_exponential_format();
    // PrintChars ( 47, 57);
    // main_dice();
    main_dice3();
    // main_dice_with_arrays_passed();
    // xrolls = (int*)calloc(kRolls, sizeof(int));main_understanding_passing_arrays_and_strings();
    // main_strings_PrintFullName( "David", "Mark" );
    // main_strings_PrintFullName( "James", "Bucanek" );
    // main_strings_PrintFullName_boundary_check("Wilhelmina", "Romanawski");
    // main_strings_strncpy_expermiments();
    return 0;
}

