//
//  eg-__7-fgets-for-getting-keyboard-input.c
//  chap_10
//
//  Created by JaranF on 02/09/2019.
//
// This fgets keyboard function:
// fgets(myCharBuff, 100, stdin);
// ... or typically ...
// fgets(myCharBuff, sizeof(myCharBuff), stdin);
// This keyboard function captures up to a maxiumum of myCharBuffer size MINUS 1 (that 1 is occupied
// by the NULL char). The user has to press the 'Return' key to get 'fgets()' go off and collect the
// keys pressed from the OS's key input buffer. The return char, '\n', gets included as part of what
// 'fgets()' returns except when the maximum number of keys it's accepting is input in which case it
// is not.
// Say, fgets(myCharBuff, 5, stdin);
// type in:
// ABC -> get -> ABC\n
// type in:
// ABCD -> get -> ABCD
// Other keyboard scanning in functions are:
// getchar() .. .. 1 char at time; Have to manually check for EOF, limits and newline
// Final note: If you have successive 'scanf()' calls or even a 'getchar()' preceeding the 'scanf()'
// you have to flush the buffer between one usage of 'scanf' to the next. Otherwise, it's if the
// most previous entry was ghosted (including the 'RETURN' key) so it automatically becomes the
// input for the next 'scanf' without giving you the chance to type anything. See
// http://c-faq.com/stdio/gets_flush1.html
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//|--------> FN PROTOTYPES <--------|
void main_fgets_for_getting_keyboard_input( void );
char GetSingleCharCommand( char* );
char* TrimLine( char* );
//|-------->      END      <--------|

void main_fgets_for_getting_keyboard_input()
{
    char recognizedCmdChars[4] = "qnl\0";
    char c = '\0';
    //
    while ( c != 'q') {
        printf("Command prompt Enter (q) quit, (n) new, (l) list) : ");
        c = GetSingleCharCommand(recognizedCmdChars);
        switch(c) {
            case 'n':
                printf("print new\n");
                break;
            case 'l':
                printf("print list\n");
                break;
        }
    }
    printf("\n...Exiting...\n");
}

char GetSingleCharCommand(char* acceptedCommandLetters)
{
    char buffer[ 30+1 ]; //fgets returns pointer to array of chars
    fgets(buffer, sizeof(buffer), stdin);
    TrimLine(buffer);
    char* foundCmdCharPtr;
    foundCmdCharPtr = strpbrk(buffer, acceptedCommandLetters);
    return foundCmdCharPtr == NULL ? '\0' : *(foundCmdCharPtr);
}

char * TrimLine(char *untrimmedString)
{
    size_t len = strlen(untrimmedString);
    size_t index = len - 1; // Minus 1 because array indexes are zero based.
    while ( index > 0 && isspace((untrimmedString[index])) ) {                                // NB strlen does NOT include terminating
        untrimmedString[index] = '\0';
        index--;
    }
    index = 0;
    char *head = untrimmedString;
    while (isspace(*head)) {  // No need for IS NOT EOF clause as isspace(EOF) returns FALSE; Likewise, same for isspace('\0')
        head++;
    }
    return head;
}
