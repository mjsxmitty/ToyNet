
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <unistd.h>


#define BUFF_SIZE   512

int main(int argc, char **argv) 
{
    int fd1, fd2;
    int max_fd;
    fd_set  read_fds;
    int ret;
    struct timeval time_out;

    if (argc != 3) {
        fprintf(stderr, "usage: %s file1 file2 timeout.\n", *argv);
        exit(-1);
    }

    if ((fd1 = open(argv[1], O_RDONLY)) == -1) {
        perror("open");
        exit(-2);
    }

    if ((fd2 = open(argv[2], O_RDONLY)) == -1) {
        perror("open");
        exit(-2);
    }
    
    max_fd = 1 + (fd1 > fd2 ? fd1 : fd2);
    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(fd1, &read_fds);
        FD_SET(fd1, &read_fds);

        time_out.tv_sec = atoi(argv[2]);
        time_out.tv_usec = 0;

        ret = select(max_fd, &read_fds, NULL, NULL, &time_out);
        if (ret == -1) {
            perror("select");
            exit(-3);
        }

        if (ret > 0) {
            if (FD_ISSET(fd1, &read_fds)) {
                show_data(argv[1], fd1);
            }
            if (FD_ISSET(fd2, &read_fds)) {
                show_data(argv[2], fd2);
            }
        } else {
            printf("no input after %d seconds\n", atoi(argv[2]));
        }
    }
}

void show_data(char *file_name, int fd) {
    char buf[BUFF_SIZE];
    int n;

    printf("%s: ", file_name);
    fflush(stdout);

    n = read(fd, buf, BUFF_SIZE);
    if (n == -1) {
        perror("read");
        exit(-4);
    }
    write(1, buf, n);
    write(1, "\n", 1);
}