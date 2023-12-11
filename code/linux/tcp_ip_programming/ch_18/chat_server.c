
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

#define BUFF_SIZE   1024
#define MAX_CLIENTS 256

int client_cnt;
int client_sockets[MAX_CLIENTS];
pthread_mutex_t mutex;

void handle_client(void *)
{

}

int main(int argc, char **argv)
{
    int                 server_socket, client_socket;
    struct sockaddr_in  server_addr, client_addr;
    socklen_t           client_addr_size;

    pthread_t   pid;
    int res = 0;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(-1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = PF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(-1);
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(-1);
    }

    while (1) {
        client_addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_socket, &client_addr_size);
        if (client_socket == -1) {
            perror("accept");
            break;
        }

        
    }
    
    return 0;
}
