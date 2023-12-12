
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
#include <pthread.h>

#define BUFF_SIZE   1024
#define MAX_CLIENTS 256

int client_cnt;
int client_sockets[MAX_CLIENTS];
pthread_mutex_t mutex;

void send_msg(char *msg, int len)
{
    int i;
    pthread_mutex_lock(&mutex);
    for (i = 0; i < client_cnt; ++i)        // 发送给所有客户端
        write(client_sockets[i], msg, len);
    pthread_mutex_unlock(&mutex);
}

void handle_client(void *arg)
{
    int client_socket = *((int *)arg);
    char buf[BUFF_SIZE];
    int str_len, i;

    while ((str_len = read(client_socket, buf, sizeof(buf))) != 0)
        send_msg(buf, str_len);

    // 移除
    pthread_mutex_lock(&mutex);
    for (i = 0; i < client_cnt; ++i) {
        if (client_socket == client_sockets[i]) {
            while (i < client_cnt - 1) {
                client_sockets[i] = client_sockets[i+1];
                i++;
            }
            break;
        }
    }

    client_cnt--;
    pthread_mutex_unlock(&mutex);
    close(client_socket);

}

int main(int argc, char **argv)
{
    int                 server_socket, client_socket;
    struct sockaddr_in  server_addr, client_addr;
    socklen_t           client_addr_size;

    pthread_t   pid;
    int res = 0;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(-1);
    }

    pthread_mutex_init(&mutex, NULL);

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

    while (1) {
        client_addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            perror("accept");
            break;
        }

        pthread_mutex_lock(&mutex);
        client_sockets[client_cnt++] = client_socket;
        pthread_mutex_unlock(&mutex);

        pthread_create(&pid, NULL, handle_client, (void *)&client_socket);
        pthread_detach(pid);
        printf("connect client: %s\n", inet_ntoa(client_addr.sin_addr));
    }

    close(server_socket);
    return 0;
}
