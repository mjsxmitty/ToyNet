
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
        sprintf(buffer, "%d", file_pipes[0]);
        execl("./pipe4", "pipe4", buffer, (char *)0);
        exit(-1);
    } else {
        cnt = write(file_pipes[1], data, strlen(data));
        printf("%d - write %d bytes\n", getpid(), cnt);
    }

    return 0;
}
