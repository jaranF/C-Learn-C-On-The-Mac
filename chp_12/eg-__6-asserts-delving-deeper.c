//
//  eg-__6-asserts-delving-deeper.c
//  chap-12
//
//  Created by JaranF on 17/02/2020.
//

#include <stdio.h>
#include "main_eg_entry_functions.h"
// ----------------------------------
#ifdef GCC_COMPILER_MACRO_DEFINED_WITH_HYPEN_D
    #define NDEBUG
    #define kHasCUSTOM_COMPILER_FLAG    "Yes"
#endif
#ifndef GCC_COMPILER_MACRO_DEFINED_WITH_HYPEN_D
    #define kHasCUSTOM_COMPILER_FLAG    "No"
#endif

#ifdef DEBUG
    #include <assert.h>
    #define kHasDEBUG_PP_MACRO_PRESENT   2
#endif
#ifndef DEBUG
    #define kHasDEBUG_PP_MACRO_PRESENT   -1
#endif

// The second '#ifndef' block determines if the 'DEBUG' macro is present (aka 'DEBUG' #define). Xcode provides
// this by default for any 'development' flavour build (i.e. not for a release, etc, where all the code
// for different CPU architectures will be compiled.
// The first one is more intresting. You can supply custom 'macros' aka data made with '#define' as
// part of the build process (i.e. on the command line OR through Xcode's UI [Project Build settings] and
// that data can control the way the code behaves regarding conditional imports, or wether 'assert' statements
// are ignored.
//
// H O W    T O    I G N O R E    A L L    A S S E R T S    (N D E B U G)
// ======================================================================
// So if the custom macro data 'GCC_COMPILER_MACRO_DEFINED_WITH_HYPEN_D' is present, then two things happen
// in the 'ifdef' conditional macro above. Firstly, a '#define NDEBUG' macro is run and this tells the compiler
// TO IGNORE ALL 'assert()' STATEMENTS. Secondly, macro data 'kHasCUSTOM_COMPILER_FLAG' is defined with a 'Yes'
// value so we'll be told about this when the thing prints out.
//
// H O W    T O    S U P P L Y    C U S T O M    M A C R O    D A T A
// ==================================================================
// Want to know how to supply custom macro data at compile-time that your code will get to see? In XCode's
// 'Project navigator' click the blue-iconed project name at the top. In the 'Build Settings' tab scroll all
//  the way down to 'Apple LLVM 8.0 - Custom Compiler Tags' and then expand open the 'Other C Flags' section.
// In this section click the '+' alongside the 'Debug' line and type in -D <your_flag_name>
// Note that the '-D' MUST be at the start.
//
// H O W    C A N    I    U S E    N D E B U G ?
// ---------------------------------------------
// If you have the line:
// #define NDEBUG
// before the '#import <assert.h>' line then all the assert statements will be ignored. This could be useful to
// temporarily bypass error-condition prevention barriers from assert statements as you want to experimentally
// try out some code under atypical conditions.

void main_asserts_delving_deeper() {
    printf("kHasCUSTOM_COMPILER_FLAG = %s\n", kHasCUSTOM_COMPILER_FLAG);
    assert( 1 == 2);
}
