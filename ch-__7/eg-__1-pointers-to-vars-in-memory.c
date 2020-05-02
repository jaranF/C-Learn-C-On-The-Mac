//
//  eg-__1-pointers-to-vars-in-memory.c
//  chap-__7
//
//  Created by Jaran F on 10/02/2016.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
int main_pointers_to_vars_in_memory( void );
//|-------->      END      <--------|

int main_pointers_to_vars_in_memory()
{
    int *myPointer;
    int myVar;
    
    myVar = 0;
    myPointer = &myVar;
    *myPointer = 27;
    *myPointer *= 2;
    printf("myVar = %d\n", myVar);
    return 0;
}

