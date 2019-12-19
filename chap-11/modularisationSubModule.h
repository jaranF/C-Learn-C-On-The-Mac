//
//  modularisationSubModule.h
//  chap-11
//
//  Created by JaranF on 03/09/2019.
//
#ifndef modularisationSubModule_h
#define modularisationSubModule_h

#include <limits.h>

//|-----------> DEFINES <-----------|
#define kPrevNamesCacheLen          3
//|-----------> STRUCTS <-----------|
struct memoizedItem {
    int suffix;
    char filename[ NAME_MAX ];
};
//|------> TYPEDEFS & ENUMS <-------|
typedef int (*fnComparasonPointer)(const char*, const struct memoizedItem);
//|--------> FN PROTOTYPES <--------|
void main_static_complex_type_vars_in_functions( void );
int StaticFunc( void );
int Comparator( const char*, struct memoizedItem );
int indexOf( struct memoizedItem[], int, const char*, fnComparasonPointer );
//|-------->      END      <--------|
#endif /* modularisationSubModule_h */
