//
//  eg-__3a-more-struct-tryouts.c
//  chap_-10
//
//  Created by Jaran F on 10/10/2018.
//
#include <stdio.h>
#include <string.h>

//|--------> FN PROTOTYPES <--------|
void main_more_struct_tryouts( void );
//|-------->      END      <--------|

void main_more_struct_tryouts()
{
    struct MyStruct {           // defined in scope of this fn, this struct can't be used in another
        int i;                  // functions scope. If you try you get 'Variable has incomplete type struct BLAH' error
        long int l;
        float f;
    } aStruct;                  // Shorthand way: define struct and assign at same time.
    aStruct.i = 10;
    aStruct.l = 21423215691;
    aStruct.f = 25.4;
    
    struct MyStruct bStruct;    // The longhand way of variable assignment for a struct.
    bStruct = aStruct;          // Shorthand for copying one struct to another.
    
    struct MyStruct arrStruct[ 3 ];   //Structs and Arrays
    arrStruct[ 0 ].i = 100;
    arrStruct[ 0 ].l = -21423215691;
    arrStruct[ 0 ].f = 254.01;
    
    struct DVDInfo {
        char rating;
        char comment[ 256 ];
    } arrDVDCollection[ 3 ];
    
    arrDVDCollection[ 0 ].rating = '8';
    strcpy(arrDVDCollection[ 0 ].comment, "Good DVD");
    printf("%s\n", arrDVDCollection[ 0 ].comment);
}
