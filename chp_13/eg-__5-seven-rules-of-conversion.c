//
//  eg-__5-seven-rules-of-conversion.c
//  chap-13
//
//  Created by Jaran F on 09/07/2019.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void main_seven_rules_of_conversion( void );
//|-------->      END      <--------|

void main_seven_rules_of_conversion() {
    // RULE 1: Any int can safely be converted to a bigger int
    char c; short int si; int i;long int li; long long int lli;
    unsigned short int UNsi;
    unsigned int UNi;
    unsigned long int UNli;
    unsigned long long int UNlli;
    c = '~'; // 0x7e = 126decimal
    printf("c = %c\n", c);
    c += 129; // = 255decimal but displays as octal 377
    lli = li = i = si = c;
    printf("lli (signed) doesn\'t equal c instead = %lld\n", lli); // expect -1
    printf("li  (signed) doesn\'t equal c instead = %ld\n", li);   // expect -1
    printf(" i  (signed) doesn\'t equal c instead = %d\n", i);     // expect -1
    printf(" si (signed) doesn\'t equal c instead = %d\n", si);    // expect -1
    UNlli = UNli = UNi = UNsi = c;
    printf("lli (signed) doesn\'t equal c instead = %lld\n", UNlli);
    printf("li  (signed) doesn\'t equal c instead = %ld\n", UNli);
    printf(" i  (signed) doesn\'t equal c instead = %d\n", UNi);
    printf(" si (signed) doesn\'t equal c instead = %d\n", UNsi);
    // RULE 2: Any int can be converted to shorter int only if it fits
    lli = 126;
    c = si = i = li = lli;
    printf("c = %c\n", c);
    printf("li  (signed) can hold downsized long long int and becomes = %ld\n",li);
    printf(" i  (signed) can hold downsized long long int and becomes = %d\n", i);
    printf(" si (signed) can hold downsized long long int and becomes = %d\n", si);
    // If int cannot be downsized because it's outside of range
    lli = 32768;
    si = i = li = lli;
    printf("li  (signed) can hold downsized long long int (#8000) and becomes = %ld\n", li);
    printf(" i  (signed) can hold downsized long long int (#8000) and becomes = %d\n", i);
    printf("si  (signed) CANNOT hold downsized long long int (#8000) and becomes = %d\n", si); // -32768
    // RULE 3: When signed integer is converted to UNSIGNED integer one of three things can happen
    // 3 i) if the convertion is to a longer type your number will always be safely converted. For
    //      instance unsigned short to signed int = ok
    //   ii) If an unsigned number is converted to a signed number (or vice versa) with the type
    //       length staying the same then:
    //           signed to unsigned  = ok
    //           unsigned to signed = only ok the number is less than 1/2 the max value of signed
    //   iii) if the number to converted goes to a type that is shorter then the normal RULE 2 applies.
    // 3 i)
    UNsi = 65535;
    i = UNsi;
    printf("unsigned SHORT (max val #FFFF) is safely converts to signed INT, i.e.  %d\n", i);
    // 3 ii)
    UNsi = 32767;
    si = UNsi;
    printf("unsigned SHORT's max value (#7FFF) safely converted to signed SHORT, i.e. %d\n", si);
    si = ++UNsi;
    printf("unsigned SHORT's max value +1 (#8000) NOT converted to signed SHORT instead becomes %d\n", si);
}
