
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024
#define OPERAND_SIZE 4

int main(int argc, char **argv) 
{
    int                 sock;
    struct sockaddr_in  server_addr;
    
    char    option_msg[BUFF_SIZE];
    int     i, operand_cnt, result;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <ip> <port>.\n", argv[0]);
        exit(-1);
    }

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

    fputs("operand: ", stdout);
    scanf("%d", &operand_cnt);
    option_msg[0] = (char)operand_cnt;
    fgetc(stdin);

    for (i = 0; i < operand_cnt; ++i) {
        printf("operand %d: ", i + 1);
        scanf("%d", (int *)&option_msg[i*OPERAND_SIZE + 1]);
    }
    fgetc(stdin);   // 刷新缓冲区
    
    fputs("operator: ", stdout);
    scanf("%c", &option_msg[operand_cnt * OPERAND_SIZE + 1]);

    write(sock, option_msg, operand_cnt * OPERAND_SIZE + 2);
    read(sock, &result, 4);

    printf("operation result: %d\n", result);
    
    close(sock);
    return 0;
}


