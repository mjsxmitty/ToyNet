
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

#define BUFF_SIZE 32
#define SERVER_FIFO_FILE    "./server_fifo"
#define CLIENT_FIFO_FILE    "./client_%d_fifo"

struct data_to_pass
{
    pid_t client_pid;
    char data[BUFF_SIZE];
};

int main(int argc, char **argv)
{
    int server_fifo_fd, client_fifo_fd;;
    struct data_to_pass send_data;
    int send_cnt;
    char client_info[BUFF_SIZE];

    server_fifo_fd = open(SERVER_FIFO_FILE, O_WRONLY);
    if (server_fifo_fd == -1) {
        perror("open");
        exit(-1);
    }

    send_data.client_pid = getpid();
    sprintf(client_info, CLIENT_FIFO_FILE, send_data.client_pid);
    if (mkfifo(client_info, 0777) == -1) {
        perror("mkfifo");
        exit(-1);
    }

    for ( send_cnt = 0; send_cnt < 5; send_cnt++) {
        sprintf(send_data.data, "hello from %d", send_data.client_pid);
        printf("%d send [%s]", send_data.client_pid, send_data.data);
        write(server_fifo_fd, &send_data, sizeof(send_data));

        client_fifo_fd = open(client_info, O_RDONLY);
        if (client_fifo_fd != -1) {
            if (read(client_fifo_fd, &send_data, sizeof(send_data)) > 0) {
                printf(", received: [%s]\n", send_data.data);
            }
            close(client_fifo_fd);
        }
    }
    
    close(server_fifo_fd);
    unlink(client_info);
    
    return 0;
}
