//
//  eg-__2-get-home-directory.c
//  chap-11
//
//  Created by Jaran F on 16/03/2019.
//
#include "eg-__3-get-home-directory.h"

void SetHomeDirectory() {
    struct passwd *pw;
    pw = getpwuid( getuid() );
    chdir( pw->pw_dir );
}
