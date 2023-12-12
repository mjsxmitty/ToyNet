
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE   1024
#define NAME_SIZE   20

char name[NAME_SIZE];
char msg[BUFF_SIZE];

void* send_msg(void *arg)
{
    int sock = *((int *)arg);
    char send_msg[NAME_SIZE + BUFF_SIZE];

    while (1) {
        fgets(msg, BUFF_SIZE, stdin);
        if (!strcmp(msg, "q\n") || !strcmp(msg, "Q\n")) {
            close(sock);
            break;
        }
            
        sprintf(send_msg, "%s %s", name, msg);
        write(sock, send_msg, strlen(send_msg));
    }

    return NULL;
}

void* recv_msg(void *arg)
{
    int sock = *((int *)arg);
    char recv_msg[NAME_SIZE + BUFF_SIZE];
    int str_len;

    while (1) {
        str_len = read(sock, recv_msg, NAME_SIZE + BUFF_SIZE + 1);
        if (str_len == -1)
            return (void *)-1;

        recv_msg[str_len] = 0;
        fputs(recv_msg, stdout);
    }

    return NULL;
}


int main(int argc, char **argv)
{
    int                 sock;
    struct sockaddr_in  server_addr;

    pthread_t   send_thread, recv_thread;
    void        *thread_return;
    
    if (argc != 4) {
        fprintf(stderr, "usage: %s <ip> <port> <name>.\n", argv[0]);
        exit(-1);
    }

    sprintf(name, "[%s]:", argv[3]);
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

    pthread_create(&send_thread, NULL, send_msg, (void *)&sock);
    pthread_create(&recv_thread, NULL, recv_msg, (void *)&sock);
    pthread_join(send_thread, &thread_return);
    pthread_join(recv_thread, &thread_return);

    close(sock);
    return 0;
}
