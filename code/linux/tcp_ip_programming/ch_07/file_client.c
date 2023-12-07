
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
    int                 sock;
    struct sockaddr_in  serv_addr;
    socklen_t           clnt_addr_size;
    
    char    buf    [64];
    int     read_cnt = 0;
    FILE    *fp;

    if (argc != 4) {
        fprintf(stderr, "usage: ./file_client ip port file");
        exit(-1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(-1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        exit(-1);
    }

    fp = fopen(argv[3], "wb");
    if (fp == NULL) {
        perror("fopen");
        exit(-1);
    }

    while ((read_cnt = read(sock, buf, BUFF_SIZE)) != 0) {
        fwrite((void *)buf, 1, read_cnt, fp);
    }

    puts("received data ...\n");
    write(sock, "Thank you", 10);

    fclose(fp);
    close(sock);
    return 0;
}


