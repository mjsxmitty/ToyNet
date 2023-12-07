
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <signal.h>

#define BUFF_SIZE   512
#define CLNT_NUM    5

void read_child_proc(int sig) {
    pid_t   pid;
    int     status;

    pid = waitpid(-1, &status, WNOHANG);
    printf("remove proc id: %d\n", pid);
}

/*多进程*/
int main(int argc, char **argv) 
{
    int serv_sock;
    int clnt_sock;

    struct sockaddr_in  serv_addr;
    struct sockaddr_in  clnt_addr;

    socklen_t clnt_addr_size;    

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

    while (1) {
        clnt_addr_size = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
        if (clnt_sock == -1) {
            perror("accept");
            continue;
        }
        puts("connect new client...");

        pid = fork();
        if (pid == -1) {
            close(clnt_sock);
            perror("frok");
            continue;
        }

        if (pid == 0) {
            close(serv_sock);
            while ((str_len = read(clnt_sock, msg, BUFF_SIZE)) != 0) {
                write(clnt_sock, msg, str_len);
            }
            
            close(clnt_sock);
            puts("client disconnected...");
            return 0;
        } else {
            close(clnt_sock);
        }
    }


    close(serv_sock);
    return 0;
}

