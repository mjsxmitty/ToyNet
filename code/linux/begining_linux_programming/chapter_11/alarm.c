
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <error.h>
#include <stdlib.h>
#include <signal.h>

static int alarm_fired = 0;

void ding(int sig)
{
    alarm_fired = 1;
}

/*发送信号*/
int main(int argc, char **argv)
{
    pid_t   pid;

    pid = fork();
    switch (pid)
    {
        case -1:
            perror("fork");
            exit(-1);
        case 0:
            sleep(5);
            kill(getppid(), SIGALRM);
            exit(0);
    }

    signal(SIGALRM, ding);
    printf("waiting for signal ...\n");

    pause();
    if (alarm_fired)
    printf("ding.\n");
    return 0;
}
