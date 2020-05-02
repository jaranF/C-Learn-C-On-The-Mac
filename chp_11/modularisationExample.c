//
//  modularisationExample.c
//  chap-11
//
//  Created by Jaran F on 16/03/2019.
//
#include <stdio.h>
#include <assert.h>
#include <mach-o/dyld.h>/* _NSGetExecutablePath */
#include <limits.h>		/* PATH_MAX */
#include <unistd.h>		/* execve   */
#include <libgen.h>		/* dirname  */
#include <string.h>		/* strcpy   */
#include "modularisationSubModule.h"

//|-----------> DEFINES <-----------|
#define kMaxSuffixNumber            100
//|-------->      END      <--------|

// The EOF marker takes up one byte and is always included in the number that
// this function returns.
off_t getFileSize( FILE *fp)
{
    fseek(fp, 0, SEEK_END);
    off_t fSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return fSize;
}

char* Executables_Path()
{
    char pathbuf[ PATH_MAX + 1 ];
    char fullPathToExecutable[ sizeof(pathbuf) + 1] ; // +1 to allow for trailing forward slash
    char *bundle_id;
    int unsigned  bufsize = sizeof(pathbuf);
    char* charBuffPointer;
    //Determine Path this executable is running from
    _NSGetExecutablePath( pathbuf, &bufsize);
    //
    bundle_id = dirname(pathbuf);
    //
    strcpy(fullPathToExecutable, bundle_id);
    strcat(fullPathToExecutable, "/");
    charBuffPointer = fullPathToExecutable;
    return charBuffPointer;
}

char* Next_Free_Filename(const char* baseFilenName, const char* extension)
{
    int suffix = 0;
    static char filenameBuf[ NAME_MAX + 1 ]; // + 1 for NUL terminating char but have to account for suffix as well
    assert(strlen(baseFilenName) <= NAME_MAX - 6); // Allow for two digit number suffixes PLUS dot PLUS 3 char extension.
    do {
        snprintf(filenameBuf, sizeof(filenameBuf), "%s%d.%s", baseFilenName, ++suffix, extension);
        // Note you could see if a file exists with the fopen() call but using "unistd.h's" function 'access' is
        // more elegant (i.e. you don't have to do the fclose as well etc). So replaced the line below.
        // fp = fopen(filenameBuf, "r");
         printf("---------------\n%s == FOUND %s\n--------------\n", filenameBuf, (access( filenameBuf, F_OK ) != -1) ? "YES" : "NO");
        //
    } while (suffix <= kMaxSuffixNumber - 1 && (access( filenameBuf, F_OK ) != -1));
    if (suffix >= kMaxSuffixNumber) {
        strcpy(filenameBuf, "");
    }
    return filenameBuf;
}

int StaticFunc() {
    static struct memoizedItem item0, item1, item2;
    item0.suffix = 0;
    strcpy(item0.filename, "abc");
    char soughtName[ 12 ] = "ashs\0"; // Try "abc\0" or "xyz\0" to test
    fnComparasonPointer ComparatorFnPtr = Comparator;
    struct memoizedItem items[ kPrevNamesCacheLen ];
    items[ 0 ] = item0;
    item1.suffix = 9;
    strcpy(item1.filename, "xyz");
    items[ 1 ] = item1;
    item2.suffix = 3;
    strcpy(item2.filename, "myFilename-");
    items[ 2 ] = item2;
    int iFoundPos = indexOf(items, 3, soughtName, ComparatorFnPtr);
    printf("%sPos Index of Found Name = %d%s\n", "\n---------------------------\n", iFoundPos,  "\n---------------------------\n");
    return 0;
}

int Comparator(const char* sought, const struct memoizedItem item)
{
    return strcmp(sought, item.filename);
    return 0;
}

int indexOf(struct memoizedItem arr[], int len, const char* sought, fnComparasonPointer comparator)
{
    int i = len - 1;
    while (i > -1 && comparator(sought, arr[ i ])) i--;
    return i;
}
