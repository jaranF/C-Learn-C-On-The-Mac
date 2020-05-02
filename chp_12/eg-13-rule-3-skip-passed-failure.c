//
//  eg-13-rule-3-skip-passed-failure.c
//  chap-12
//
//  Created by JaranF on 02/05/2020.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//|-----------> DEFINES <-----------|
#define kMaxTitleLength             256
//|-----------> STRUCTS <-----------|
//|------> TYPEDEFS & ENUMS <-------|
//|--------> FN PROTOTYPES <--------|
void main_rule_3_skip_passed_failure( void );
int DoSomething( void );
int DoSomethingElse( void );
int DoThirdThing( void );
//|-------->      END      <--------|
const int ERROR = -1;

void main_rule_3_skip_passed_failure()
{
    bool problemOccurred = false;
    srand((int unsigned)clock());   // Seed rand() function.
    if (DoSomething() == ERROR)
        problemOccurred = true;
    if (!problemOccurred) {
        if (DoSomethingElse() == ERROR) {
            problemOccurred = true;
        }
    }
    if (!problemOccurred)
        if (DoThirdThing() == ERROR)
            problemOccurred = true;
    if (!problemOccurred) {
        // everything was successful
        printf("Everything was successful\n");
    } else {
        // a problem ocurred
        fprintf(stderr, "A problem occurred\n");
    }
}

int DoSomething()
{
    return rand() % 2 == 0 ? 0 : -1;
}

int DoSomethingElse()
{
    return rand() % 2 == 0 ? 0 : -1;
}

int DoThirdThing()
{
    return 0;
}
