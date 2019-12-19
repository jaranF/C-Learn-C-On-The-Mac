//
//  eg-__7-prime-finder.c
//  chap-__6
//
//  Created by Jaran F on 09/02/2016.
//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//|--------> FN PROTOTYPES <--------|
int main_prime_finder( void );
//|-------->      END      <--------|

int main_prime_finder()
{
    bool  isPrime;
    int   startingPoint, candidate, last, i;
    //
    startingPoint = 235;
    //
    if (startingPoint < 2) {
        candidate = 2;
    } else if (startingPoint == 2) {
        candidate = 3;
    } else {
        candidate = startingPoint;
        if (candidate % 2 == 0)        //Test only odd numbers.
            candidate--;
        do {
            isPrime = true;
            candidate += 2;
            last = sqrt(candidate);
            //
            //Loop through odd numbers only
            for (i = 3; (i <= last) && isPrime; i += 2) {
                if ((candidate % i) == 0)
                    isPrime = false;
            }
        } while ( ! isPrime);
    }
    printf("The next prime number after %d is %d. Happy!?", startingPoint, candidate);
    return 0;
}


