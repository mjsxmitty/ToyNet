
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char **argv) 
{
    int serv_sock;
    int clnt_sock;

    struct sockaddr_in  serv_addr;
    struct sockaddr_in  clnt_addr;

    socklen_t clnt_addr_size;
    
    char msg[] = "Hello World.";

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

    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
    if (clnt_sock == -1) {
        perror("accept");
        exit(-1);
    }

    write(clnt_sock, msg, strlen(msg));
    close(serv_sock);
    close(clnt_sock);

    return 0;
}

