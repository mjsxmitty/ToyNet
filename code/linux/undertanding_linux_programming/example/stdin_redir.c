
#include "stdin_redir.h"
#include <stdio.h>
#include <unistd.h>

void stdin_redir() {
    int fd, mew_fd;
    char line[100];

    fgets(line, 100, stdin); printf("%s\n", line);
    fgets(line, 100, stdin); printf("%s\n", line);
    fgets(line, 100, stdin); printf("%s\n", line);

    fd = open("./Makefile", O_RDONLY);    
    if(fd < 0) {
        fprintf(stderr, "open file failed.\n");
        exit(-1);
    }
#if 0
    close(0);
    new_fd = dup(fd);
    if(new_fd != 0) {
        perror("dup");
        exit(-1);
    }
    close(fd);
#endif
    new_fd = dup2(fd, 0);

    fgets(line, 100, stdin); printf("%s\n", line);
    fgets(line, 100, stdin); printf("%s\n", line);
    fgets(line, 100, stdin); printf("%s\n", line);

}


