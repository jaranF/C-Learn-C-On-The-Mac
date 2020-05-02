//
//  modularisationExample.h
//  chap-11
//
//  Created by Jaran F on 16/03/2019.
//

#ifndef modularisationExample_h
#define modularisationExample_h

//|-----------> DEFINES <-----------|
#define kMaxTitleLength             256
//|-----------> STRUCTS <-----------|
//|------> TYPEDEFS & ENUMS <-------|
//|--------> FN PROTOTYPES <--------|
//|-------->      END      <--------|

// Defining the includes here does not make any difference. The file that uses them,
// 'modularisationExample.c' must have these includes or you get a compile time error
// unless 'modularisationExample.c' includes this file
#include <stdio.h>
#include <stdlib.h>  // malloc and free


extern off_t getFileSize( FILE *fp );
extern char* Executables_Path( void );
extern char* Next_Free_Filename( const char* baseFilenName, const char* extension );
#endif/* modularisationExample_h */
