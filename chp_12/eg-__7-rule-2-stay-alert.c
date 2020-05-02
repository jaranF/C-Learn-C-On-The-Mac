//
//  eg-__7-rule-2-stay-alert.c
//  chap-12
//
//  Created by JaranF on 18/02/2020.
//
#include <stdio.h>
#include <pwd.h>
#include <unistd.h>
#include <assert.h>
#include "main_eg_entry_functions.h"

//|--------> FN PROTOTYPES <--------|
static int SetHomeDirectory( void );
//|-------->      END      <--------|

void main_rule_2_stay_alert_to_return_values() {
    if (SetHomeDirectory() !=0) {
        fprintf(stderr, "Runtime Error! Could not change directory to desired path.");
    }
}

/* Note the Function signature IS NOT:
void SetHomeDirectory( void ); */
static int SetHomeDirectory() {
    struct passwd *pw = getpwuid(getuid());
    assert(pw != NULL);
    return chdir(pw->pw_dir);
} // Actually return something useful to the calling Function so it can assertain the success or failure of the change
  // directory attempt.
