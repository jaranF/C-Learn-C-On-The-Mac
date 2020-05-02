//
//  eg-__6-read-into-array-of-structs-with-fgets.c
//  chap-11
//
//  Created by Jaran F on 16/03/2019.
//
#include "eg-__6-read-into-array-of-structs-with-fgets.h"
#include <unistd.h>     // chdir (not reqd if 'eg-__2-get-home-directory.h' is included.
#include <stdbool.h>
// If you put the 'dvdData' file in your home directory (or a sub-directory therein) then
// uncomment the #include line below:
// #include "eg-__2-get-home-directory.h"
// ... AND replace ...
// int errno = chdir(kPathInCompiledProduct);
// ... with ...
// SetHomeDirectory();
// ... And have any sub-directory path from home (if required) at the start of the 'kDataFileName'
// define (see 'eg-__5-read-into-array-of-structs-with-fgets.h') so as to tell the program where
// to read the 'dvdData' file from.
// Other file functions are:
// fgetc()   .. .. 1 char at time; Have to manually check for EOF, limits and newline.
// fputc()   .. .. 1 char at a time.
// fscanf()  .. .. like the keyboard reading function but applies to file streams.
//           .. .. Also captures newlines as part of the input.
// fread()   .. .. A type, array or struct N bytes big, (possibly read X times repeatedly) from current file position (see fseeko())

//|-----------> DEFINES <-----------|
#define kDVDStructsArrayLen         3
//|-------->      END      <--------|

/********************> main_read_into_array_of_structs_with_fgets( <*/
int main_read_into_array_of_structs_with_fgets()
{
    FILE			*fp;
    struct DVDInfo	*infoPtr;
    //
    // SetHomeDirectory();
    int errno = chdir(kPathInCompiledProduct);
    if (errno != 0) {
        fprintf(stderr, "chdir failed: Path %s does not exist", kPathInCompiledProduct);
        return errno;
    } else {
        fp = fopen(kDataFileName, "r");
        if (fp == NULL) {
            errno = -1;
            fprintf(stderr, "Could not open file %s", kDataFileName);
        }
        // BELOW DOES'NT WORK AS STRUCT FIELDS IN FILE AREN'T STORED IN FIXED LENGTHS
        // SAY 256 CHARS FOR TITLE; RATHER ONLY THE NUMBER OF CHARS REQD PLUS NEWLINE.
        // fSize = getFileSize(fp);
        // struct DVDInfo filmCollection[fSize / sizeof( struct DVDInfo )]; // DOESNT WORK
        struct DVDInfo filmCollection[kDVDStructsArrayLen];
        int i = 0;
        do {
            infoPtr = malloc(sizeof( struct DVDInfo ));
            //
            if (NULL == infoPtr) {
                fprintf(stderr, "Out of memory!!!  Goodbye!\n" );
                exit( 0 );
            }
        } while (ReadStructFromFile(fp, infoPtr, &filmCollection[i++]));
        PrintDVDInfoStructArray(filmCollection, kDVDStructsArrayLen);
        errno = 0;
    }
    return errno;
}

/************************************> ReadStructFromFile <*/
bool ReadStructFromFile( FILE *fp, struct DVDInfo *infoPtr, struct DVDInfo *structArrayElePtr )
{
    int		num;
    //
    if (fscanf( fp, "%[^\n]\n", infoPtr->title ) != EOF) {
        if (fscanf( fp, "%[^\n]\n", infoPtr->comment ) == EOF) {
            printf( "Missing DVD comment!\n" );
            return false;
        } else if (fscanf( fp, "%d\n", &num ) == EOF) {
            printf( "Missing DVD rating!\n" );
            return false;
        } else {
            infoPtr->rating = num;
            strlcpy( (*structArrayElePtr).title, infoPtr->title, kMaxTitleLength -1 );
            strlcpy( (*structArrayElePtr).comment, infoPtr->comment, kMaxCommentLength -1 ) ;
            (*structArrayElePtr).rating = num;
            // AddToList( infoPtr ); // NOT REQD FOR PURPOSES OF THIS DEMO AS WE HAVE AN ARRAY.
            return true;
        }
    }
    else
        return false;
}

/*******************************> PrintDVDInfoStructArray <*/
void PrintDVDInfoStructArray( struct DVDInfo array[], int len )
{
    struct DVDInfo singleDVDFromCollection;
    assert(len > 0);
    for (int i = 0; i < len; i++) {
        singleDVDFromCollection = array[i];
        printf("Title: %s\n", (array[i]).title);
        printf("Comment: %s\n", (array[i]).comment);
        printf("Rating: %d\n", array[i].rating);
        printf("----------------------------------\n");
    }
    return;
}
