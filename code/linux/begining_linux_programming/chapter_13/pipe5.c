
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

#define BUFF_SIZE   64

int main(int argc, char **argv)
{
    int file_pipes[2];
    char buffer[BUFF_SIZE];
    pid_t   pid;
    int cnt = 0;
    const char data[] = "123";

    memset(buffer, 0, sizeof(buffer));
    if(pipe(file_pipes) == -1) {
        perror("pipe");
        exit(-1);
    }

    if ((pid = fork()) == (pid_t) -1) {
        perror("fork");
        exit(-1);
    }

    if (pid == 0) {
        close(0);
        dup(file_pipes[0]);
        close(file_pipes[0]);
        close(file_pipes[1]);
        execlp("od", "od", "-c", (char *)0);
        exit(-1);
    } else {
        close(file_pipes[0]);
        cnt = write(file_pipes[1], data, strlen(data));
        close(file_pipes[1]);
        printf("%d - write %d bytes\n", getpid(), cnt);
    }

    return 0;
}
