//
//  eg-__4-passing-structs-as-args.c
//  chap_-10
//
//  Created by Jaran F on 10/10/2018.
//  If you pass a struct in by value you pass in a copy so it's change safe but if you pass in by reference it is
//  not change safe. To tell the compiler that your struct shouldn;t be changed used the 'const' keyword. If you
//  used 'const'  and attempted a change you'd get a compiler errpr 'read-only variable is not assignable'.
//
#include <stdio.h>
#include "DVDTracker.h"
#include <string.h>

//|--------> FN PROTOTYPES <--------|
void main_passing_structs_as_args( void );
void PrintDVD( struct DVDinfo *DVDStructPtr, int );
void PassBy_Value_And_Alter( struct DVDinfo );
void PassBy_Ref_And_Alter(/* const */ struct DVDinfo *DVDStructPtr); // Use const (see chap 13) to mark struct as immutable.
//|-------->      END      <--------|

void main_passing_structs_as_args()
{
    struct DVDinfo myFirstDVD;
    myFirstDVD.rating = '7';
    strcpy(myFirstDVD.comment, "A great musical");
    strcpy(myFirstDVD.title, "Wicked");
    //
    PrintDVD(&myFirstDVD, 0);
    printf("After pass by value and attempt alteration\n");
    // EXPERIMENT 1.
    // What happens if a struct is passed by value and function it's past to attempts a change on that struct param?
    PassBy_Value_And_Alter(myFirstDVD);
    PrintDVD(&myFirstDVD, 10);
    // CONCLUSION
    // Passing by value, passes A COPY in as the parameter to the receiving function and so changes there are isolated.
    // EXPERIMENT 2
    // What happens if a struct is passed by reference and function it's past to attempts a change on that struct param?
    PassBy_Ref_And_Alter(&myFirstDVD);
    printf("After pass by reference and attempt alteration\n");
    PrintDVD(&myFirstDVD, 14);
}
// In Chapter 13 the 'const' keyword is introduced which would be useful here as it is
// obvious that printing a struct shouldn't chage it. i.e. void PrintDVD(const struct ...
void PrintDVD(struct DVDinfo *DVDStructPtr, int indentAmount)
{
    char c = indentAmount ? ' ' : '\b'; // NB the '%*c' field formatter placeholder. See c-faq.com/stdio/printfvwid.html
    printf("%*cRating = %c\n", indentAmount, c, (*DVDStructPtr).rating);
    printf("%*cTitle = %s\n", indentAmount, c, DVDStructPtr->title);
    printf("%*cComment = %s\n", indentAmount, c, DVDStructPtr->comment);
}

void PassBy_Value_And_Alter(struct DVDinfo localDVD)
{
    localDVD.rating = '0';
}

void PassBy_Ref_And_Alter(/* const */ struct DVDinfo *DVDStructPtr)
{
    (*DVDStructPtr).rating = '0';
}
