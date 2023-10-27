
#include "echo.h"

#include <stdio.h>
#include <termios.h>
#include <stdlib.h>

#define oops(s, y) {perror(s); exit(y);}

int echo_state(int nid)
{
    struct termios info;
    int ret;

    ret = tcgetattr(nid, &info);
    if (ret == -1) {
        perror("tcgetattr");
        return -1;
    }

    if (info.c_lflag & ECHO) {
        printf("echo is on!\n");
    } else {
        printf("echo is off!\n");
    }

    return 0;
}

int set_echo(int argc, char **argv)
{
    struct termios info;
    
    if (argc != 2) {
        oops("arg num", -1);
    }

    if (tcgetattr(0, &info) == -1) {
        oops("tcgetattr", -2);
    }

    if (argv[1][0] == 'y') {
        info.c_lflag |= ECHO;
    } else {
        info.c_lflag &= ~ECHO;
    }

    if (tcsetattr(0, TCSANOW, &info) == -1) {
        oops("tcsetattr", -3);
    }

    return 0;
}
