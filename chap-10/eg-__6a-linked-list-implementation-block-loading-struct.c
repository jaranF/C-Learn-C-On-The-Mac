//
//  eg-__6a-linked-list-implementation-block-loading-struct.c
//  chap_10
//
//  Created by JaranF on 28/08/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//|-----------> DEFINES <-----------|
#define kMaxDVDs                    5
#define kMaxTitleLength             72
#define kMaxCommentLength           72
//|-----------> STRUCTS <-----------|
struct DVDinfo {
    int rating;
    char title[ kMaxTitleLength ];
    char comment[ kMaxCommentLength ];
    struct DVDinfo* nextItemPtr;
};
//|--------> FN PROTOTYPES <--------|
void main_linked_list_implementation_block_loading_struct( void );
struct DVDinfo* loadInDVDData( char srcArray[kMaxDVDs][3][kMaxTitleLength], size_t );
static void traverseLinkedList( struct DVDinfo* headListItem );
void freeList( struct DVDinfo* headListItem );
//|-------->      END      <--------|

void main_linked_list_implementation_block_loading_struct()
{
    char rawDVDData[kMaxDVDs][3][kMaxTitleLength] = {
        { {"8"}, {"Oliver Twist"}, {"The Lionel Bart classic musical"}},
        { {"6"}, {"Wicked"}, {"A scary musical"}},
        { {"9"}, {"One Flew Over The Cuckoos Nest"}, {"Won the big five at the Oscars. Only three films have done this"}},
        { {"8"}, {"Back To The Future"}, {"Eighties Classic"}},
        { {"3"}, {"How to Win Friends and Influence People"}, {"Simon Pegg vehicle that was box office Pulonium"} }
    };
    printf("%s = rating\n", rawDVDData[0][0]);
    struct DVDinfo* DVDLinkedListPtr = loadInDVDData(rawDVDData, kMaxDVDs);
    traverseLinkedList(DVDLinkedListPtr);
    freeList(DVDLinkedListPtr);
}

struct DVDinfo* loadInDVDData(char srcArray[kMaxDVDs][3][kMaxTitleLength], size_t numOfDVDs )
{
    size_t i = 0;
    struct DVDinfo* firstDVDStructPtr;
    struct DVDinfo* structDVDcurrentItemPtr;
    firstDVDStructPtr = NULL;
    if (numOfDVDs > 0) {
        firstDVDStructPtr = malloc(sizeof(struct DVDinfo));
        structDVDcurrentItemPtr = firstDVDStructPtr;
        while (i < numOfDVDs) {
            structDVDcurrentItemPtr->rating = atoi(srcArray[i][0]);
            strlcpy(structDVDcurrentItemPtr->title, srcArray[i][1], kMaxTitleLength);
            strlcpy(structDVDcurrentItemPtr->comment, srcArray[i][2], kMaxTitleLength);
            (*structDVDcurrentItemPtr).nextItemPtr = ++i == numOfDVDs ? NULL : malloc(sizeof(struct DVDinfo));
            structDVDcurrentItemPtr = (*structDVDcurrentItemPtr).nextItemPtr;
        }
    }
    return firstDVDStructPtr;
}

void traverseLinkedList(struct DVDinfo* headListItem)
{
    struct DVDinfo currItem;
    struct DVDinfo* iteratorItemPtr = headListItem;
    do {
        currItem = *iteratorItemPtr;
        printf("Title: %s\n", iteratorItemPtr->title);
        printf("Rating: %d\n", iteratorItemPtr->rating);
        printf("Comment: %s\n", iteratorItemPtr->comment);
        iteratorItemPtr = iteratorItemPtr->nextItemPtr;
    }
    while (iteratorItemPtr != NULL);
    printf("**********************************\nEnd Traverse Linked List With Loop\n**********************************\n");
}

void freeList(struct DVDinfo* head)
{
    struct DVDinfo* tmp;
    //
    while (head != NULL)
    {
        tmp = head;
        head = head->nextItemPtr;
        tmp->nextItemPtr = NULL;
        free(tmp);
    }
    
}

