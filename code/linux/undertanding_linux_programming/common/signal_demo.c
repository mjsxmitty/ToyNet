
#include "signal_demo.h"

#include <stdio.h>
#include <signal.h>

#define INPUT_LEN   100

void f(int sig)
{
    printf("OUCH\n");
}

void signal_demo()
{
#if 0
    int i = 0;
    signal(SIGINT, f);

    for (i = 0; i != 10; ++i)
    {
        printf("Hello\n");
        sleep(1);
    }
#endif

    char    input[INPUT_LEN];
    int     nchars;

    signal(SIGINT, init_handle);
    signal(SIGQUIT, quit_handle);

    do {
        printf("\ntype a seies of message: ");
        nchars = read(0, input, INPUT_LEN - 1);
        if (nchars == -1) {
            perror("read error: ");
        } else {
            input[nchars] = '\0';
            printf("\nyou typed: %s\n", input);
        }
    } while (strncmp(input, "quit", 4) != 0);
}


void init_handle(int sig_num)
{
    printf("received sig: %d, waiting\n", sig_num);
    sleep(1);
    printf("leving init handle.\n");
}

void quit_handle(int sig_num)
{
    printf("received sig: %d, waiting\n", sig_num);
    sleep(2);
    printf("leving quit handle.\n");
}


