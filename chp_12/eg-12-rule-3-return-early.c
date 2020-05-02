//
//  eg-12-rule-3-return-early.c
//  chap-12
//
//  Created by JaranF on 19/04/2020.
//
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>   // calloc
#include <pwd.h>
#include <unistd.h>
#include <string.h>   // strerror
#include <errno.h>
#include "main_eg_entry_functions.h"

//|-----------> DEFINES <-----------|
#define kDataFileName               "./Desktop/My_Data_File"
#define kMaxTitleLength             256
//|-----------> STRUCTS <-----------|
struct DVDInfo {
    char			rating;
    char			*title;
    char			*comment;
    struct DVDInfo	*next;
};
//|--------> FN PROTOTYPES <--------|
static struct DVDInfo *ReadStructFromFile( FILE *fp );
static struct DVDInfo *NewDVDInfo( void );
static void SetHomeDirectory();
//|-------->      END      <--------|

void main_rule_3_return_early()
{
    FILE *fp;
    SetHomeDirectory();
    fp = fopen(kDataFileName, "r");
    struct DVDInfo *DVDStructFromFilePtr;
    DVDStructFromFilePtr = ReadStructFromFile(fp);
}

static struct DVDInfo * ReadStructFromFile(FILE *fp)
{
    struct DVDInfo  *infoPtr;
    int scanResult;
    assert(fp != NULL);
    // Allocate a new DVDInfo struct
    infoPtr = NewDVDInfo();
    scanResult = fscanf( fp, "%[^\n]\n", infoPtr->title );
    // Note the multiple nested ifs with 'follow the success pattern'
    if ( scanResult == 1 ) {
        scanResult = fscanf( fp, "%[^\n]\n", infoPtr->comment );
        if ( scanResult == 1 ) {
            int num;
            scanResult = fscanf( fp, "%d\n", &num );
            if ( scanResult == 1 ) {
                infoPtr->rating = num;
                return infoPtr;         // <-- success!
            }
        }
    }
    // By the time we get here one or all of the fscanf() calls will have run and since
    // there was no early return designating a success there must be an error to deal with.
    if ( scanResult != EOF ) {
        fprintf( stderr, "Invalid data near offset %lu, %d: %s\n",
                (long unsigned int)ftello(fp),
                errno,
                strerror(errno) );
    }
    free( infoPtr );
    infoPtr = NULL;
    // Return the new DVDInfo struct read from the file, or NULL
    return NULL;
}

static void SetHomeDirectory()
{
    struct passwd *pw;
    pw = getpwuid( getuid() );
    chdir( pw->pw_dir );
}

/**
 ****************
 NewDVDInfo()
 return pointer to new DVDInfo struct
 
 Allocate and initialize one DVDInfo struct
 */
static struct DVDInfo *NewDVDInfo( void )
{
    return calloc( 1, sizeof( struct DVDInfo ) );
}
