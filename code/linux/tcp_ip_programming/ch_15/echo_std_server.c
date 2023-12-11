
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFF_SIZE   1024
#define CLNT_NUM    5

int main(int argc, char **argv) 
{
    int                 server_sock;
    int                 client_sock;
    struct sockaddr_in  server_addr;
    struct sockaddr_in  client_addr;
    socklen_t           client_addr_size;    

    int     i = 0, str_len;
    char    message[BUFF_SIZE];

    FILE    *read_fp;
    FILE    *write_fp;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(-1);
    }

    server_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("socket");
        exit(-1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(-1);
    }

    if (listen(server_sock, 5) == -1) {
        perror("listen");
        exit(-1);
    }

    client_addr_size = sizeof(client_addr);
    for (i = 0; i < CLNT_NUM; ++i) {        
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_sock == -1) {
            perror("accept");
            break;
        }
        printf("connect client: %d\n", i);
        
        read_fp = fdopen(client_sock, "r");
        write_fp = fdopen(client_sock, "w");

        while (!feof(read_fp)) {
            fgets(message, BUFF_SIZE, read_fp);
            fputs(message, write_fp);
            fflush(write_fp);
        }
        
        fclose(read_fp);
        fclose(write_fp);
    }
    close(server_sock);

    return 0;
}

