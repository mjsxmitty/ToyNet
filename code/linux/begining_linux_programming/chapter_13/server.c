
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
    char *pbf;
    struct data_to_pass recv_data;
    int read_cnt;
    char client_info[BUFF_SIZE];

    mkfifo(SERVER_FIFO_FILE, 0777);
    server_fifo_fd = open(SERVER_FIFO_FILE, O_RDONLY);
    if (server_fifo_fd == -1) {
        perror("open");
        exit(-1);
    }

    sleep(10);

    do
    {
        read_cnt = read(server_fifo_fd, &recv_data, sizeof(recv_data));
        if (read_cnt > 0) {
            pbf = recv_data.data;
            while (*pbf) {
                *pbf = toupper(*pbf);
                pbf++;
            }
            sprintf(client_info, CLIENT_FIFO_FILE, recv_data.client_pid);

            client_fifo_fd = open(client_info, O_WRONLY);
            if (client_fifo_fd != -1) {
                write(client_fifo_fd, &recv_data, sizeof(recv_data));
                close(client_fifo_fd);
            }
        }
    } while (read_cnt > 0);
    
    close(server_fifo_fd);
    unlink(SERVER_FIFO_FILE);

    return 0;
}
