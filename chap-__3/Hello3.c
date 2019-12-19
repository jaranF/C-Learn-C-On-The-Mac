//
//  Hello3.c
//  chap-__3
//
//  Created by Jaran F on 28/12/2014.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
void sayHello( void );
//|-------->      END      <--------|

int main2(int argc, const char * argv[])
{
    sayHello();
    sayHello();
    sayHello();
    return 0;
}

void sayHello() {
    printf("Hello, World!\n");
}

