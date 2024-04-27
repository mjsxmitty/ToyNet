
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <libgen.h>
#include <assert.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

static bool stop = false;

static void handle_term(int sig) {
    stop = true;
}

int main(int argc, char **argv)
{
    signal(SIGTERM, handle_term);
    
    if (argc < 3) {
        printf("usage: ./%s ipaddr port.\n", basename(argv[0]));
        return -1;
    }
    
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    assert(sock >= 0);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &address.sin_addr);
    address.sin_port = htons(atoi(argv[2]));

    int ret = bind(sock, (struct sockaddr *)&address, sizeof(address));
    assert(ret != -1);

    ret = listen(sock, 5);
    assert(ret != -1);

    sleep(10);

    struct sockaddr_in client_sock;
    socklen_t client_len = sizeof(client_sock);
    int conn_fd = accept(sock, (struct sockaddr *)&client_sock, &client_len);
    if (conn_fd < 0) {
        printf("error: %d\n", errno);
    } else {
        char remote[INET_ADDRSTRLEN];
        printf("connected with ip: %s and port %d.\n", 
                inet_ntop(AF_INET, &client_sock.sin_addr, remote, INET_ADDRSTRLEN),
                ntohs(client_sock.sin_port));
    }

    close(sock);
    return 0;
}
