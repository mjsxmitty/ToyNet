
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFF_SIZE 512

void read_routine(int sock, char *buf) {
    while (1) {
        int str_len = read(sock, buf, BUFF_SIZE);
        if (str_len == 0) {
            return ;
        }

        buf[str_len] = 0;
        printf("msg form server: %s\n", buf);
    }
}

void write_routine(int sock, char *buf) {
    
    while (1) {
        fgets(buf, BUFF_SIZE, stdin);
        if (!strcmp(buf, "q\n") || !strcmp(buf, "Q\n")) {
            shutdown(sock, SHUT_WR);
            return ;
        }
        write(sock, buf, BUFF_SIZE);
    }
}

/*分割IO*/
int main(int argc, char **argv) 
{
    int sock;

    struct sockaddr_in  serv_addr;
    socklen_t clnt_addr_size;

    char buf[BUFF_SIZE];
    pid_t pid;

    if (argc != 3) {
        fprintf(stderr, "param error.");
        exit(-1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(-1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        exit(-1);
    }
    printf("connected ...\n");

    pid = fork();
    if (pid == -1) {
        close(sock);
        perror("frok");
        exit(-1);
    }

    if (pid == 0) {
        write_routine(sock, buf);
    } else {
        read_routine(sock, buf);
    }

    close(sock);
    return 0;
}


