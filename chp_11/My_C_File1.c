//
//  My_C_File1.c
//  chap-11
//
//  Created by Jaran F on 31/07/2019.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void main_fn_prototypes_and_extern_without_header ( void );
//|-------->      END      <--------|


// POINT 1: FUNCTION PROTOTYPE DEFINITIONS
// ---------------------------------------
// NB 'Fn_My_Function2()' is defined elsewhere but you call it from here. Note how if you do not
// have the function prototype defined BEFORE the call you get a compile-time warning:
// 'Implicit declaration of function 'Fn_My_Function2()' is invalid in C99.
int Fn_My_Function2( void );
// POINT 2: THE STATIC KEYWORD
// ---------------------------
// If the line above has the keyword 'static' prepended then the compiler will complain with:
// "Function 'Fn_My_Function2()' has internal; linkage but is not defined"
// 'Static' means expect the definition (i.e. function body to be in this file aka 'translation unit').
// POINT 3: WHERE FUNCTION PROTOTYPE DEFINITIONS GO
// ------------------------------------------------
// So this file, 'My_C_File1.c' calls 'Fn_My_Function2()' in the other '.c' file and that second function
// calls 'Fn_My_Function3()' but if you were to think that you could get away with putting the function proto
// -type definition 'int Fn_My_Function3( void )' here you'd be wrong; just because the execution path
// starts here and end up calling 'Fn_My_Function3()' doesn't mean that the prototype should go here.
// Rather, it's the file that directly calls the 'Fn_My_Function3()' function that should have the
// function prototype definition.
// POINT 4: THE 'EXTERN' KEYWORD WHICH DOES NOTHING
// ------------------------------------------------
// The extern keyword makes no difference. So if we delete the function prototype definition from the
// top of 'My_C_File2.c' and uncomment the line below then there is still a compile warning.
// extern int Fn_My_Function3( void );
void main_fn_prototypes_and_extern_without_header()
{
    int num = Fn_My_Function2();
    printf("%d\n", num);
}

