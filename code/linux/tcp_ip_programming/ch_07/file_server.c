
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFF_SIZE 128

int main(int argc, char **argv) 
{
    int                 serv_sock, clnt_sock;
    struct sockaddr_in  serv_addr, clnt_addr;
    socklen_t           clnt_addr_size;

    char                buf[BUFF_SIZE];
    FILE                *fp;
    int                 read_cnt;
    
    if (argc != 3) {
        fprintf(stderr, "usage: ./file_server port file.\n");
        exit(-1);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
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

    if (listen(serv_sock, 5) == -1) {
        perror("listen");
        exit(-1);
    }

    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
    if (clnt_sock == -1) {
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
            write(clnt_sock, buf, read_cnt);
            break;
        }
        write(clnt_sock, buf, BUFF_SIZE);
    }

    shutdown(clnt_sock, SHUT_WR);
    read(clnt_sock, buf, BUFF_SIZE);
    printf("message from client: %s\n", buf);

    fclose(fp);
    close(serv_sock);
    close(clnt_sock);

    return 0;
}

