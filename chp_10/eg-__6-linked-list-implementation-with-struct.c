//
//  eg-__6-linked-list-implementation-with-struct.c
//  chap_-10
//
//  Created by Jaran F on 14/10/2018.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//|-----------> DEFINES <-----------|
#define kMaxDVDs                    4
#define kMaxTitleLength             256
#define kMaxCommentLength           256
//|-----------> STRUCTS <-----------|
struct DVDinfo {
    char rating;
    char title[ kMaxTitleLength ];
    char comment[ kMaxCommentLength ];
    struct DVDinfo* nextItemPtr;
};
//|--------> FN PROTOTYPES <--------|
void main_linked_list_implementation_with_struct( void );
void traverseLinkedListWithoutLoop( struct DVDinfo* headListItem );
void traverseLinkedList( struct DVDinfo* headListItem );
//|-------->      END      <--------|

void main_linked_list_implementation_with_struct()
{
    struct DVDinfo DVDa;
    struct DVDinfo* structDVDcurrentItemPtr;
    struct DVDinfo* structDVDnextItemPtr;
    //
    DVDa.rating = '7';
    strcpy(DVDa.title, "Wicked");
    strcpy(DVDa.comment, "Based on the musical");
    DVDa.nextItemPtr = (struct DVDinfo*)malloc(sizeof(struct DVDinfo));
    structDVDcurrentItemPtr = DVDa.nextItemPtr;
    //
    structDVDcurrentItemPtr->rating = '8';
    strcpy(structDVDcurrentItemPtr->title, "Toy Story");
    strcpy(structDVDcurrentItemPtr->comment, "First full-length computer animated film ever made.");
    structDVDcurrentItemPtr->nextItemPtr = (struct DVDinfo*)malloc(sizeof(struct DVDinfo));
    structDVDnextItemPtr = (structDVDcurrentItemPtr->nextItemPtr);
    //
    (*structDVDnextItemPtr).rating = '9';
    strcpy(structDVDnextItemPtr->title, "One Flew Over The Cuckoo\'s Nest");
    strcpy(structDVDnextItemPtr->comment, "One of a handful of films to clean sweep the big 5 oscar categories");
    structDVDnextItemPtr->nextItemPtr = NULL;
    traverseLinkedList(&DVDa);
}

void traverseLinkedListWithoutLoop(struct DVDinfo* headListItem)
{
    printf("Title: %s\n", (*headListItem).title);
    printf("Rating: %c\n", (*headListItem).rating);
    printf("Comment: %s\n", headListItem->comment);
    headListItem = headListItem->nextItemPtr;
    printf("Title: %s\n", (*headListItem).title);
    printf("Rating: %c\n", (*headListItem).rating);
    printf("Comment: %s\n", headListItem->comment);
    headListItem = headListItem->nextItemPtr;
    printf("Title: %s\n", (*headListItem).title);
    printf("Rating: %c\n", (*headListItem).rating);
    printf("Comment: %s\n", headListItem->comment);
    printf("*************************************\nEnd Traverse Linked List Without Loop\n*************************************\n");
}

void traverseLinkedList(struct DVDinfo* headListItem)
{
    struct DVDinfo currItem;
    struct DVDinfo* prevItemPtr;
    struct DVDinfo* iteratorItemPtr = headListItem;
    do {
        currItem = *iteratorItemPtr;
        printf("Title: %s\n", iteratorItemPtr->title);
        printf("Rating: %c\n", iteratorItemPtr->rating);
        printf("Comment: %s\n", iteratorItemPtr->comment);
        prevItemPtr = iteratorItemPtr->nextItemPtr;
        iteratorItemPtr = iteratorItemPtr->nextItemPtr;
    }
    while (prevItemPtr != NULL);
    printf("**********************************\nEnd Traverse Linked List With Loop\n**********************************\n");
}
