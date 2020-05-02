//
//  eg-__9b-enums-passed-as-func-params.h
//  chap-13
//
//  Created by Jaran F on 05/06/2019.
//
#ifndef eg___9b_enums_passed_as_func_params_h
#define eg___9b_enums_passed_as_func_params_h

#include <stdio.h>

//|------> TYPEDEFS & ENUMS <-------|
enum FooEnum {
    kBAR,
    kBAZ
} Foo;  // Note instance variable declared after closing curly bracket.
enum movementAxisEnum {
    kNorthSouth,
    kEastWest
};
typedef enum {
    kNorth = -1, kEast = -1,
    kNone = 0,
    kSouth = 1, kWest= 1
} coordAxisMovementDeltas;

//|--------> FN PROTOTYPES <--------|
enum FooEnum enumPassedToFunc1( void );
enum movementAxisEnum enumPassedToFunc2( void );
coordAxisMovementDeltas enumPassedToFunc3(void);    // Note with a 'typedef' you don't
coordAxisMovementDeltas enumPassedToFunc4(void);    // have to use the 'enum' keyword'
coordAxisMovementDeltas enumPassedToFunc5(void);    // as we see here with the return
coordAxisMovementDeltas enumPassedToFunc6(void);    // type on these function
coordAxisMovementDeltas enumPassedToFunc7(void);    // prototyes definitions.
//|-------->      END      <--------|
//
// Below: Demonstration of function prototype definition where an enum is returned
/*
 enum coodinateAdjustmentsNESW determineDoT(  Position pos, char currCountry, Boundaries gridBoundaries );
 
 typedef struct {
 int top;
 int right;
 int bottom;
 int left;
 } Boundaries;
 
 typedef struct {
 int y;
 int x;
 } Position;
 */
#endif /* eg___9b_enums_passed_as_func_params_h */
