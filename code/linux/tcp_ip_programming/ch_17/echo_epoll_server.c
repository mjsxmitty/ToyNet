
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <sys/socket.h>

#define BUFF_SIZE   4
#define EPOLL_SIZE  50

void set_noblock_mode(int fd) {
    int flag = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flag | O_NOBLOCK);
}

int main(int argc, char **argv) 
{
    int                 server_socket;
    int                 client_socket;
    struct sockaddr_in  server_addr;
    struct sockaddr_in  client_addr;
    socklen_t           client_addr_size;    

    int     i = 0, str_len;
    char    msg[BUFF_SIZE];

    struct epoll_event  *ep_events;
    struct epoll_event  event;
    int                 epfd, event_cnt;

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

    set_noblock_mode(server_socket);

    epfd = epoll_create(EPOLL_SIZE);
    ep_events = malloc(sizeof(struct epoll_event) * EPOLL_SIZE);

    event.events = EPOLLIN;
    event.data.fd = server_socket;
    epoll_ctl(epfd, EPOLL_CTL_ADD, server_socket, &event);

    while (1) {
        event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);
        if (event_cnt == -1) {
            perror("epoll");
            break;
        }

        puts("epoll wait ...\n");
        for (i = 0; i < event_cnt; ++i) {
            if (ep_events[i].data.fd == server_socket) {
                client_addr_size = sizeof(client_addr);
                client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
                if (client_socket == -1) {
                    perror("accept");
                    continue;
                }

                set_noblock_mode(client_socket);
                event.events = EPOLLIN | EPOLLET;
                event.data.fd = client_socket;
                epoll_ctl(epfd, EPOLL_CTL_ADD, client_socket, &event);
                
                printf("connect client: %d\n", client_socket);                
            } else {
                while (1) {
                    str_len = read(ep_events[i].data.fd , msg, BUFF_SIZE);
                    if (str_len == 0) {
                        epoll_ctl(epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
                        close(ep_events[i].data.fd);
                        printf("close client: %d\n", client_socket);  
                    } else if (str_len < 0) {
                        if (errno == EAGAIN)
                            break;  // 缓冲区为空
                    } else {
                        write(ep_events[i].data.fd, msg, str_len);
                    }
                }
            }
        }
    }

    close(server_socket);
    return 0;
}

