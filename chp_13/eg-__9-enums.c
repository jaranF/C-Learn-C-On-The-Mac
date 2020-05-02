//
//  eg-__9-enums.c
//  chap-13
//
//  Created by Jaran F on 04/06/2019.
//
#include <stdio.h>

//|--------> FN PROTOTYPES <--------|
int main_enums( void );
//|-------->      END      <--------|

int main_enums( void ) {
  enum Weekdays {
      Monday,
      Tuesday,
      Wednesday,
      Thursday,
      Friday,
      Saturday,
      Sunday
  };
  enum Weekdays whichDay;
  whichDay = Thursday;
  printf("The variable of type \'Weekdays\' (enum) when set to \'Thursday\' = %d\n", Thursday);
  enum Colors {
      red,
      green = 5,
      blue,
      magenta,
      yellow = blue + 5
  } myColor;
  myColor = blue;
  printf("myColor = blue color is %d\n", myColor);
  enum {
      chocolate,
      stawberry,
      vanilla
  };
    int iceCreamFlavor = stawberry;
    return iceCreamFlavor;
}

/*
enum coodinateAdjustmentsNESW determineDoT( ) { // Position pos, char currCountry, enum coodinateAdjustmentsNESW directionOfTravel
    // directionOfTravel = kNone;
    return kNone;
} */


//enum coodinateAdjustmentsNESW determineDoT( Position pos, char currCountry, Boundaries gridBoundaries)
//{
//    if (pos.x > gridBoundaries.left && () )
//    return kSouth;
//}


