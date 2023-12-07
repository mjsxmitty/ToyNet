
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
    int sock;

    struct sockaddr_in  serv_addr;
    
    char msg[BUFF_SIZE];
    int str_len = 0, recv_len = 0, recv_cnt = 0;

    if (argc != 3) {
        fprintf(stderr, "param error.");
        exit(-1);
    }

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(-1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    while (1) {
        fputs("input a series of number(q to quit): ", stdout);
        fgets(msg, BUFF_SIZE, stdin);

        if (!strcmp(msg, "q\n") || !strcmp(msg, "Q\n"))
            break;

        write(sock, msg, strlen(msg));
        str_len = read(sock, msg, sizeof(msg));
       
        msg[str_len] = '\0';
        printf("msg form server: %s\n", msg);
    }

    close(sock);
    return 0;
}


