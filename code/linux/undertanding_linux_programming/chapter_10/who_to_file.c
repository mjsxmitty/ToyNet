
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() 
{
    int fd;
    int pid;

    if ((pid = fork()) == -1) {
        perror("fork");
        return -1;
    }

    if (pid == 0) {
        close(1);
        fd = open("who_test", O_CREAT  | O_EXCL | O_APPEND, 0644);
        if (fd == -1) {
            perror("create");
            return -1;
        }

        execlp("who", "who", NULL);
        perror("execlp");
        return -1;
    }

    if (pid != 0) {
        wait(NULL);
        printf("done running who ...\n");
    }

    return 0;
}

