//
//  eg-__9c-enums-with-typedefs.c
//  chap-13
//
//  Created by Jaran F on 17/06/2019.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void main_enums_with_typedefs( void );
//|-------->      END      <--------|

void main_enums_with_typedefs() {
    typedef enum {
        kNone,
        kNorth,
        kSouth
    } DirNSaxis;
    typedef enum {
        kEast = 1,
        kWest
    } DirEWaxis;
    DirNSaxis dir = kSouth;
    dir = kSouth;
}
