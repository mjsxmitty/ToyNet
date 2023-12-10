
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <signal.h>

#define BUFF_SIZE   512

void read_child_proc(int sig) {
    pid_t   pid;
    int     status;

    pid = waitpid(-1, &status, WNOHANG);    //不阻塞
    printf("remove proc id: %d\n", pid);
}

/*多进程*/
int main(int argc, char **argv) 
{
    int                 server_sock;
    int                 client_sock;
    struct sockaddr_in  server_addr;
    struct sockaddr_in  client_addr;
    socklen_t           client_addr_size;    

    int i = 0, str_len;

    char msg[BUFF_SIZE];

    pid_t pid;

    struct sigaction act;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(-1);
    }

    act.sa_handler = read_child_proc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGCHLD, &act, 0);

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

    while (1) {
        client_addr_size = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_sock == -1) {
            perror("accept");
            continue;
        }
        puts("connect new client...");

        pid = fork();
        if (pid == -1) {
            close(client_sock);
            perror("fork");
            continue;
        }

        if (pid == 0) {
            close(server_sock);
            while ((str_len = read(client_sock, msg, BUFF_SIZE)) != 0) {
                write(client_sock, msg, str_len);
            }
            
            close(client_sock);
            puts("client disconnected...");
            return 0;

        } else {
            close(client_sock);
        }
    }

    close(server_sock);
    return 0;
}

