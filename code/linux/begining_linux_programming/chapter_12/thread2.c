
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

int run_now = 1;

void* thread_func(void *arg) {
    int print_cnt = 0;
    while (print_cnt++ < 20) {
        if (run_now == 2) {
            printf("2");
            fflush(stdout);
            run_now = 1;
        } else {
            sleep(1);
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    pthread_t thread_id;
    int res = 0;

    res = pthread_create(&thread_id, NULL, thread_func, NULL);
    if (res != 0) {
        perror("pthread create");
        exit(-1);
    }

    int print_cnt = 0;
    while (print_cnt++ < 20) {
        if (run_now == 1) {
            printf("1");
            fflush(stdout);
            run_now = 2;
        } else {
            sleep(1);
        }
    }
    
    printf("waiting for thread exit ...\n");
    if (res != 0) {
        perror("pthread join");
        exit(-2);
    }
    printf("thread joined.\n");

    return 0;
}