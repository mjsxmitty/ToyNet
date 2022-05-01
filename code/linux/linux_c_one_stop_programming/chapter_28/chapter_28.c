
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "chapter_28.h"

void Chapter_28()
{
    //Practice_28_3();
    Practice_28_4();
}

#define MSG_TRY     "try again\n"

/*非阻塞读终端*/
int Practice_28_3()
{
    char    buf[10];
    int     fd, n;

    fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
    if (fd < 0) {
        perror("open /dev/tty.");
        exit(1);
    }

tryagain:

    n = read(fd, buf, 5);
    if (n < 0) {
        if (errno == EAGAIN) {
            sleep(5);
            write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
            goto tryagain;
        }

        perror("read /dev/tty");
        exit(1);
    }
    
    write(STDOUT_FILENO, buf, n);
    close(fd);
    return 0;
}

#define MSG_TIMEOUT     "timeout\n"

/*非阻塞读终端和等待超时*/
int Practice_28_4()
{
    char    buf[10];
    int     fd, n, i;

    fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
    if (fd < 0) {
        perror("open /dev/tty.");
        exit(1);
    }

    for (i = 0; i < 5; i++) {
        n = read(fd, buf, 10);
        if (n >= 0) 
            break;
        
        if (errno != EAGAIN) {
            perror("read /dev/tty.");
            exit(1);
        }

        sleep(2);
        write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
    }
    
    if (i == 5)
        write(STDOUT_FILENO, MSG_TIMEOUT, strlen(MSG_TIMEOUT));
    else
        write(STDOUT_FILENO, buf, n);
    
    close(fd);
    return 0;
}