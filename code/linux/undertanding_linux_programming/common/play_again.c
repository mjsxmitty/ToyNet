
#include <stdio.h>
#include <termios.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>

#include "play_again.h"

#define QUESTION    "do you want another transaction?"
#define SLEEP_TIME  1

int play_again()
{
    int res;

    tty_mode(0);
    set_crmode();
    set_nodelay_mode();

    signal(SIGINT, ctrl_chander);
    signal(SIGQUIT, SIG_IGN);
    
    res = get_response(5);
    tty_mode(1);

    return res;
}

char get_ok_char()
{
    int c;
    while ((c = getchar()) != EOF && strchr("yYnN", c) == NULL)
        ;
    return c;
}

int get_response(int max_tries)
{
    int c;
    printf("%s (y/n)?\n", QUESTION);
    fflush(stdout);
    
    while (1) {
        sleep(SLEEP_TIME);
        c = tolower(get_ok_char());
        if (c == 'y')
            return 0;
        if (c == 'n')
            return 1;
        if (max_tries-- == 0)
            return 2;

        putchar('\a');
    }
}

void set_crmode()
{
    struct termios tty_state;
    
    tcgetattr(0, &tty_state);

    //tty_state.c_lflag   &= ~ECHO;       // 取消回显
    tty_state.c_lflag   &= ~ICANON;     // 取消缓冲
    tty_state.c_cc[VMIN] = 1;           // 每次接收一个字符
    
    tcsetattr(0, TCSANOW, &tty_state);
}

void set_nodelay_mode()
{
    int term_flags = 0;
    term_flags = fcntl(0, F_GETFL);

    term_flags |= O_NDELAY;        // 非阻塞模式
    fcntl(0, F_SETFL, term_flags);
}

void tty_mode(int how)
{
    static struct termios   org_mode;
    static int              org_flags;
    
    if (how == 0) {
        tcgetattr(0, &org_mode);
        org_flags = fcntl(0, F_GETFL);
    } else {
        tcsetattr(0, TCSANOW, &org_mode);
        fcntl(0, F_SETFL, org_flags);
    }
}

void ctrl_chander(int sig)
{
    tty_mode(1);
    exit(1);
}



