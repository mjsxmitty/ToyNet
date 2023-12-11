
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

    FILE    *read_fp;
    FILE    *write_fp;

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

    read_fp = fdopen(sock, "r");
    write_fp = fdopen(sock, "w");

    while (1) {
        fputs("input a series of number(q to quit): ", stdout);
        fgets(message, BUFF_SIZE, stdin);

        if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
            break;

        fputs(message, write_fp);
        fflush(write_fp);

        fgets(message, BUFF_SIZE, read_fp);        
        printf("message form server: %s\n", message);
    }

    fclose(read_fp);
    fclose(write_fp);
    return 0;
}


