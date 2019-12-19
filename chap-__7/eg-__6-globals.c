//
//  eg-__6-globals.c
//  chap-__7
//
//  Created by Jaran F on 16/06/2016.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
int main_demonstrate_need_for_global( void );
void PassAlong( int myVar );
void PrintMyVar( int myVar );
//|-------->      END      <--------|

int main_demonstrate_need_for_global( void )
{
  int myVar;
  myVar = 10;
  PassAlong( myVar );
  return 0;
}

void PassAlong( int myVar )
{
  PrintMyVar( myVar );
}

void PrintMyVar( int myVar )
{
  printf( "myVar = %d\n", myVar );
}
