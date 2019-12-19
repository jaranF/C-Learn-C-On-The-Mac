//
//  main.c
//  chap_10
//
//  Created by Jaran F on 27/01/2017.
#include <stdio.h>

//|-----------> DEFINES <-----------|
#define kMaxTitleLength             256
// Note when defining a function signature that accepts a multi dim array all but the first
// dimension MUST be defined. In this case kMaxTtitleLength must be defined.
#define kMaxCommentLength           256
//|-----------> STRUCTS <-----------|
struct DVDinfo {
    char rating;
    char title[kMaxTitleLength];
    char comment[kMaxCommentLength];
    struct DVDinfo* nextItemPtr;
};
//|--------> FN PROTOTYPES <--------|
void main_multidim_arrays( void );
void PrintDVDTitle( int dvdNum, char title[][kMaxTitleLength] );
void main_multidimarrays_instead_of_struct( void );
void main_introducing_struct( void );
void main_more_struct_tryouts( void );
void main_multidimarrays_char( void );
void main_passing_structs_as_args( void );
void main_fgets_for_getting_keyboard_input( void );
void main_linked_list_implementation_with_struct( void );
void main_linked_list_implementation_block_loading_struct( void );
void traverseLinkedListWithoutLoop( struct DVDinfo* headListItem );
void traverseLinkedList( struct DVDinfo* headListItem );
//|-------->      END      <--------|

int main(int argc, const char * argv[])
{
    // main_multidim_arrays();
    // main_multidimarrays_char();
    // main_multidimarrays_instead_of_struct();
    // main_fgets_for_getting_keyboard_input();
    // main_introducing_struct();
    // main_more_struct_tryouts();
    // main_passing_structs_as_args();
    // main_linked_list_implementation_with_struct();
     main_linked_list_implementation_block_loading_struct();
    return 0;
}

