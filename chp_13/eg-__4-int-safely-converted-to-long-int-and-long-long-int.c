//
//  eg-__4-int-safely_converted_to_long_int_and_long_long_int.c
//  chap-13
//
//  Created by Jaran F on 09/06/2019.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void main_int_safely_converted_to_long_int_and_long_long_int( void );
//|-------->      END      <--------|

void main_int_safely_converted_to_long_int_and_long_long_int() {
    int i32bits;
    i32bits = 2147483647; // Assuming four byte sized ints              = 7f ff ff ff
    unsigned int uI32bits = 4294967295; // Assuming four byte sized ints = ff ff ff ff
    printf("Size of Int is %zu bytes\n", sizeof(i32bits));
                                      // Assuming eight byte sized longs = xx xx xx xx 7f ff ff ff
    long int lI64bits = uI32bits;     // There's is capacity as a long int has extra xx (4 bytes)

    printf("The value of signed int i when auto-typecasting to bigger (long int) = %ld\n", lI64bits);
    lI64bits = uI32bits;              // There is still capacty
    printf("The value of max value\'d UNSIGNED int i when auto-typecasting to bigger (long int) = %ld\n", lI64bits);
    printf("Size of LONG Int is %zu bytes\n", sizeof(lI64bits));
    long long int llI64bits;
    printf("Size of LONG LONG Int is %zu bytes\n", sizeof(llI64bits));
    unsigned long int uLongI64bits = 0xFFFFFFFFFFFFFFFF;
    printf("The value of max value\'d UNSIGNED LONG int i when auto-typecasting to bigger (long long int) = %zu\n", uLongI64bits);
    // li = uint32bit
    
}
