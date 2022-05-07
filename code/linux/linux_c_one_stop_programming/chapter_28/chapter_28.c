
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termio.h>
#include <termios.h>
#include <sys/mman.h>

#include "chapter_28.h"

void Chapter_28(int argc, char **argv)
{
    //Practice_28_3();
    //Practice_28_4();
    //Practice_28_5();
    //Practice_28_6(argc, argv);
    //Practice_28_7();
    Practice_28_8();
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

    // while ((n = read(fd, buf, 5)) < 0) {
    //     if (errno == EAGAIN) {
    //         sleep(3);
    //         write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
    //         continue;
    //     }

    //     perror("read /dev/tty ");
    //     exit(1);
    // }
    
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

/*fcntl 改变file status(已打开)*/
int Practice_28_5()
{
    char    buf[64];
    int     fd, flags, n;

    flags = fcntl(STDIN_FILENO, F_GETFL);
    // flags |= O_NONBLOCK;
    // if (fcntl(STDIN_FILENO, F_SETFL, flags) == -1) {
    //     perror("fcntl");
    //     exit(1);
    // }

    while ((n = read(STDIN_FILENO, buf, 10)) < 0) {
        if (errno == EAGAIN) {
            sleep(1);
            write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
            continue;
        }
        
        perror("read stdin.");
        exit(1);
    }
    
    write(STDOUT_FILENO, buf, n);
    return 0;
}

int Practice_28_6(int argc, char **argv)
{
    int     val;
    if (argc != 2) {
        fputs("usage: ./execution <file>\n", stderr);
        exit(1);
    }

    if ((val = fcntl(atoi(argv[1]), F_GETFL)) < 0) {
        printf("fcntl error for fd %d\n", atoi(argv[1]));
        exit(1);
    }
    
    switch (val & O_ACCMODE)
    {
    case O_RDONLY:
        printf("read only");
        break;
    case O_WRONLY:
        printf("write only");
        break;
    case O_RDWR:
        printf("read write");
        break;
    default:
        fputs("invalid access mode.\n", stderr);
        break;
    }

    if (val & O_APPEND)
        printf(", append");
    
    if (val & O_NONBLOCK)
        printf(", nonblock");
    
    putchar('\n');
    return 0;
}

/* ioctl 获取设备信息 */
int Practice_28_7()
{
    struct winsize size;

    //判断是否是终端机
    if (isatty(STDIN_FILENO) == 0)
        exit(1);

    if (ioctl(STDIN_FILENO, TIOCGWINSZ, &size) < 0) {
        perror("ioctl TIOCGWINSZ error");
        exit(1);
    }
    
    printf("%d rows, %d cols\n", size.ws_row, size.ws_col);
    return 0;
}

int Practice_28_8()
{
    int *p, fd;
    fd = open("hello", O_RDWR);
    if (fd < 0) {
        perror("open hello");
        exit(1);
    }

    p = mmap(NULL, 6, PROT_WRITE, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    close(fd);

    p[0] = 0x30313233;
    munmap(p, 6);   //解除映射
    return 0;
}