//
//  eg-__1-multidimarrays.c
//  chap_-10
//
//  Created by Jaran F on 10/06/2018.
//
#include <stdio.h>

//|-----------> DEFINES <-----------|
#define kMaxDVDs                    2
#define kMaxTitleLength             12 // Defined in main.c as well
//|--------> FN PROTOTYPES <--------|
void main_multidim_arrays( void );
void PrintDVDTitle( int dvdNum, char title[][ kMaxTitleLength ] );
//|-------->      END      <--------|

void main_multidim_arrays( void )
{
    char	title[ kMaxDVDs ][ kMaxTitleLength ];   // MULTI DIMENSION ARRAY SYNTAX!
    int     dvdNum;
    //
    printf( "The title array takes up %zu bytes of memory.\n\n",
           sizeof( title ) );
    //
    for ( dvdNum = 0; dvdNum < kMaxDVDs; dvdNum++ ) {
        printf( "Title of DVD #%d: ", dvdNum + 1 );
        fgets( title[ dvdNum ], kMaxTitleLength, stdin );
    }
    printf( "----\n" );
    //
    for ( dvdNum = 0; dvdNum < kMaxDVDs; dvdNum++ )
        PrintDVDTitle( dvdNum, title );
}

void PrintDVDTitle( int dvdNum, char title[][ kMaxTitleLength ] ) // NB When used as a param the dimsn of array is reqd.
{
    printf( "Title of DVD #%d: %s\n", dvdNum + 1, title[ dvdNum ] );
}

