
#include "sigdemo1.h"

#include <stdio.h>
#include <signal.h>


void f(int sig)
{
    printf("OUCH\n");
}

void sigdemo1()
{
    int i = 0;
    signal(SIGINT, f);

    for (i = 0; i != 10; ++i)
    {
        printf("Hello\n");
        sleep(1);
    }
}


