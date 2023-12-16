
#define _XOPEN_SOURCE

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ouch(int sig)
{
    printf("OUCH-get a signal %d\n", sig);
}

int main(int argc, char **argv)
{
    struct sigaction act;
    act.sa_handler = ouch;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    
    sigaction(SIGINT, &act, 0);

    while (1)
    {
        printf("hello world\n");
        sleep(1);
    }
    
    return 0;
}