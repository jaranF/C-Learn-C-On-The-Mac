//
//  eg-__8-errno.c
//  chap-12
//
//  Created by JaranF on 18/02/2020.
//
#include <errno.h>  // VITAL!
#include <stdio.h>
#include <limits.h> // Path name max string len
#include <string.h>
#include <unistd.h> //chdir
#include "main_eg_entry_functions.h"

//|-----------> DEFINES <-----------|
#define kNumberOfPaths              3
//|--------> FN PROTOTYPES <--------|
static int setDirectory( char* );
//|-------->      END      <--------|

void main_errno() {
    char pathsArray[kNumberOfPaths][PATH_MAX];
    strcpy(pathsArray[0], "/private/var/db/sudo");
    strcpy(pathsArray[1], "/doesnotexist");
    strcpy(pathsArray[2], "/etc/ssh/ssh_config");
    int i = 0;
    while (i < kNumberOfPaths) {
        int setDirStatus = setDirectory(pathsArray[i++]);
        if (setDirStatus != 0) {
            int lastErrNoValue = errno;
            fprintf(stderr, "Changed Dir failed\n");
            switch (lastErrNoValue) {
                case ENOENT:
                    fprintf(stderr, "\tDirectory not found\n");
                    break;
                case EACCES:
                    fprintf(stderr, "\tPermission to CD into directory denied\n");
                    break;
                case ENOTDIR:
                    fprintf(stderr, "\tWas a file not a directory so cannot CD into it\n");
                    break;
            }
        }
    }
}

static int setDirectory(char *path) {
    return chdir(path);
}
