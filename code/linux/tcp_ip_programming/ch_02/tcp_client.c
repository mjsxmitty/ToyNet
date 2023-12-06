
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char **argv) 
{
    int sock;

    struct sockaddr_in  serv_addr;
    socklen_t clnt_addr_size;
    
    char msg[64];
    int str_len = 0;
    int idx = 0, read_len = 0;

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

    while ((read_len = read(sock, &msg[idx++], 1))) {
        if (read_len == -1) {
            perror("read");
            exit(-1);
        }

        str_len += read_len;
    }

    printf("msg form server: %s\n", msg);
    printf("read str cnt: %d\n", str_len);

    close(sock);
    return 0;
}


