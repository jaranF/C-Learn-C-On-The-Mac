//
//  eg-__7a-pointer-equivalency-with-chars.c
//  chap-__9
//
//  Created by JaranF on 18/04/2020.
//
#include <stdio.h>
#include <string.h>

//|--------> FN PROTOTYPES <--------|
void main_pointer_equivalency_with_chars( void );
void PrintInReverse(char *);
char* CopyAndReverseAndPrint(char *);
//|-------->      END      <--------|

void main_pointer_equivalency_with_chars()
{
    char buff[10];
    strcpy(buff, "HI THERE!");
    char buff2[13] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', '\0'};
    PrintInReverse(buff);
    strcpy(buff2, CopyAndReverseAndPrint(&buff2[0]));   // So '&buff2[0]' is just the long-hand of above.
    // The above is poor programming practice as using 'strcpy()' is making a massive assumption about the length of the char buffer string
    // that is returned from the function. Also what 'CopyAndReverseAndPrint()' returns is a char buffer that was declared locally in that
    // function so therefore occupies a piece of the stack memory so returning it isn't wise (and why I use the 'static' keyword).
}

void PrintInReverse(char *charStrPtr) // later on we'll use the 'const' keyword modified for functions like this.
{
    size_t len = strlen(charStrPtr);
    while (len-- > 0) {
        putchar(charStrPtr[len]);
    }
    putchar('\n');
}

char* CopyAndReverseAndPrint(char *charStrPtr)
{
    size_t len = strlen(charStrPtr);    // strlen gives length WITHOUT trailing NULL char. Whereas sizeof is WITH NULL char.
    len = len < 10 ? len : 9;
    static char newBuff[10];
    strlcpy(newBuff, charStrPtr, len + 1); // len + 1 to take account of trailing NULL char.
    int i = 0;
    while (len-- > 0) {
        putchar(charStrPtr[len]);
        newBuff[i++] = charStrPtr[len];
    }
    putchar('\n');
    return &newBuff[0]; // If 'newBuf' wasn't declared 'static' you'd get a compiler warning:
                        // "Address of stack memory associated with local variab;e 'newBuff' returned"
    // return newBuff;
}
