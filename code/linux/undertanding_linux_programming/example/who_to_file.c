
#include "who_to_file.h"
#include <unistd.h>
#include <stdio.h>

void who_to_file() {
    int fd;
    int pid;

    if ((pid = fork()) == -1) {
        perror("fork");
        return ;
    }

    if (pid == 0) {
        close(1);
        fd = creat("usertest", 0644);
        if (fd == -1) {
            perror("create");
            return ;
        }

        execlp("who", "who", NULL);
        perror("execlp");
        return ;
    }

    if (pid != 0) {
        wait(NULL);
        printf("done runing who ...\n");
    }
}

