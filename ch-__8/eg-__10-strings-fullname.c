//
//  eg-__10-strings-fullname.c
//  chap-__8
//
//  Created by Jaran F on 09/04/2019.
//
#include <stdio.h>
#include <string.h>

//|--------> FN PROTOTYPES <--------|
void main_strings_PrintFullName( char* firstName, char* lastName );
//|-------->      END      <--------|

void main_strings_PrintFullName( char* firstName, char* lastName )
{
    char fullName[20];
    strcpy( fullName, lastName );
    strcat( fullName, ", " );
    strcat( fullName, firstName );
    printf( "full name: %s\n", fullName );
}
