
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
    int serv_sock;

    struct sockaddr_in  serv_addr;
    struct sockaddr_in  clnt_addr;

    socklen_t clnt_addr_size;    

    int str_len;
    char msg[BUFF_SIZE];

    if (argc != 2) {
        fprintf(stderr, "param error.");
        exit(-1);
    }

    serv_sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (serv_sock == -1) {
        perror("socket");
        exit(-1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind");
        exit(-1);
    }

    while (1) {
        clnt_addr_size = sizeof(clnt_addr);
        str_len = recvfrom(serv_sock, msg, BUFF_SIZE, 0, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
        sendto(serv_sock, msg, str_len, 0, (struct sockaddr *)&clnt_addr, clnt_addr_size);
    }

    close(serv_sock);
    return 0;
}

