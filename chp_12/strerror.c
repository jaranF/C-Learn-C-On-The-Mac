//
//  strerror.c
//  chap-12
//
//  Created by JaranF on 18/02/2020.
//
#include <errno.h>  // VITAL!
#include <stdio.h>
#include <limits.h> // Path name max string len
#include <string.h> // strerror()
#include <unistd.h> //chdir
#include "main_eg_entry_functions.h"

//|-----------> DEFINES <-----------|
#define kNumberOfPaths              3
//|--------> FN PROTOTYPES <--------|
static int setDirectory( char* );
//|-------->      END      <--------|

void main_strerror() {
    char pathsArray[kNumberOfPaths][PATH_MAX];
    strcpy(pathsArray[0], "/private/var/db/sudo");
    strcpy(pathsArray[1], "/doesnotexist");
    strcpy(pathsArray[2], "/etc/ssh/ssh_config");
    int i = 0;
    while (i < kNumberOfPaths) {
        if (setDirectory(pathsArray[i++]) != 0) {
            fprintf(stderr, "%s\n", strerror(errno));
        }
    }
}

static int setDirectory(char *path) {
    return chdir(path);
}
