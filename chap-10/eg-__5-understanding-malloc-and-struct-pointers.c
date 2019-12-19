//
//  eg-__5_understanding-malloc-and-struct-pointers.c
//  chap_10
//
//  Created by Jaran F on 12/10/2018.
//
// This malloc memory allocation function:
// struct DVDinfo *myDVDPointer = (struct DVDinfo *)malloc( sizeof( struct DVDinfo ) );
//
// This calloc memory allocation function
// struct DVDinfo *myDVDLinkedListPtr = (struct DVDinfo *)calloc(5, sizeof( struct DVDinfo ) );
// ... Note that the first arg to 'calloc()' specifies how many structs you want. i.e. in this case for 5 DVDs.
// Remember when using malloc or calloc to use free(MyPointer) before the function using it ends.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//|-----------> DEFINES <-----------|
#define kMaxDVDs                    4
#define kMaxTitleLength             256
#define kMaxCommentLength           256
//|-----------> STRUCTS <-----------|
struct DVDinfo {
    char rating;
    char title[ kMaxTitleLength ];
    char comment[ kMaxCommentLength ];
};
//|--------> FN PROTOTYPES <--------|
void main_understanding_malloc_and_struct_pointers( void );
//|-------->      END      <--------|

void main_understanding_malloc_and_struct_pointers()
{
    struct DVDinfo myFirstDVD;
    struct DVDinfo *myFirstDVDPtr;
    //
    myFirstDVD.rating = '7';
    strcpy(myFirstDVD.title, "Toy Story 2");
    strcpy(myFirstDVD.comment, "Lorem ipso sed amet");
    // Ok, above we defined a variable to hold a struct as per usual above.
    // Below, experiment with using pointers on said struct variable.
    myFirstDVDPtr = &myFirstDVD;
    (*myFirstDVDPtr).rating = '9';
    strcpy((*myFirstDVDPtr).title, "Toy Story 3");
    //
    // Now define mySecondDVD using malloc to get the pointer to the struct
    struct DVDinfo *mySecondDVDPtr = (struct DVDinfo *)malloc( sizeof( struct DVDinfo ) );
    mySecondDVDPtr->rating = '9';
    strcpy((*mySecondDVDPtr).title, "Wicked");
    strcpy(mySecondDVDPtr->comment, "Based on the musical");
    //
    int* iPtr = malloc(sizeof(int));    // Declaring a pointer & assigning via 'malloc()' in one line.
    iPtr = calloc(1, sizeof(int));    // Calloc reserves n bytes of memory and fills it with zeros
    free(mySecondDVDPtr);
    free(iPtr);
}




