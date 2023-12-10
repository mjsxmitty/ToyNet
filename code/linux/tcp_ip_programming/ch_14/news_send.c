
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFF_SIZE   512
#define TTL    5

int main(int argc, char **argv) 
{
    int                 send_sock;
    struct sockaddr_in  mul_addr;
    
    int     time_live = TTL;
    char    buf[BUFF_SIZE];
    FILE    *fp;

    int so_bro = 1;
    
    if (argc != 4) {
        fprintf(stderr, "usage: %s <ip> <port> <file>\n", argv[0]);
        exit(-1);
    }

    send_sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (send_sock == -1) {
        perror("socket");
        exit(-1);
    }

    //setsockopt(send_sock, IPPROTO_IP, IP_MULTICAST_TTL, (void *)&time_live, sizeof(time_live));
    setsockopt(send_sock, SOL_SOCKET, SO_BROADCAST, (void *)&so_bro, sizeof(so_bro));

    memset(&mul_addr, 0, sizeof(mul_addr));
    mul_addr.sin_family = AF_INET;
    mul_addr.sin_addr.s_addr = inet_addr(argv[1]);
    mul_addr.sin_port = htons(atoi(argv[2]));

    if ((fp = fopen(argv[3], "r+")) == NULL) {
        perror("fopen");
        exit(-1);
    }

    printf("send...\n");

    while (!feof(fp))
    {
        fgets(buf, BUFF_SIZE, fp);
        sendto(send_sock, buf, strlen(buf), 0, (struct sockaddr *)&mul_addr, sizeof(mul_addr));
        sleep(2);
    }
    

    fclose(fp);
    close(send_sock);
    
    return 0;
}


