//
//  eg-__3-get-home-directory.h
//  chap-11
//
//  Created by JaranF Work-MBP on 07/09/2019.
//
#ifndef eg___2_get_home_directory_h
#define eg___2_get_home_directory_h

#include <pwd.h>
#include <unistd.h>

//|--------> FN PROTOTYPES <--------|
extern void SetHomeDirectory( void ); // if you miss out the extern keyword then it's assumed to be 'extern' anyway
//|-------->      END      <--------|

#endif /* eg___2_get_home_directory_h */
