//
//  eg-__7a-static-complex-type-vars-in-functions.c
//  chap-__7
//
//  Created by Jaran F on 09/08/2019.
//
#include <stdio.h>
#include <limits.h>		/* NAME_MAX */
#include <string.h>

//|-----------> DEFINES <-----------|
#define kPrevNamesCacheLen          3
//|-----------> STRUCTS <-----------|
struct memoizedItem {
    int suffix;
    char filename[NAME_MAX];
};
//|----------> TYPEDEFS <-----------|
typedef int (*fnComparasonPointer)(const char*, const struct memoizedItem);
//|--------> FN PROTOTYPES <--------|
void main_static_complex_type_vars_in_functions( void );
static int StaticFunc( void ); // The static keyword here is just so I can have duplicate
                               // functions with the same name (see the other static var
                               // file, 'eg-__7a-static-vars-in-functions.c'). It has
                               // nothing to so with the static var 'memoizedItem'.
int Comparator( const char*, struct memoizedItem );
int indexOf( struct memoizedItem[], int, const char*, fnComparasonPointer );
//|-------->      END      <--------|

void main_static_complex_type_vars_in_functions()
{
    StaticFunc();
}

static int StaticFunc()
{
    static struct memoizedItem item0, item1, item2;
    item0.suffix = 0;
    strcpy(item0.filename, "abc");
    char soughtName[12] = "myFilename-\0"; // Try "abc\0" or "xyz\0" or event "foobar\0" to test
    fnComparasonPointer ComparatorFnPtr = Comparator;
    struct memoizedItem items[kPrevNamesCacheLen];
    items[0] = item0;
    item1.suffix = 9;
    strcpy(item1.filename, "xyz");
    items[1] = item1;
    item2.suffix = 3;
    strcpy(item2.filename, "myFilename-");
    items[2] = item2;
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
    while (i > -1 && comparator(sought, arr[i])) i--;
    return i;
}
