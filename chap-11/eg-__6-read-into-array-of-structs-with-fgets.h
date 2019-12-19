//
//  eg-__5-read-into-array-of-structs-with-fgets.h
//  chap-11
//
//  Created by Jaran F on 16/03/2019.
//
#ifndef eg___5_read_into_array_of_structs_with_fgets_h
#define eg___5_read_into_array_of_structs_with_fgets_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

//|-----------> DEFINES <-----------|
#define kMaxTitleLength             256
#define kMaxCommentLength           256
#define kDataFileName               "./dvdData"
#define kPathInCompiledProduct      "/Users/jaranf/Library/Developer/Xcode/DerivedData/chap-11-djdacyixhgdswzbgjbeeeozectzb/Build/Products/Debug/"

//|-----------> STRUCTS <-----------|
struct DVDInfo {
    char			rating;
    char			title[ kMaxTitleLength ];
    char			comment[ kMaxCommentLength ];
    struct DVDInfo	*next;
};
//|--------> FN PROTOTYPES <--------|
int     main_read_into_array_of_structs_with_fgets( void );
void    PrintDVDInfoStructArray( struct DVDInfo array[], int len );
bool	ReadStructFromFile( FILE *fp, struct DVDInfo *infoPtr, struct DVDInfo *DVDinfoElePtr );
//|-------->      END      <--------|
#endif /* eg-__5-read-into-array-of-structs-with-fgets.h */
