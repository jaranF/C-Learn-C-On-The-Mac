//
//  eg-__9a-enums-with-duplicate-ints-represented.c
//  chap-13
//
//  Created by Jaran F on 05/06/2019.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void main_enums_with_duplicate_ints_represented( void );
//|-------->      END      <--------|

void main_enums_with_duplicate_ints_represented() {
    enum coodinateAdjustmentsNESW {
        kNorth = -1, kEast = -1,
        kNone = 0,
        kSouth = 1, kWest= 1
    };
    enum coodinateAdjustmentsNESW direction = kNorth;
    printf("kNorth = %d\n", direction);
}
