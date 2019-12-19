//
//  eg-__7-fseeko-random-access.c
//  chap-11
//
//  Created by JaranF on 07/10/2019.
//
// This fseeko file reading function:
// fseeko(fPtr, [off_t]OFFSETNUM, [SEEK_SET | SEEK_CUR | SEEK_END]);
// Note the constant at the end determines if the OFFSET (in bytes) is from the BEGINNING
// (i.e. SEEK_SET) of the file or the end.
// MASSIVELY IMPORTANT: When 'fseeko()' is used don't expect to use a 'fscanf()' after it;
// No, that gets really screwed up. Instead you have to use a 'fread()' command instead.
// Other file functions are:
// fgetc()   .. .. 1 char at time; Have to manually check for EOF, limits and newline.
// fputc()   .. .. 1 char at a time.
// fgets()   .. .. Whole files at a time until either EOF or SIZE worth of bytes being read.
// fscanf()  .. .. like the keyboard reading function but applies to file streams.
#include <stdio.h>
#include <string.h>
#include "eg-__3-get-home-directory.h"

//|-----------> DEFINES <-----------|
#define kDataFileName               "dicethrow_distribution_freq"
#define kPathInHomeDir              "./Documents/learning/c/Learn_C_On_The_Mac/chap-11/"
#define FULLFILEURI(VOID) (#VOID kPathInHomeDir kDataFileName)
//|--------> FN PROTOTYPES <--------|
int main_fseeko_random_access( void );
void Flush( void );
//|-------->      END      <--------|

int main_fseeko_random_access()
{
    int retValue = 0;
    int num;
    FILE *fp;
    SetHomeDirectory();
    fp = fopen( FULLFILEURI() , "r" );
    if ( NULL == fp ) {
        printf("Error opening file \'%s\'\n", kDataFileName);
        printf("In file path...\n");
        printf("%s\n", kPathInHomeDir);
        retValue = -1;
    } else {
        off_t seekbytes;
        size_t bytesread;
        do {
            printf("Enter dice tally to get freq of (2 to 12 or 0 to exit): ");
            scanf("%lld", &seekbytes);
            if (seekbytes == 0) break;
            else if (seekbytes < 2 || seekbytes > 12)
                printf("Out of range! Acceptable input is 2 to 12 only. Please try again: ");
            else {
                fseeko(fp, ((seekbytes - 2) * sizeof(int)), SEEK_SET);
                bytesread = fread(&num, sizeof(int), 1, fp);
                if (bytesread != 0) {
                    printf("\nFrequency of tally %lld from two dice roles %d\n", seekbytes, num);
                } else {
                    fprintf( stderr, "error reading file (error num = %d)\n", 1);
                }
            }
        } while (seekbytes != 0);
        printf("Exiting ...\n");
        fclose(fp);
    }
    return retValue;
}

void Flush( void )
{
    while ( getchar() != '\n' )
        ;
}
