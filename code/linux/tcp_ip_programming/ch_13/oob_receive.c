
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <signal.h>

#define BUFF_SIZE   512

int server_socket, client_socket;

void oob_handler(int sig) {
    int     str_len;
    char    msg[BUFF_SIZE];

    str_len = recv(client_socket, msg, sizeof(msg) - 1, MSG_OOB);
    msg[str_len] = 0;
    printf("oob msg: %s\n", msg);
}

int main(int argc, char **argv) 
{
    struct sockaddr_in  server_addr;
    struct sockaddr_in  client_addr;
    socklen_t           client_addr_size;    

    int     str_len;
    char    msg[BUFF_SIZE];

    struct sigaction act;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(-1);
    }

    act.sa_handler = oob_handler;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
        
    sigaction(SIGURG, &act, 0);

    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(-1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(-1);
    }

    if (listen(server_socket, 5)) {
        perror("listen");
        exit(-1);
    }

    client_addr_size = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
    if (client_socket == -1) {
        perror("accept");
        exit(-1);
    }

    fcntl(client_socket, F_SETOWN, getpid());     // 防止影响多个进程

    while ((str_len = recv(client_socket, msg, sizeof(msg), 0)) != 0) {
        if (str_len == -1)
            continue;
        msg[str_len] = 0;
        puts(msg);
    }

    close(client_socket);
    close(server_socket);
    return 0;
}

