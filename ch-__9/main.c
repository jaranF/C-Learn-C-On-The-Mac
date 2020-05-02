//
//  main.c
//  chap-__9
//
//  Created by Jaran F on 20/01/2017.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
int main_seeArgs( int, const char* argv[] );
void namer( void );
void main_pointer_arithmetic_equality( void );
void main_pointer_arithmetic_addition( void );
void main_pointer_arithmetic_subtraction( void );
int main_pointer_arithmetic_equivalency( void );
void main_pointer_equivalency_with_chars( void );
int main_scanf_used_to_read_in_integers( void );
int main_scanf_read_keyinput_len_restricted( void );
int main_scanf_read_in_alpha_chars_only( void );
int main_word_count( void );
void ReadLine( char* );
int CountWords( char* );
void main_cross_assigning_ints_to_chars( void );
void main_pointers_and_strings_boundary_overruns( void );
char* main_roman_numerals_5a( void );
char* main_roman_numerals_5b( void );
void NumberToRomanNumeral( int number, char *romanNumeral );
int main_roman_numerals( int, const char * argv[] );
//|------->      END      <--------|

int main(int argc, const char * argv[])
{
    // main_seeArgs(argc, argv);
    // namer();
    // main_pointer_arithmetic_equality();
    // main_pointer_arithmetic_addition();
    // main_pointer_arithmetic_equivalency();
    main_pointer_equivalency_with_chars();
    // printf("The return int value of \'scanf()\' is %1d\n", main_scanf_used_to_read_in_integers());
    // printf("The return int value of \'scanf()\' is %1d\n", main_scanf_read_keyinput_len_restricted());
    // main_word_count();
    // main_cross_assigning_ints_to_chars();
    // main_pointers_and_strings_boundary_overruns();
    // main_scanf_read_keyinput_len_restricted();
    // main_scanf_read_in_alpha_chars_only();
    // main_roman_numerals_5a();
    // main_cross_assigning_ints_to_chars();
    // main_roman_numerals_5b();
    // main_roman_numerals( argc, argv );
    return 0;
}

