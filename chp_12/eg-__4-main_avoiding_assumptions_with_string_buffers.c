//
//  eg-__4_avoiding-assumptions-with -string-buffers.c
//  chap-12
//
//  Created by JaranF on 15/02/2020.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "main_eg_entry_functions.h"

//|-----------> DEFINES <-----------|
#define kMaxTitleLength             256
//|-----------> STRUCTS <-----------|
struct DVDInfo {
    char title[kMaxTitleLength];
};
//|--------> FN PROTOTYPES <--------|
char* InputDVDTitleName( struct DVDInfo* dvd );
char* RightTrim( char* );
//|-------->      END      <--------|

void main_avoiding_assumptions_with_string_buffers()
{
    struct DVDInfo dvd;
    printf("original input string  = -%s-", InputDVDTitleName(&dvd));
    printf("\n-------------------------------\n");
    printf("Righthand whitespace trimmed string = -%s-", dvd.title);
}

char* InputDVDTitleName(struct DVDInfo* dvdPtr)
{
    char buffer[500 + 1];
    printf("Enter title:");
    fgets(buffer, sizeof(buffer), stdin);
    char* bufPtr = buffer;
    /* H O W    N O T    T O    D O   IT
     ===================================
     text[strlen(text) - 1] = '\0'; // How not to do it (what happens if text is a zero length string)?
     */
    strlcpy(dvdPtr->title, bufPtr, sizeof(dvdPtr->title));
    RightTrim(dvdPtr->title);
    return bufPtr;
}

char* RightTrim(char* textPtr)
{
    size_t idx = textPtr != NULL ? strlen(textPtr) - 1: 0;
    bool foundTrailingWhitespace = false;
    // H O W    T O    D O    I T
    // ==========================
    // if textPtr is NULL then the trinary defends against that so idx will be 0 (zero)
    // by the time we get to here. If textPtr points to a string comprised of just a
    // "\n\0" (i.e. NEWLINE + NULL with strlen of only 1 then idx will be equal 0 again
    // because of the ' - 1' deduction in the trinary and again this while loop won't
    // exexute as there is nothing meangiful for it to do.
    while (idx > 0 ) {
        if (isspace(*(textPtr + idx))) {
            *(textPtr + idx) = '\0';
            foundTrailingWhitespace = true;
        } else if (foundTrailingWhitespace) {
            break;
        }
        
        idx--;
    }
    return textPtr;
}
