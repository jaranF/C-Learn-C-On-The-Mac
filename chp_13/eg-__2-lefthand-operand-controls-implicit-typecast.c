//
//  eg-__3-lefthand-operand-controls-implicit-typecast.c
//  chap-13
//
//  Created by Jaran F on 25/04/2019.
//
#include "eg-__2-lefthand-operand-controls-implicit-typecast.h"

//|--------> FN PROTOTYPES <--------|
void main_lefthand_operand_controls_implicit_typecast( void );
//|-------->      END      <--------|

void main_lefthand_operand_controls_implicit_typecast() {
    int i = 99;
    double d = 98.7;
    if ( i == d ) {          // Since the lefthand is a int, it is the double
        printf( "equal\n" ); // operand that must be converted so 98.8 = 98 as int.
    } else {
        printf( "neq\n" );
    }
    d = 99.0;
    if ( d == i ) {
        printf ( "2. eq\n" );
    } else {
        printf( " 2. neq\n" );
    }
}
