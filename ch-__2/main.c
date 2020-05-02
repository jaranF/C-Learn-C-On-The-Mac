//
//  main.c
//  Chap-__2/Listing 2-1
//
//  Created by Jaran F on 28/12/2014.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
int main( int argc, const char * argv[] );
//|-------->      END      <--------|

int main(int argc, const char * argv[])
{
    int number, sum;
    sum = 0;
    for (number = 1; number <= 10; number++)
        sum += number;
    printf("The sum of numbers from 1 to 10 i s %d\n", sum);
    return 0;
}

