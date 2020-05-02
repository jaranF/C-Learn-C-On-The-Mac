//
//  eg-__1-namer.c
//  chap-__9
//
//  Created by Jaran F on 20/01/2017.
//
#include <stdio.h>
#include <string.h>

//|--------> FN PROTOTYPES <--------|
void namer();
//|------->      END      <--------|

void namer()
{
  char name[20];
  printf( "Type your firstname, please\n" );
  scanf( "%s", name);
  printf( " Hello %s!\n", name );
  printf( "The number of characters in your name is %ld\n", strlen(name));
}
