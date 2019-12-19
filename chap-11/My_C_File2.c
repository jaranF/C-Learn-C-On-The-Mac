//
//  My_C_File2.c
//  chap-11
//
//  Created by Jaran F on 31/07/2019.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
int Fn_My_Function3( void );
//|-------->      END      <--------|

int Fn_My_Function2()
{
    Fn_My_Function3();
    return 5678;
}

int Fn_My_Function3()
{
    return 34;
}
