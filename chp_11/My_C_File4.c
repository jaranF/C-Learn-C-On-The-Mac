//
//  My_C_File4.c
//  chap-11
//
//  Created by Jaran F on 06/08/2019.
//
#include "My_C_File4.h"

//|--------> FN PROTOTYPES <--------|
void main_fn_prototypes_and_extern_with_header ( void );
//|-------->      END      <--------|

// POINT 5: EXTERN WITH HEADER FILES
// ---------------------------------------
// The point made in point 4 about the extern keyword holds true with headers as well; namely that it is
// a red herring in C99 and is always implied anyway.
// POINT 6: STATIC FUNCTIONS WITH HEADER FILES
// -------------------------------------------
// Avoid 'static' in header files like the plague because using it kills the potential for header file
// sharing and re-use. If 'Fn_My_Function5()' was static then this '.c' file would have to define that
// function (as well is in 'My_C_File5.c' which also pulls in this header. It would be 'Fn_My_Function5()'
// in this file that gets executed; the other one would be left dangling with the compiler complaining of
// an unused function.
// POINT 7: DUPLICATE FUNCTION NAMES
// ---------------------------------
// Notwithstanding the above, a static could be useful if you wanted two function names with the same name
// in two different '.c' files as without the static keyword the compiler barfs.

void main_fn_prototypes_and_extern_with_header()
{
    int num = Fn_My_Function5();
    printf("%d\n", num);
}

//int Fn_My_Function5() {
//    return 5;
//}
