//
//  eg-__1a-multidimarrays-char.c
//  chap_10
//
//  Created by Jaran F on 10/06/2018.
// You can use a shorthand for creating a multi-dimensional array of chars AND numbers however you
// are constrained with the numbers you can use insofar that a char is a signed byte and can only hold
// numbers 0 to 127 and -1 to -128; and you can't mix string of chars with floats in an array.
#include <stdio.h>

//|-----------> DEFINES <-----------|
#define kCharsBufferDimensionLength 3
//|--------> FN PROTOTYPES <--------|
void main_multidimarrays_char( void );
void charMultiDimLonghand( void );
void charMultiDimShorthand( void );
void charMultiDimWithNumbers( void );
void charMultiDimWithNumbersAndOverflow( void );
//|-------->      END      <--------|

void main_multidimarrays_char()
{
    charMultiDimLonghand();
    charMultiDimShorthand();
    charMultiDimWithNumbers();
    charMultiDimWithNumbersAndOverflow();
    int romanNumerals[ 13 ][ 2 ][ kCharsBufferDimensionLength ] = {
        {{'M', '\0', '\0'},  1000},
        {{'C', 'M',  '\0'},  900},
        {{'D', '\0', '\0'}, 500},
        {{'C', 'D',  '\0'}, 400},   // Because this is declared as a int array (albeit multi-dimensional) we are allowed numbers > 127.
        {{'C', '\0', '\0'}, 100},
        {{'X', 'C',  '\0'}, 90},
        {{'L', '\0', '\0'}, 50},
        {{'X', 'L',  '\0'}, 40},
        {{'X', '\0', '\0'}, 10},
        {{'I', 'X',  '\0'}, 9},
        {{'V', '\0', '\0'}, 5},
        {{'I', 'V',  '\0'}, 4},
        {{'I', '\0', '\0'}, 1}
    };
    // The chars of the above, say 'V' or 'XL' etc. aren't stored in memory using the usual char rubric of one ASCII char per byte of
    // memory; rather they are stored as the most significant byte of however many bytes an int is worth. Say an int occupies 4 bytes
    // then 'CM' is represented as 'C' (hex 43) in memory location 0x7fff5fbff658 and 'M' (hex 4D) in location 0x7fff5fbff65c i.e.
    // 0x7fff5fbff658       43 00 00 00     C...
    // 0x7fff5fbff65C       4D 00 00 00     M...
    for (int i; i < 13; i++) {
        printf("Outer element i[%2d] : Roman Numeral : Decimal Value = %4d\n", i, romanNumerals[ i ][ 1 ][ 0 ]);
    }
}

void charMultiDimLonghand()
{
    char unitsConvTable[ 4 ][ kCharsBufferDimensionLength ] = {
        {'m', 'm', '\0'},
        {'c', 'm', '\0'},
        {'i', 'n', '\0'},
        {'f', 't', '\0'}
    };
    printf("----------------------\ncharMultiDimLonghand()\n----------------------\n");
    printf("sizeof 2 dim array \'unitsConvTable\' (outermost dimension size) = %zu\n------------------------------------------------------------------\n", sizeof(unitsConvTable) / sizeof(unitsConvTable[0]));
    for (int i = 0; i < 4; i++) {
        printf("Outer element i[%2d] : Unit Name = %c%c\n", i, unitsConvTable[ i ][ 0 ], unitsConvTable[ i ][ 1 ]);
    }
}

void charMultiDimShorthand()
{
    char unitsConvTableShorthand[ 4 ][ kCharsBufferDimensionLength ] = { /* Note the declared length of the array of chars is 3 and when the double speech marks are used you can rely on the compiler to put the trailing '\0' NULL char on the end. Hence 1 element for the 'c', another for the 'm' and the third and final element for the NUL char. */
        {"mm"},
        {"cm"},
        {"in"},
        {"ft"}
    };
    printf("\n\n%*c\ncharMultiDimShorthand()\n-----------------------\n", 23, '+');
    printf("sizeof 2 dim array \'unitsConvTable\' (outermost dimension size) = %zu\n------------------------------------------------------------------\n", sizeof(unitsConvTableShorthand) / sizeof(unitsConvTableShorthand[ 0 ]));
    for (int i = 0; i < 4; i++) {
        printf("Outer element i[ %2d ] : Unit Name = %c%c\n", i, unitsConvTableShorthand[ i ][ 0 ], unitsConvTableShorthand[ i ][ 1 ]);
    }
}

void charMultiDimWithNumbers()
{
    char unitsConvTableWithMultipliers[ 3 ][ 2 ][ kCharsBufferDimensionLength ] = {
        {{"mm"}, 1},
        {{"cm"}, 10},
        {{"in"}, 25.4}
    };
    printf("\n\n-------------------------\ncharMultiDimWithNumbers()\n-------------------------\n");
    printf("5mm    to millimeters (mm) = %5.2f mm\n", (float)(5 * unitsConvTableWithMultipliers[ 0 ][ 1 ][ 0 ]));
    printf("4cm    to millimeters (cm) = %5.2f mm\n", (float)(4 * unitsConvTableWithMultipliers[ 1 ][ 1 ][ 0 ]));
    printf("1 inch to millimeters (in) = %5.2f mm\n", (float)(1 * unitsConvTableWithMultipliers[ 2 ][ 1 ][ 0 ])); //Expect 25.00 because a char only holds whole numbers
}

void charMultiDimWithNumbersAndOverflow()
{
    char unitsConvTableWithMultipliers[ 3 ][ 2 ][ kCharsBufferDimensionLength ] = {
        {{"mm"}, 10},
        {{"cm"}, 100},
        {{"in"}, 254}
    };
    printf("\n\n------------------------------------\ncharMultiDimWithNumbersAndOverflow()\n------------------------------------\n");
    printf("5mm    to millimeters (mm) = %5.2f mm\n", (float)(5 * (unitsConvTableWithMultipliers[ 0 ][ 1 ][ 0] / 10)));
    printf("4cm    to millimeters (cm) = %5.2f mm\n", (float)(4 * (unitsConvTableWithMultipliers[ 1 ][ 1 ][ 0 ] / 10)));
    printf("1 inch to millimeters (in) = %5.2f mm\n", (float)(1 * (unitsConvTableWithMultipliers[ 2 ][ 1 ][ 0 ] / 10))); //Expect Zero . Why ? see below
    printf("Multiplier number (remember it\'s a signed byte) in the \'in\' (inches) row is %5.2f\n", (float)unitsConvTableWithMultipliers[ 2 ][ 1 ][ 0 ]);
    printf("... and -2 divided by 10 = -0.2 which gets truncated to zero as a char only holds whole numbers.\n");
}
