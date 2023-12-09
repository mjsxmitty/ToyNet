
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
    int                 server_socket;
    int                 client_socket;
    struct sockaddr_in  server_addr;
    struct sockaddr_in  client_addr;
    socklen_t           client_addr_size;    

    int     i = 0, str_len;
    char    msg[BUFF_SIZE];

    fd_set  reads, cpy_reads;
    struct timeval time_out;

    int fd_max, fd_num;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(-1);
    }

    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(-1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(-1);
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(-1);
    }

    FD_ZERO(&reads);
    FD_SET(server_socket, &reads);
    fd_max = server_socket;

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
                if (i == server_socket){
                    client_addr_size = sizeof(client_addr);
                    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
                    if (client_socket == -1) {
                        perror("accept");
                        continue;
                    }
                    
                    FD_SET(client_socket, &reads);
                    if (fd_max < client_socket)
                        fd_max = client_socket;
                    
                    printf("connect client: %d\n", client_socket);                
                } else {
                    str_len = read(i, msg, BUFF_SIZE);
                    if (str_len == 0) {
                        FD_CLR(i, &reads);
                        close(i);
                        printf("close client: %d\n", client_socket);  
                    } else {
                        write(i, msg, str_len);
                    }
                }

            }
        }
    }

    close(server_socket);
    return 0;
}

