
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define HOST_LEN    128
#define BLOCK_LOG   5

int make_server_socket_q(int port_num, int block_log)
{
    int 				sock;    
    struct sockaddr_in  addr;    

    struct hostent      *hp;
    char hostname[HOST_LEN];        

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return -1;
    }
    
    memset(&hostname, 0, sizeof(hostname));
    gethostname(hostname, HOST_LEN);
    hp = gethostbyname(hostname);
    if (hp == NULL) {
        perror("gethostbyname");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(port_num));
    memcpy(&addr.sin_addr, *(struct in_addr **)hp->h_addr_list, sizeof(struct in_addr));
    
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return -1;
    }

    if (listen(server_sock, block_log) == -1) {
        perror("listen");
        return -1;
    }

    return sock;
}


int make_server_socket(int port_num)
{
    return make_server_socket_q(port_num, BLOCK_LOG);
}

int connect_to_server(char *host, int port_num)
{
    int 				sock;    
    struct sockaddr_in  addr;    
    struct hostent      *hp;     

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return -1;
    }    

    hp = gethostbyname(host);
    if (hp == NULL) {
        perror("gethostbyname");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(port_num));
    memcpy(&addr.sin_addr, *(struct in_addr **)hp->h_addr_list, sizeof(struct in_addr));

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return -1;
    }

    return sock;
}

