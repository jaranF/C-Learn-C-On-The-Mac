//
//  ex-__2-guess-myInt-val-after.c
//  chap-__4
//
//  Created by Jaran F on 31/12/2014.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void Exercise2 ( void );
//|-------->      END      <--------|

void Exercise2 ()
{
    int myInt;
    //
    myInt = 5;
    myInt *= (3 + 4) * 2;  //expect 70
    printf( "myInt ---> %d\n", myInt );
    //
    myInt = 2;
    myInt *= ((3 + 4) * 2) - 9;  //expect 10
    printf( "myInt ---> %d\n", myInt );
    //
    myInt = 2;
    myInt /= 5; // 2 divided by 5 - 0,4 (but truncated to 0 [zero])
    myInt--;  //expect -1
    printf( "myInt ---> %d\n", myInt );
    //
    myInt = 25;
    myInt /= 3 * 2;  //expect 4
    printf( "myInt ---> %d\n", myInt );
    //
    myInt = (3 * 4 * 5) / 9;
    myInt -= (3 + 4) * 2; //expect -8 i.e. 60 / 9 = (6 truncated) - 14 = -8
    printf( "myInt ---> %d\n", myInt );
    //
    myInt = 5;
    printf( "myInt ---> %d\n", myInt = 2); //expect 2
    //
    myInt = 1;
    myInt /= (3 + 4) / 6; //expect 1
    printf( "myInt ---> %d\n", myInt );  
}
