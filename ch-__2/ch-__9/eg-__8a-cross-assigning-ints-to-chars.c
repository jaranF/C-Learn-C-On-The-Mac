//
//  eg-__4a-cross-assigning-ints-to-chars.c
//  chap-__9
//
//  Created by Jaran F on 25/01/2017.
//
#include <stdio.h>
#include <string.h>

//|--------> FN PROTOTYPES <--------|
void main_cross_assigning_ints_to_chars( void );
//|------->      END      <--------|

void main_cross_assigning_ints_to_chars()
{
    char buff[4] = "xyz\0";
    int intbuff[] = {65, 97, 94, 0};    // ASCII chars A a ^
    // Before Snapshot Of How This Looks In Memory
    // -------------------------------------------
    // 7FFF5FBFF860:    41 00 00 00  |  61 00 00 00  |  5E 00 00 00  |  00 00 00 00 » A...a...^.......
    // 7FFF5FBFF872:    00 00 00 78  |  79 7A 00 77  |  8F 8D 1F C7  |  7D 00 12 A0 » ...xyz.?????????
    int* intBuffPointer = intbuff;
    int i = 0;
    while (*intBuffPointer != '\0') {
      buff[i++] = *intBuffPointer;
      printf("- %d -\n", *intBuffPointer++);
    }
    // AFTER Snapshot Of How This Looks In Memory
    // ------------------------------------------
    // 7FFF5FBFF860:    41 00 00 00  |  61 00 00 00  |  5E 00 00 00  |  00 00 00 00 » A...a...^.......
    // 7FFF5FBFF870:    00 00 00 41  |  61 5E 00 77  |  8F 8D 1F C7  |  7D 00 12 A0 » ...Aa^.?????????
    
    // CONCLUSION
    // It is safe to downcast an int to a char as the computer will automatically take care of stripping off the extra
    // following '00' byte sequences as necessary to squeeze ascii value into single byte space of a char
    printf("\n---------------------\nEXPERIMENT 2 (below)\n---------------------\n");
    // EXPERIMENT 2.
    // What happens if instead of a single-byte range ascii char an int initially holds TWO bytes worth of set ascii bits
    strcpy(buff, "xyz");
    int intbuff2[] = {24897, 94, 0, 0};
    // Before Snapshot Of How This Looks In Memory
    // -------------------------------------------
    // 7FFF5FBFF840:    41 61 00 00  |  5E 00 00 00  |  00 00 00 00  |  00 00 00 00 » A...a...^.......
    // ...                  ...              ...           ...              ...
    // 7FFF5FBFF850:    00 00 00 00  |  78 79 7A 00  |  31 49 55 79  |  73 70 00 A0 » ....xyz.1IUysp.#
    intBuffPointer = intbuff2;
    i = 0;
    while (*intBuffPointer != '\0') {
        buff[i++] = *intBuffPointer;
        printf("- %d -\n", *intBuffPointer++);
    }
    // AFTER Snapshot Of How This Looks In Memory
    // ------------------------------------------
    // 7FFF5FBFF840:    41 61 00 00  |  5E 00 00 00  |  00 00 00 00  |  00 00 00 00 » A...a...^.......
    // ...                  ...              ...           ...              ...
    // 7FFF5FBFF850:    00 00 00 00  |  41 5E 7A 00  |  31 49 55 79  |  73 70 00 A0 » ....A^z.1IUysp.#
    //
    // where *intbuff = 0x7FFF5FBFF874
    
    // CONCLUSION
    // It is NOT safe to downcast an int to a char if anything MORE than the LEAST SIGNIFICANT BYTE of the int holds a
    // meaningful ASCII value most often this means if it holds anything other than zero. So whilst ths LSB's 0x41 got
    // downcast and pushed into the char array at memory location 0x7FFF5FBFF874 the 61 (i.e. ascii 'a') just fell into
    // a black hole. Effectively only two ascii chars ended up being copied into 'buff' char array and so the 'z' it had
    // at the end to begin with is preserved
    
    char charSingle = (char)(0x416279);
    putchar(charSingle);
    printf("\n---------------------\nEXPERIMENT 3 (below)\n---------------------\n");

    //EXPERIMENT 3.
    //what happens if what was a char pointer pointing to say, "vwyxz", is instead coerced pointing to what an int array
    // pointer points to with the values:
    //                 [0] = 0x41615e7a
    //                 [1] = 0x0000005f
    //                 [2] = 0x00000000
    //                 [3] = 0x00000000
    // ... And what happens when we change one of those values in the int array, say 0x00000005f (i.e. 95 decimal) to a
    // completely different value, say 0x0000002B (i.e. 43 decimal or ascii '+'  )
    char buffNew[6] = "vwxyz\0";
    char *charPtr;
    charPtr = buffNew;
    int j = 0;
    while (*charPtr != '\0')
        printf("buffNew i.e. \'vwxyz\' with \'charPtr\' pointing to char at index %d which is char \'%c\'\n", j++, *charPtr++);
    // BEFORE Snapshot Of How This Looks In Memory
    // -------------------------------------------
    // buffNew:
    // 0x7fff5fbff705:  76 77 78 79  |  7A 00 XX XX  |  XX XX XX XX  |  XX XX XX XX » vwzyz...........
    // intbufNew:       (1st element)   (2nd element)   (3rd element)   (4th element)
    // 0x7fff5fbff720:  41 61 5E 7A  |  5F 00 00 00  |  00 00 00 00  |  00 00 00 00 » Aa^z_...........
    int intbuffNew[] = {2053005633, 95, 0, 0}; // 2053005633d hex = 41 61 5e 7a = Aa^z ... and ... 95d hex = 5F = _
    void *intArrayPtr;                         // NB declaring this as int *intArrayPtr as normal causes a compiler warning.
    intArrayPtr = &intbuffNew[0];
    intbuffNew[1] = 0x2B;
    // CHANGE The first element in intbuffNewArray to 0x0000002B
    // intbufNew:       (1st element)   (2nd element)   (3rd element)   (4th element)
    // 0x7fff5fbff720:  41 61 5E 7A  |  2B 00 00 00  |  00 00 00 00  |  00 00 00 00 » Aa^z+...........
    charPtr = intArrayPtr;
    // AFTER Snapshot Of How This Looks In Memory
    // -------------------------------------------
    // buffNew:
    // 0x7fff5fbff705:  76 77 78 79  |  7A 00 XX XX  |  XX XX XX XX  |  XX XX XX XX » vwzyz...........
    // *charPtr:
    // 0x7fff5fbff720:  41 61 5E 7A  |  2B 00 00 00  |  00 00 00 00  |  00 00 00 00 » Aa^z+...........
    //CONCLUSION
    //You can coerce a pointer pointing to an array / value of one type to instead act as a char array pointer. Note, to
    // avoid having the compiler barf at the pointer type re-assignment I declared the int array pointer as type 'void'.
    j = 0;
    printf("\nAfter coercing a int array pointer into being a char array pointer\n");
    while (*charPtr != '\0')
        printf("buffNew still = \'vwxyz\' but now \'charPtr\' points to an int array whose index %d is char \'%c\'\n", j++, *charPtr++);
    
    return;
}















