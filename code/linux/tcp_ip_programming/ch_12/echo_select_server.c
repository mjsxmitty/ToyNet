
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define BUFF_SIZE   512

int main(int argc, char **argv) 
{
    int serv_sock;
    int clnt_sock;

    struct sockaddr_in  serv_addr;
    struct sockaddr_in  clnt_addr;

    socklen_t clnt_addr_size;    

    int i = 0, str_len;
    char msg[BUFF_SIZE];

    fd_set  reads, cpy_reads;
    struct timeval time_out;

    int fd_max, fd_num;

    if (argc != 2) {
        fprintf(stderr, "param error.");
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

    FD_ZERO(&reads);
    FD_SET(serv_sock, &reads);
    fd_max = serv_sock;

    while (1) {
        cpy_reads = reads;
        time_out.tv_sec = 5;
        time_out.tv_usec = 5000;

        if ((fd_num = select(fd_max + 1, &cpy_reads, 0, 0, &time_out)) == -1) {
            perror("select");
            break;
        }

        if (fd_num == 0) {
            puts("fd not exchange ...");
            continue;
        }

        for (i = 0; i < fd_max + 1; ++i) {
            if (FD_ISSET(i, &cpy_reads)) {
                clnt_addr_size = sizeof(clnt_addr);
                clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
                if (clnt_sock == -1) {
                    perror("accept");
                    continue;
                }
                
                FD_SET(clnt_sock, &reads);
                if (fd_max < clnt_sock)
                    fd_max = clnt_sock;
                
                printf("connect client: %d\n", clnt_sock);                
            } else {
                str_len = read(i, msg, BUFF_SIZE);
                if (str_len == 0) {
                    FD_CLR(i, &reads);
                    close(i);
                    printf("close client: %d\n", clnt_sock);  
                } else {
                    write(i, msg, str_len);
                }
            }
        }
    }

    close(serv_sock);
    return 0;
}

