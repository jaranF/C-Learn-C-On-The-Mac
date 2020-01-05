//
//  eg-__2-dvdlisted-model-a-arrays.c
//  chap_-10
//
//  Created by Jaran F on 13/06/2018.
//
#include <stdio.h>
#include <string.h>

//|-----------> DEFINES <-----------|
#define kMaxDVDs                    2 // 5000
#define kMaxTitleLength             256
#define kMaxCommentLength           256
//|--------> FN PROTOTYPES <--------|
void main_multidimarrays_instead_of_struct( void );
void PrintAllInfoOfAllDVDs( char title[][ kMaxTitleLength ], char rating[], char comment[][ kMaxCommentLength ], int arraysLen );
//|-------->      END      <--------|

static int gASCII_ZERO = 0x30;

void main_multidimarrays_instead_of_struct()
{
    char    rating[ kMaxDVDs ];
    char    title[ kMaxDVDs ][ kMaxTitleLength ];
    char    comment[ kMaxDVDs ][ kMaxCommentLength ];
    char c;
    int ratingInput;
    int     dvdNum;
    //
    for ( dvdNum = 0; dvdNum < kMaxDVDs; dvdNum++ ) {
        // Note best practice to use 'scanf()' for keyboard input. Read why here:
        // http://c-faq.com/stdio/gets_flush1.html
        // 'scanf()' leaving UNCLAIMED KEYSTROKES in the buffer IS a problem for me.
        // That is why I have the line:
        //                           while ((c = getchar()) != '\n' && c != EOF) { }
        printf( "Title of DVD #%d: ", dvdNum + 1 );
        // fgets( title[ dvdNum ], kMaxTitleLength, stdin );
        // 'scanf()' seems to be terminating NUL char safe i.e. it adds it on automatically.
        // To prove scanf adds on the terminating NUL automatically, first pre-fill 'titleBuff' with '12345678901'
        // (eleven chars + NUL) via :
        // char titleBuff[12];
        // strcpy(titleBuff, "12345678901");
        // Then use scanf with a %10s to capture ONE char less than titleBuff's capacity:
        //     scanf("%10s", titleBuff);
        // Expect the end of the twelve bytes of memory where titleBuff is stored to be Mem[10] = '\0' and Mem[11] = '\0'.
        // Which means when it captures it's ten-length string it adds on the NULL (but this time in one char position
        // short of where it was on the original strcpy assignment.
        scanf("%255s", title[ dvdNum ]);                    /// 255 chars grabbed + 1 for NUL scanf adds = kMaxTitleLength
        while ((c = getchar()) != '\n' && c != EOF) ; // Clear input buffer
        
        printf( "Rating of DVD #%d: ", dvdNum + 1 );
        scanf("%1d", &ratingInput);
        rating[ dvdNum ] = gASCII_ZERO + ratingInput;
        while ((c = getchar()) != '\n' && c != EOF) ; // Clear input buffer
        printf( "Comment on DVD #%d: ", dvdNum + 1 );
        scanf("%255s", comment[ dvdNum ]);                  // 255 chars grabbed + 1 for NULL scanf adds = kMaxCommentLength
        while ((c = getchar()) != '\n' && c != EOF) ; // Clear input buffer. Actually book code is wrong 'cos 'getchar()' returns an int. See http://c-faq.com/stdio/stdinflush2.html
        putchar(13);
    } //next dvdNum
    PrintAllInfoOfAllDVDs(title, rating, comment, kMaxDVDs);
    return;
}
//
void PrintAllInfoOfAllDVDs(char title[][ kMaxTitleLength ], char rating[], char comment[][ kMaxCommentLength ], int arraysLen )
{
    for (int i = 0; i < arraysLen; i++) {
        printf("DVD #%d. Title = %s\n", i + 1 , title[ i ]);
        printf("DVD #%d. Rating = %c\n", i + 1 , rating[ i ]);
        printf("DVD #%d. Comment = %s\n", i + 1, comment[ i ]);
    }
    
}
