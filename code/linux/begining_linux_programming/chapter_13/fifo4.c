
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <limits.h>

#define FIFO_FILE "./my_fifo"
#define BUFF_SIZE PIPE_BUF

int main(int argc, char *argv[])
{
    int pipe_fd;
    int res = 0;
    int bytes_send = 0;
    char buffer[BUFF_SIZE];

    memset(buffer, 0, sizeof(buffer));

    printf("process %d opening FIFO\n", getpid());
    pipe_fd = open(FIFO_FILE, O_RDONLY);
    printf("process %d result %d\n", getpid(), pipe_fd);

    if (pipe_fd != -1) {
        do {
            res = read(pipe_fd, buffer, BUFF_SIZE);
            bytes_send  = bytes_send + res;
        } while (res > 0);
        close(pipe_fd);
    }
    
    printf("process %d finished, %d bytes read\n", getpid(), bytes_send);
    return 0;
}