//
//  eg-__11-strings-fullname-boundaries-safety-check.c
//  chap-__8
//
//  Created by Jaran F on 09/04/2019.
//
#include <stdio.h>
#include <string.h>

//|--------> FN PROTOTYPES <--------|
void main_strings_PrintFullName_boundary_check( char* firstName, char* lastName );
//|-------->      END      <--------|

void main_strings_PrintFullName_boundary_check( char* firstName, char* lastName )
{
    char fullName[20];
    strlcpy( fullName, lastName, sizeof(fullName) );
    strlcat( fullName, ", ", sizeof(fullName) );
    strlcat( fullName, firstName, sizeof(fullName) );
    printf( "full name: %s\n", fullName );
}
