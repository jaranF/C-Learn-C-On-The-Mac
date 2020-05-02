//
//  eg-__9b-enums-passed-as-func-params.c
//  chap-13
//
//  Created by Jaran F on 05/06/2019.
//
#include "eg-__9b-enums-passed-as-func-params.h"

//|--------> FN PROTOTYPES <--------|
void main_enums_passed_as_func_params_module_scope( void );
//|-------->      END      <--------|

void main_enums_passed_as_func_params_module_scope( void ) {
    Foo = enumPassedToFunc1(); // Note that the header file defines a 'Foo' variable of module scope so there's no 'enum FooEnum Foo' required (as opposed to the below example)
    printf("The \'Foo\' variable returns \'kBAZ\' i.e. the int value = %d\n", Foo);
    enum movementAxisEnum direction = enumPassedToFunc2();
    printf("The \'direction\' variable returns \'kNorthSouth\' i.e. the int value = %d\n", direction);
    
    coordAxisMovementDeltas movementAdjuster = enumPassedToFunc3();
    printf("\nThe 'movementAdjuster var holds \'kNorth\' (int value = %d)\n", movementAdjuster);
    movementAdjuster = enumPassedToFunc4();
    printf("The 'movementAdjuster var holds \'kSouth\' (int value = %d)\n", movementAdjuster);
    movementAdjuster = enumPassedToFunc5();
    printf("The 'movementAdjuster var holds \'kEast\' (int value = %d)\n", movementAdjuster);
    movementAdjuster = enumPassedToFunc6();
    printf("The 'movementAdjuster var holds \'kWest\' (int value = %d)\n", movementAdjuster);
    movementAdjuster = enumPassedToFunc7();
    printf("The 'movementAdjuster var holds \'kNone\' (int value = %d)\n", movementAdjuster);
    return;
}

enum FooEnum enumPassedToFunc1() {
    return kBAZ;
}

enum movementAxisEnum enumPassedToFunc2() {
    return kNorthSouth;
}

coordAxisMovementDeltas enumPassedToFunc3() {
    return kNorth;
}

coordAxisMovementDeltas enumPassedToFunc4() {
    return kSouth;
}

coordAxisMovementDeltas enumPassedToFunc5() {
    return kEast;
}

coordAxisMovementDeltas enumPassedToFunc6() {
    return kWest;
}

coordAxisMovementDeltas enumPassedToFunc7() {
    return kNone;
}
