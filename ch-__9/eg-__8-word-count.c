//
//  eg-__4-word-count.c
//  chap-__9
//
//  Created by Jaran F on 25/01/2017.
//
#include <stdio.h>
#include <ctype.h>     // This is to bring in the declaration of isspace()
#include <stdbool.h>   // This is to bring in the define for true
#include <string.h>    // strlen

//|-----------> DEFINES <-----------|
#define kMaxLineLength              100
//|--------> FN PROTOTYPES <--------|
int main_word_count( void );
void ReadLine( char* );
int CountWords( char* );
//|------->      END      <--------|

int main_word_count()
{
    char line[ kMaxLineLength +1 ];
    int numWords;
    printf( "Type a line of text, please:\n" );
    ReadLine(line);
    numWords = CountWords(line);
    printf( "\n---- This line has %d word%s, %zu character%c ---\n", numWords, ( numWords!=1 ? "s" : "" ), strlen(line), strlen(line) > 1 ? 's': '\0' );
    printf( "%s\n", line );
    return 0;
}

void ReadLine( char* line )
{
    int numCharsRead = 0;
    int c;
    while ( (c = getchar()) != EOF
           && c != '\n'
           && ++numCharsRead <= kMaxLineLength ) {
        *line++ = c;
    }
    *line = '\0';
}

int CountWords (char* line)
{
    int wordCountTally;
    bool inWord;
    wordCountTally = 0;
    inWord = false;
    while (*line != '\0') {
       if ( isspace(*line) ) {
           inWord = false;
       }
       else {
           if ( !inWord ) {
               wordCountTally++;
               inWord = true;
           }
       }
       line++;
    }
    return wordCountTally;
}

