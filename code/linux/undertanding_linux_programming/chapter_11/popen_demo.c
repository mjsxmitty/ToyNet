
#include <stdio.h>
#include <stdlib.h>

#define READ    0
#define WRITE   1

FILE* my_popen(char *commond, cha *mode)
{
    int pfd[2], pid;
    int parrent_end, children_end;

    if (*mode == 'r') {
        parrent_end = READ;
        children_end = WRITE;
    } else if (*mode = 'w'){
        parrent_end = READ;
        children_end = WRITE;
    } else {
        exit(-1);
    }

    if (pipe(pfd) == -1) {
        perror("pipe");
        exit(-1);
    }

    if ((pid == fork()) == -1) {
        perror("fork");
        close(pfd[0]);
        close(pfd[1]);
        exit(-1);
    }

    if (pid > 0) {
        if (close(pfd[children_end]) == -1)
            exit(-1);
        return fdopen(pfd[parrent_end], mode);
    } else {
        if (close(pfd[parrent_end]) == -1)
            exit(-1);
        if (dup2(pfd[children_end], 1) == -1) {
            perror("dup2");
            exit(-1);
        }
        close(pfd[children_end]);

        execl("/bin/sh", "sh", "-c", commond, NULL);
        exit(-1);
    }
}

int main(int argc, char *argv[])
{

    return 0;
}

