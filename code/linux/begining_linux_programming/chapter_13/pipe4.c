
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define BUFF_SIZE   64

int main(int argc, char *argv[])
{
    int recv_cnt;
    char buffer[BUFF_SIZE];
    int file_fd;
    
    memset(buffer, 0, sizeof(buffer));
    sscanf(argv[1], "%d", &file_fd);

    recv_cnt = read(file_fd, buffer, BUFF_SIZE);
    printf("%d - read %d bytes: %s\n", getpid(), recv_cnt, buffer);

    return 0;
}
