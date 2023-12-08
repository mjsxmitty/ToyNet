
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFF_SIZE   512
#define CLNT_NUM    5

int main(int argc, char **argv) 
{
    int                 server_sock;
    struct sockaddr_in  server_addr;
    struct sockaddr_in  client_addr;
    socklen_t           client_addr_size;    

    int     str_len;
    char    msg[BUFF_SIZE];

    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(-1);
    }

    server_sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (server_sock == -1) {
        perror("socket");
        exit(-1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(-1);
    }

    while (1) {
        client_addr_size = sizeof(client_addr);
        str_len = recvfrom(server_sock, msg, BUFF_SIZE, 0, (struct sockaddr *)&client_addr, &client_addr_size);
        sendto(server_sock, msg, str_len, 0, (struct sockaddr *)&client_addr, client_addr_size);
    }

    close(server_sock);
    return 0;
}

