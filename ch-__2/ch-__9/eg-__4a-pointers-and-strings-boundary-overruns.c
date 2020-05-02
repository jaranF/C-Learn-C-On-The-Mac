//
//  eg-__2apointers-and-strings-boundary-overruns.c
//  chap-__9
//
//  Created by Jaran F on 25/01/2017.
//
#include <stdio.h>
#include <string.h>

//|--------> FN PROTOTYPES <--------|
void main_pointers_and_strings_boundary_overruns( void );
void Example1( void );
void Example2( void );
//|------->      END      <--------|

void main_pointers_and_strings_boundary_overruns()
{
    // What happens when arrays of chars (i.e. strings) don't have
    // their boundaries respected (i.e. missing NUL character).
    Example1();
    // The take away is that whenever you define an array of chars vis-a-vis:
    // char myArray[2]; then you have to remember to add the NUL on the end
    // of the array.
    Example2();
    // The takeaway is that the len number in 'strlcpy()' includes the '\0' NULL
    // char that the function will add on when it makes the copy. So if you wanted
    // to copy all uppercase letters of the alphabet then the len would be 27.
    // Similarly,
    // strlcpy(destBuf, sourceBuff, 1);
    // Simply puts a '\0' NULL char in index position zero.

}

void Example1()
{
    char buff[5];
    buff[0] = 'A';
    buff[1] = 'B';
    buff[2] = 'C';
    buff[3] = '\0';
    char buffMissingTerminator[2];
    buffMissingTerminator[0] = 'Z';
    buffMissingTerminator[1] = 'Y';
    printf("\n%zu (might by five because it might have run thru the memory locations allocated for \'buff\' before reaching a NULL (ASCII \'0\' terminating char)\n", strlen(buffMissingTerminator));
}

void Example2()
{
    char buffTruncated[2];
    buffTruncated[0] = '@';
    buffTruncated[1] = '\0';
    char buffMissingTerminator[2];
    buffMissingTerminator[0] = 'Z'; // Note if you tried doing the same with this command
    buffMissingTerminator[1] = 'Y'; // strcpy(buffMissingTerminator, "ZY"); you'd get a runtime error because of a buffer overrun
    printf("%zu (might by three because it might have run thru the memory locations allocated for \'buffTruncated\' before reaching a NULL (ASCII \'0\' terminating char)\n", strlen(buffMissingTerminator));
    char newString[4];
    strcpy(newString, buffMissingTerminator);
    printf("\'%s\' is the content of newString\n", newString);
    strlcpy(newString, buffMissingTerminator, 3);
    printf("\'%s\' is the content of newString (using \'strlcpy\' with 3 length restriction\n", newString);
    strlcpy(newString, buffTruncated, 2);
    printf("\'%s\' is the content of newString (using \'strlcpy\' with 2 length restriction\n", newString);
}
