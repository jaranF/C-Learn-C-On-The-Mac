//
//  eg-__3-fscanf-exploration.c
//  chap-11
//
//  Created by JaranF on 14/09/2019.
//
// This fscanf file reading function:
// fscanf(fPtr, [string]RESTRICT_SPECIFIER);
//
// Other file functions are:
// fgetc()   .. .. 1 char at time; Have to manually check for EOF, limits and newline.
// fputc()   .. .. 1 char at a time.
// fgets()   .. .. Whole files at a time until either EOF or SIZE worth of bytes being read.
// fread()   .. .. A type, array or struct N bytes big, (possibly read X times repeatedly) from current file position (see fseeko()).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eg-__3-get-home-directory.h"

//|-----------> DEFINES <-----------|
#define kMaxFieldLength             256
#define kScanToNewlinePattern       "%[^\n]\n"
#define kOK                         1
//|-----------> STRUCTS <-----------|
struct foo {
    char field1[ kMaxFieldLength ];
    char field2[ kMaxFieldLength ];
    char field3[ kMaxFieldLength ];
    struct foo* nextItemPtr;
};
//|--------> FN PROTOTYPES <--------|
int main_fscanf_exploration_line_at_a_time( void );
void parseCommaDelimited( struct foo*, char* );       // Alters struct foo
void printAllLinkedListItems( struct foo* );
void freeList( struct foo* );
//|-------->      END      <--------|

int main_fscanf_exploration_line_at_a_time()
{
    // fscanf();
    int retValue = 0;
    FILE *fp;
    //
    SetHomeDirectory();
    fp = fopen( "./Documents/learning/c/Learn_C_On_The_Mac/chap-11/My_CSVData_File.csv", "r" );
    //
    if ( NULL == fp ) {
        printf("Error opening file \'My_CSVData_File.csv\'\n");
        printf("In file path...\n");
        printf("/Users/jaranf/Documents/learning/c/Learn_C_On_The_Mac/chap-11/\n");
        retValue = -1;
    } else {
        struct foo *myFooPtrLinkedList = NULL, *currentItemPtr = NULL, *prevItemPtr;
        int scanfResult;
        char all3FieldsBuff[3 * kMaxFieldLength]; // ","; //+1 for comma at start & +1 for trailing NULL char at end.
        prevItemPtr = NULL;
        //
        while (kOK == (scanfResult = fscanf(fp, kScanToNewlinePattern, all3FieldsBuff))) {
            currentItemPtr = (struct foo*)malloc(sizeof(struct foo));
            if (prevItemPtr != NULL) {
                prevItemPtr->nextItemPtr = currentItemPtr;
            } else {
               myFooPtrLinkedList = currentItemPtr;
            }
            parseCommaDelimited(currentItemPtr, all3FieldsBuff);
            prevItemPtr = currentItemPtr;
        }
        currentItemPtr->nextItemPtr = NULL;
        if (scanfResult != EOF) {
   /*         fprintf( stderr, "Invalid data near offset %lu, %d: %s\n",
                    (long unsigned int)ftello(fp), scanResult, strerror(scanResult) );
            */
        }
       // fgets(charBuffPtr, (int)fSize, fp);  // fgets
        //printf(charBuffPtr, "%s");
        printf("\n");
        //printf("myFooPtrLinkedList->field1 = %s\n", myFooPtrLinkedList->field1);
        printAllLinkedListItems(myFooPtrLinkedList);
        fclose( fp );
        
        freeList(myFooPtrLinkedList);
        
    }
    return retValue;
}

void parseCommaDelimited(struct foo* destinationStructPtr, char* line)
{
    char *pch, *base;
    base = (char*)destinationStructPtr;
    int i = 0;
    pch = strtok (line,",");
    while (pch != NULL)
    {
        //strcpy(destinationStructPtr->field1, pch);
        strcpy((base + (i++ * kMaxFieldLength)), pch);
        pch = strtok (NULL, ",");
    }
}

void printAllLinkedListItems(struct foo* linkedList)
{
    while (linkedList->nextItemPtr != NULL) {
        printf("linkedList->field1 = %s\n", linkedList->field1);
        printf("linkedList->field2 = %s\n", linkedList->field2);
        printf("linkedList->field3 = %s\n", linkedList->field3);
        printf("--------------------------\n");
        linkedList = linkedList->nextItemPtr;
    }
    
}

void freeList(struct foo *head)
{
    struct foo* tmp;
    //
    while (head != NULL)
    {
        tmp = head;
        head = head->nextItemPtr;
        tmp->nextItemPtr = NULL;
        free(tmp);
    }
}

