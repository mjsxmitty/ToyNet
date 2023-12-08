
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv) 
{
    int                 sock;
    struct sockaddr_in  server_addr;
    
    char    message[BUFF_SIZE];
    int     str_len = 0, recv_len = 0, recv_cnt = 0;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <ip> <port>.\n", argv[0]);
        exit(-1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(-1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(-1);
    }
    printf("connected ...\n");

    while (1) {
        fputs("input a series of number(q to quit): ", stdout);
        fgets(message, BUFF_SIZE, stdin);

        if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
            break;

        str_len = write(sock, message, BUFF_SIZE);
        if (str_len == -1) {
            perror("write");
            break;
        }

        /*防止write字符串过大,导致接受不到全部的问题*/
        while (recv_len < str_len) {
            recv_cnt = read(sock, message, BUFF_SIZE - 1);
            if (recv_cnt == -1) {
                perror("read");
                break;
            }

            recv_len += recv_cnt;
        }
        
        message[recv_len] = '\0';
        printf("message form server: %s\n", message);
    }

    close(sock);
    return 0;
}


