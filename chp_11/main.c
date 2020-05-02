
//  main.c
//  chap-11
//
//  Created by Jaran F on 22/05/2016.
//

//void SetHomeDirectory( void );  THIS CAN BE REMOVED IF YOU BRING IN THE GET_HOME.H HEADERFILE
//                                AND THAT HAS THE ENTRY:
//                                extern void SetHomeDirectory( void );
#include "eg-__3-get-home-directory.h"
#include "eg-__6-read-into-array-of-structs-with-fgets.h"

int main_fgetc_readchar( void );
int main_fgets_readfile( void );
int main_fgets_readfile_with_eof_encountered_before_size_limit( void );
int main_fgets_readfile_with_size_limit_restriction_kicking_in_before_eof( void );
int main_fscanf_exploration_line_at_a_time( void );
int main_fputc_write_chars_to_file( void );
char* generateRandomString( int len );
void main_fn_prototypes_and_extern_without_header ( void );
int main_fseeko_random_access( void );
void main_fwrite_and_endianness_hacks( void );
int main_various_num_of_ints_per_line_solutionA( int, const char * argv[] );
int main_various_num_of_ints_per_line_solutionB( int, const char * argv[] );

int main(int argc, const char * argv[])
{
    // main_fgets_readfile();
    // main_fgetc_readchar();
    // SetHomeDirectory();
    // main_fscanf_exploration_line_at_a_time();
    // main_fgets_readfile_with_eof_encountered_before_size_limit();
    // main_fgets_readfile_with_size_limit_restriction_kicking_in_before_eof();
    // main_read_into_array_of_structs_with_fgets();
    // main_fputc_write_chars_to_file();
    // main_fseeko_random_access();
    // main_fwrite_and_endianness_hacks();
    main_various_num_of_ints_per_line_solutionB(argc, argv);
    return 0;
}

// If you had the line:
//     #include "modularizationExample.h"
// but within that HEADER file the setHomeDirectory was defined with the static keyword
// then in this module, where you use the function the function would have to be defined
// as per the below.
// void SetHomeDirectory() {
//     struct passwd *pw;
//     pw = getpwuid( getuid() );
//     chdir( pw->pw_dir );
// }
