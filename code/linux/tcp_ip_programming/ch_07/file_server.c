
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFF_SIZE 30

int main(int argc, char **argv) 
{
    int                 server_socket, client_socket;
    struct sockaddr_in  server_addr, client_addr;
    socklen_t           client_addr_size;

    char                buf[BUFF_SIZE];
    FILE                *fp;
    int                 read_cnt;
    
    if (argc != 3) {
        fprintf(stderr, "usage: %s <port> <file>.\n", argv[0]);
        exit(-1);
    }

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

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(-1);
    }

    client_addr_size = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
    if (client_socket == -1) {
        perror("accept");
        exit(-1);
    }

    fp = fopen(argv[2], "rb");
    if (fp == NULL) {
        perror("fopen");
        exit(-1);
    }

    while (1) {
        read_cnt = fread((void*)buf, 1, BUFF_SIZE, fp);
        if (read_cnt < BUFF_SIZE) {
            write(client_socket, buf, read_cnt);
            break;
        }
        write(client_socket, buf, BUFF_SIZE);
    }

    shutdown(client_socket, SHUT_WR);
    read(client_socket, buf, BUFF_SIZE);
    printf("message from client: %s\n", buf);

    fclose(fp);
    close(server_socket);
    close(client_socket);

    return 0;
}

