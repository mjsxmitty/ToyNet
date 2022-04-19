
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>

#include "chapter_04.h"

#ifndef BUF_SIZE
#define BUF_SIZE    1024
#endif

/* 
 * copy.c 
 * Copy the file named argv[1] to a new file named in argv[2].
 */
void chapter_4_1(int argc, char **argv)
{
    int input_fd, out_fd, open_flags;
    mode_t  file_perms;
    ssize_t num_read;

    if (argc != 3 || strcmp(argv[1], "--help"))
    {
        printf("USAGE: %s old_file new_file\n", argv[0]);
        return ;
    }
    
    
}
