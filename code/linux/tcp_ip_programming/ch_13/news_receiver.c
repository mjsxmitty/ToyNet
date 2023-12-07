
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFF_SIZE 512

int main(int argc, char **argv) 
{
    int                 recv_sock;
    struct sockaddr_in  addr;
    struct ip_mreq      join_addr;
    
    char    msg[BUFF_SIZE];
    int     str_len;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <groupip> <port>\n", argv[0]);
        exit(-1);
    }

    recv_sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (recv_sock == -1) {
        perror("socket");
        exit(-1);
    }

    join_addr.imr_multiaddr.s_addr = inet_addr(argv[1]);
    join_addr.imr_interface.s_addr = htonl(INADDR_ANY);

    setsockopt(recv_sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *)&join_addr, sizeof(join_addr));

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(atoi(argv[2]));

    if (bind(recv_sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(-1);
    }

    while (1) {
        str_len = recvfrom(recv_sock, msg, BUFF_SIZE - 1, 0, NULL, 0);
        if (str_len < 0)
            break;

        msg[str_len] = 0;
        fputs(msg, stdout);
    }

    close(recv_sock);
    return 0;
}



