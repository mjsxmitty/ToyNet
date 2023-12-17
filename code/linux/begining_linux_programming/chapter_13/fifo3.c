
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
#define TEN_MSG     (1024*1024*10)

int main(int argc, char *argv[])
{
    int pipe_fd;
    int res;
    int bytes_send = 0;
    char buffer[BUFF_SIZE];

    if (access(FIFO_FILE, F_OK) == -1) {
        res = mkfifo(FIFO_FILE, 0777);
        if (res != 0) {
            perror("mkfifo");
            exit(-1);
        }
    }

    printf("process %d opening FIFO\n", getpid());
    pipe_fd = open(FIFO_FILE, O_WRONLY);
    printf("process %d result %d\n", getpid(), pipe_fd);

    if (pipe_fd != -1) {
        while (bytes_send < TEN_MSG) {
            res = write(pipe_fd, buffer, BUFF_SIZE);
            if (res == -1) {
                perror("write");
                exit(-1);
            }
            bytes_send  = bytes_send + res;
        }
        close(pipe_fd);
    }
    
    return 0;
}