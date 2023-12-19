
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ctype.h>

#define HOST_LEN    128
#define PORT        2000

void serialize_dirname(char *str)
{
    char *src, *dst;
    for (src = dst = str; *src; ++src) {
        if (*src == '/' || isalnum(src))
            *dst++ = *src;
    }
    *dst = '\0';
}

int main(int argc, char **argv) 
{
    int 				server_sock;
    int 				client_sock;
    struct sockaddr_in  server_addr;
    struct sockaddr_in  client_addr;
    socklen_t 			client_addr_size;

    struct hostent      *hp;
    char hostname[HOST_LEN];

    FILE    *fpi, *fpo, *pfp;
    char dirname[BUFSIZ];
    char commond[BUFSIZ];
    char c;
    
    if (argc != 1) {
        fprintf(stderr, "usage: ./%s\n", argv[0]);
        exit(-1);
    }

    server_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("socket");
        exit(-1);
    }
    
    memset(&hostname, 0, sizeof(hostname));
    gethostname(hostname, HOST_LEN);
    hp = gethostbyname(hostname);
    if (hp == NULL) {
        perror("gethostbyname");
        return -1;
    }

    //bcopy((void *)hp->h_addr, (void *)&server_addr.sin_addr, hp->h_length);

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(PORT));
    memcpy(&server_addr.sin_addr, *(struct in_addr **)hp->h_addr_list, sizeof(struct in_addr));
    
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
            exit(-1);
        }

        if ((fpi = fdopen(client_sock, "r")) == NULL) {
            perror("fdopen r");
            exit(-1);
        }

        if (fgets(dirname, BUFSIZ, fpi) == NULL) {
            perror("fgets");
            exit(-1);
        }

        //
        serialize_dirname(dirname);
        
        fprintf(commond, "ls %s", dirname);
        if ((pfp = popen(commond, "r")) == NULL) {
            perror("popen");
            exit(-1);
        }

        if ((fpo = fdopen(client_sock, "w")) == NULL) {
            perror("fdopen w");
            exit(-1);
        }

        while ((c = getc(pfp)) != EOF) {
            putc(c,fpo);
        }

        fclose(fpi);
        fclose(fpo);
        fclose(pfp);
        close(server_sock);
    }

    close(client_sock);

    return 0;
}


