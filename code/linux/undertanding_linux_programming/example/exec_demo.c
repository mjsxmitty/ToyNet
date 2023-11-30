
#include "exec_demo.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void exec_demo() {

    char *arg_list[3];

    arg_list[0] = "ls";
    arg_list[1] = "-l";
    arg_list[2] = 0;

    printf("***********do ls*****************\n");
    execvp("ls", arg_list);         // 查找默认环境
    printf("***********ls done***************\n");
}

int execute(char *arg_list[]) {
    execvp(arg_list[0], arg_list);  // 成功不返回
    perror("execvp failed");
    exit(-1);
}

char* make_string(char *buf) {
    char *cp;

    buf[strlen(buf) - 1] = '\0';    // 有换行
    cp = malloc(strlen(buf) + 1);
    if (cp == NULL) {
        fprintf(stderr, "no memory!\n");
        exit(-2);
    }

    strcpy(cp, buf);
    return cp;
}

#define MAX_ARGS    20
#define ARG_LEN     100

void psh_demo() {

    char    *arg_list[MAX_ARGS + 1];
    char    arg_buf[ARG_LEN];
    int     num_args = 0;

    while (num_args < MAX_ARGS) {
        printf("arg[%d]: ", num_args);
        if (fgets(arg_buf, ARG_LEN, stdin) != NULL && *arg_buf != '\n') {
            arg_list[num_args++] = make_string(arg_buf);
        } else {
            if (num_args > 0) {
                arg_list[num_args] = NULL;
                execute(arg_list);
                num_args = 0;
            }
        }
    }
}

void fork_demo() {
    int ret_from_fork, my_pid;

    my_pid = getpid();
    printf("before, my pid is: %d\n", my_pid);

    // 父进程f返回子进程id;子进程返回0；出错返回-1
    ret_from_fork = fork();     
    sleep(1);

    printf("after, my pid is: %d, frok() said: %d\n\n", getpid(), ret_from_fork);
}


void child_code(int delay) {
    printf("child %d here, will sleep for %d seconds.\n", getpid(), delay);
    sleep(delay);
    printf("child done, about to exit.\n");
    exit(10);
}

void parent_code(int child_pid) {
    int wait_rv;
    int child_status;
    int high_8, low_7, bit_8;
    
    wait_rv = wait(&child_status);   // wait 返回子进程pid
    printf("done waitind for child %d, wait ret: %d.\n", child_pid, wait_rv);

    high_8 = child_status >> 8;
    low_7 = child_status & 0x7F;
    bit_8 = child_status & 0x80;
    printf("status: exit = %d, sig = %d, core = %d.\n", high_8, low_7, bit_8);
}

void wait_demo() {
    int new_pid;

    printf("before, my pid is: %d\n", my_pid);
    if ((new_pid = fork()) == -1) {
        perror("fork()");
    } else if (new_pid == 0){
        child_code(5);
    } else {
        parent_code(new_pid);
    }
}
