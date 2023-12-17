
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

#define FIFO_FILE "./my_fifo"

int main(int argc, char *argv[])
{
    int res, i;
    int open_mode = 0;

    if (argc < 2) {
        fprintf(stderr, "usage: %s <O_RDONLY|O_WRONLY|O_NONBLOCK>\n", argv[0]);
        return -1;
    }

    for (i = 1; i < argc; ++i) {
        if (strncmp(argv[i], "O_RDONLY", 8) == 0)
            open_mode |= O_RDONLY;
        if (strncmp(argv[i], "O_WRONLY", 8) == 0)
            open_mode |= O_WRONLY;
        if (strncmp(argv[i], "O_NONBLOCK", 8) == 0)
            open_mode |= O_NONBLOCK;
    }

    if (access(FIFO_FILE, F_OK) == -1) {
        res = mkfifo(FIFO_FILE, 0777);
        if (res != 0) {
            perror("mkfifo");
            exit(-1);
        }
    }

    printf("process %d opening FIFO\n", getpid());
    res = open(FIFO_FILE, open_mode);
    printf("process %d result %d\n", getpid(), res);
    sleep(5);
    if (res != -1)
        close(res);
    printf("process %d finished\n", getpid());
    return 0;
}