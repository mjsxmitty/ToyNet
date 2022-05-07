
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "chapter_29.h"

void Chapter_29(int argc, char **argv)
{
    chapter_29_2();
}

void chapter_29_2()
{
    int     fd, save_fd;
    char    msg[] = "this is a test\n";

    fd = open("somefile", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR); //fd --> somefile
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    save_fd = dup(STDOUT_FILENO);   // save_fd --> tty
    dup2(fd, STDOUT_FILENO);        // 1 --> somefile
    close(fd);                      // fd close
    write(STDOUT_FILENO, msg, strlen(msg));

    dup2(save_fd, STDOUT_FILENO);   // 1 --> tty, 1 somefile close
    write(STDOUT_FILENO, msg, strlen(msg));
    close(save_fd);                 // save_fd close
    return 0;
}