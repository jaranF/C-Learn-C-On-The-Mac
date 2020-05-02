//
//  eg-__7-pointer-arithmetic-equivalency.c
//  chap-__9
//
//  Created by JaranF on 18/04/2020.
//  Originally created by James Bucanek and David Mark on 8/1/12.
//  Copyright (c) 2012 Apress, Inc. All rights reserved.
//
#include <stdio.h>
#include <assert.h>

//|--------> FN PROTOTYPES <--------|
int main_pointer_arithmetic_equivalency( void );
//|-------->      END      <--------|

int main_pointer_arithmetic_equivalency()
{
    // This code demonstrates the interchangability and
    //  equivalency of pointer and array variables in C.
    //
    int array[ 10 ] = { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 };
    int *pointer;
    //
    int n = 4;
    int x;
    int *intPtr;
    size_t sz;
    //
    // The name of an array is the address of its first element
    pointer = array;            // *pointer and array[0] are now the same
    pointer = &array[0];        // identical to previous statement
    assert(array == &array[0]);
    //
    // Getting the zero'th element of an array is the same as
    //  dereferencing a pointer
    x = array[ 0 ];             // these two statements are identical,
    x = *pointer;               //  assuming pointer==array
    assert(array[0] == *(pointer));
    // Getting the n'th element of an array is the same as
    //  dereferencing pointer + n
    //
    x = array[ n ];             // these two statements are identical,
    x = *(pointer + n);         //  assuming pointer==array
    assert(array[n] == *pointer + n);
    //
    // The address of the n'th element of an array is the same
    //  as adding n to a pointer
    intPtr = &array[ n ];       // these two statements are identical,
    intPtr = pointer + n;       //  assuming pointer==array
    assert((&array[n]) == pointer + n);
    //
    // Subtracting pointers is the same as subtracting indexes.
    // Assuming n==4 and intPtr==&array[n], then
    sz = n - 1;                 // 3
    sz = &array[n] - &array[1]; // 3 = &array[4] - &array[1]
    sz = intPtr - array;        // 4 = (pointer+4) - &array[0]
    assert((&array[n] - &array[1]) == 3);   // The pointers deal with memory addesses but note how the delta between memory addresses is then divided by size of elements stored in the array giving the difference expresses as distance between array ELEMENTS and NOT memory addresses.
    assert(intPtr - array == 4);
    //
    // Pointer names and array names are interchanable:
    //  A pointer can be used as if it were an array variable.
    //  The name of an array can be used as if it were a pointer.
    x = array[ n ];
    printf("X = %d ", x); // x = array[ 4 ];104 is printed
    pointer = array; // reset the pointer to &array[0]
    x = pointer[ n ];
    printf("X = %d ", x); // the same as array[4] so, again 104 is printed
    x = *(array+n);
    x = *(pointer+n);
    intPtr = &array[ n ];
    intPtr = &pointer[ n ];
    intPtr = array + n;
    intPtr = pointer + n;
    //
    // sizeof(array) is the size of the entire array in bytes
    // sizeof(array[0]) or sizeof(int) is the size of a single element
    // sizeof(array)/sizeof(array[0]) is the dimension of the array
    sz = sizeof(array);                 // 40, assuming int array[10]
    sz = sizeof(array[0]);              // 4, assuming 4 byte ints
    sz = sizeof(array)/sizeof(array[0]);// 10, works for any_type array[10]
    //
    // sizeof(pointer) = size of the pointer
    // sizeof(*pointer) = size of the variable pointer points to
    sz = sizeof(pointer);       // 8, assuming a 64-bit computer
    sz = sizeof(*pointer);      // 4, assuming 4 byte ints
    //
    // Pointers can be compared for equality, or inequality,
    //  to another pointer
    if ( intPtr == &array[ n ] )
        // true if intPtr points to array[n]
        ;
    if ( intPtr > array )
        // true if intPtr points to array[1] or anything past that
        // false if intPtr points to array[0]
        ;
    if ( intPtr < &array[sizeof(array)/sizeof(array[0])] )
        // true if intPtr points to any element of array[]
        // false if intPtr points to a non-existent element
        //  beyond the end of the array
        ;
    //
    return 0;
}
