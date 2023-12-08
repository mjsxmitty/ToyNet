
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
    struct sockaddr_in  server_addr;
    socklen_t           client_addr_size;
    
    char    buf    [64];
    int     read_cnt = 0;
    FILE    *fp;

    if (argc != 4) {
        fprintf(stderr, "usage: %s <ip> <port> %s\n", argv[0], argv[3]);
        exit(-1);
    }

    fp = fopen(argv[3], "w+");
    if (fp == NULL) {
        perror("fopen");
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
    
    while ((read_cnt = read(sock, buf, BUFF_SIZE)) != 0) {
        fwrite((void *)buf, 1, read_cnt, fp);   //???
    }

    puts("received data.\n");
    write(sock, "Thank you", 10);

    fclose(fp);
    close(sock);
    return 0;
}


