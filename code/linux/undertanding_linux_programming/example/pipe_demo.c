
#include "pipe_demo.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_SIZE   512

void pipe_demo1() {

    int i, len, apipe[2];
    char buf[BUFF_SIZE];

    if (pipe(apipe) == -1) {
        perror("pipe");
        return ;
    }
    printf("create pipe succeed, file sescription: { %d, %d }\n", apipe[0], apipe[1]);

    while (fgets(buf, BUFF_SIZE, stdin)) {
        len = strlen(buf);

        if (write(apipe[1], buf, len) != len) {
            perror("write");
            break ;
        }

        for (i = 0; i < len; ++i) {
            buf[i] = 'x';
        }

        len = read(apipe[0], buf, len);
        if (len == -1) {
            perror("read");
            break ;
        }

        if (write(1, buf, len) != len) {
            perror("write");
            break;
        }
    }
}

#define CHILD_CACHE     "i'm child!"
#define PARENT_CACHE    "i'm parent!"

void pipe_demo2() {
    int pipe_arr[2];
    int len;
    char buf[BUFF_SIZE];

    if (pipe(pipe_arr) == -1) {
        perror("pipe");
        return ;
    }

    switch(fork()) {
        case -1:
            perror("fork");
            exit(-1);
        case 0:
            len = strlen(CHILD_CACHE);
            while (1) {
                if (write(pipe_arr[1], CHILD_CACHE, len) != len) {
                    perror("child write");
                    exit(-2);
                }
            }
            sleep(2);
        default:
            len = read(pipe_arr[0], buf, BUFF_SIZE);
            if(len < 0) {
                perror("parent read");
                exit(-3);
            }
            sleep(3);

            if (write(1, buf, len) != len) {
                perror("parent write");
                exit(-4);
            }
    }
}

void pipe_demo3(int argc, char **argv) {
    int pipe_arr[2];

    if (argc != 3) {
        fprintf(stderr, "param error\n");
        exit(-1);
    }

    if (pipe(pipe_arr) == -1) {
        perror("pipe");
        return ;
    }

    switch(fork()) {
        case -1:
            perror("fork");
            exit(-1);
        case 0:
            // 子进程写
            close(pipe_arr[0]);
            if (dup2(pipe_arr[1], 1) == -1) {
                perror("child dup");
                exit(-2);
            }
            close(pipe_arr[1]);

            execlp(argv[1], argv[1], NULL);
            perror("child execlp");
            exit(-3);
        default:
            // 父进程读
            close(pipe_arr[1]);
            if (dup2(pipe_arr[0], 0) == -1) {
                perror("child dup");
                exit(-4);
            }
            close(pipe_arr[0]);

            execlp(argv[2], argv[2], NULL);
            perror("parent execlp");
            exit(-5);
    }
}