//
//  eg-__1-avoid-assumptions-by-replacing-literal-values.c
//  chap-12
//
//  Created by JaranF on 19/12/2019.
//
#include <stdio.h>
#include <string.h>
#include "main_eg_entry_functions.h"

//|-----------> DEFINES <-----------|
#define kMaxTitleLength             21
//|-----------> STRUCTS <-----------|
struct DVDInfo {
    char title[kMaxTitleLength];
};
//|--------> FN PROTOTYPES <--------|
char* InputDVDTitle( struct DVDInfo dvd );
char* TrimLine( char* );
//|-------->      END      <--------|

void main_avoid_assumptions_by_replacing_literal_values()
{
    struct DVDInfo dvd;
    InputDVDTitle(dvd);
}

char* InputDVDTitle(struct DVDInfo dvd)
{
    char buffer[500 + 1];
    printf("Enter title:");
    fgets(buffer, sizeof(buffer), stdin);
    char* bufPtr = buffer;
    // strlcpy(dvd.title, bufPtr, kMaxTitleLength);
    // Note the below is preferable to even the above
    strlcpy(dvd.title, TrimLine(bufPtr), sizeof(dvd.title));
    return bufPtr;
}

char* TrimLine( char* text)
{
    //size_t index;
    return text;
}
