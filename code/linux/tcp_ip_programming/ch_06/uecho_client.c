
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFF_SIZE 512

int main(int argc, char **argv) 
{
    int                 sock;
    struct sockaddr_in  server_addr, from_addr;
    socklen_t           addr_size;
    
    char    msg[BUFF_SIZE];
    int     str_len = 0;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <ip> <port>\n", argv[0]);
        exit(-1);
    }

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(-1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    while (1) {
        fputs("input a series of number(q to quit): ", stdout);
        fgets(msg, BUFF_SIZE, stdin);

        if (!strcmp(msg, "q\n") || !strcmp(msg, "Q\n"))
            break;

        sendto(sock, msg, strlen(msg), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

        addr_size = sizeof(from_addr);
        str_len = recvfrom(sock, msg, BUFF_SIZE, 0, (struct sockaddr *)&from_addr, &addr_size);
       
        msg[str_len] = '\0';
        printf("msg form server: %s\n", msg);
    }

    close(sock);
    return 0;
}


