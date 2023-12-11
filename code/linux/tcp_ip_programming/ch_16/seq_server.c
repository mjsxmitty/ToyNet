
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFF_SIZE   1024

int main(int argc, char **argv)
{
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;

    char buf[BUFF_SIZE] = {0,};

    FILE    *read_fp;
    FILE    *write_fp;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
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

    client_addr_size = sizeof(client_socket);
    if (accept(server_socket, (struct sockaddr *)&client_socket, &client_addr_size) == -1) {
        perror("accept");
        exit(-1);
    }

    read_fp = fdopen(client_socket, "r");
    write_fp = fdopen(dup(client_socket), "w");
    if (read_fp == NULL || write_fp == NULL) {
        perror("fdopen");
        exit(-1);
    }

    fputs("SERVER: hi~\n", write_fp);
    fflush(write_fp);

    fclose(write_fp);
    fgets(buf, BUFF_SIZE, read_fp);
    fputs(buf, write_fp);
    fclose(read_fp);

    return 0;
}