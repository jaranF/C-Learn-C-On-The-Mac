//
//  eg-__3-introducing-struct.c
//  chap_10
//
//  Created by Jaran F on 27/01/2017.
//  The project for this example is called "StructSize" in the book
#include <stdio.h>
#include <string.h>
#include "DVDTracker.h"
#include "StructSize.h" // In the book's source code the include file is called "StructSize.h"

//|--------> FN PROTOTYPES <--------|
void main_introducing_struct( void );
//|-------->      END      <--------|

void main_introducing_struct()
{
    struct DVDinfo myInfo;      // Note the struct is defined in header file.
    myInfo.rating = 7;          // Dot notation to assign a value to property.
    struct MyStruct aStruct, bStruct; // Defining multiple variable names to use the same struct
    aStruct.i = 214748364;
    aStruct.l = 1234567890;
    aStruct.f = 3.141;
    //
    bStruct = aStruct;          // Copying one struct to another. A shortcut for the below
    //
    printf("\nbStruct.i (i.e. an int) = %d", bStruct.i);
    printf("\nbStruct.l (i.e. an long) = %ld", bStruct.l);
    printf("\nbStruct.f (i.e. a float) = %5.3f\n", bStruct.f);
    //example 2 copying one struct over to another
}
