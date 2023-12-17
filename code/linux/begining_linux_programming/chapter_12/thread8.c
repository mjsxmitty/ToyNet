
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

#define THREAD_CNT  10

void* thread_func(void *arg) {
    int my_number = *(int *)arg;
    printf("thread func running, num: %d\n", my_number);
    sleep(my_number);
    printf("bye, num: %d\n", my_number);
    pthread_exit(NULL);
}

int main(int argc, char **argv) 
{
    pthread_t thread_ids[THREAD_CNT];
    int res = 0;
    int index = 0;
    void *thread_result = NULL;

    for (index = 0; index < THREAD_CNT; ++index) {
        res = pthread_create(&(thread_ids[index]), NULL, thread_func, (void *)(&index));
        if (res != 0) {
            perror("pthread create");
            exit(-1);
        }
        sleep(1);
    }

    printf("waiting for thread exit ...\n");
    for (index = THREAD_CNT - 1; index >= 0; --index) {
        res = pthread_join(thread_ids[index], thread_result);
        if (res != 0) {
            perror("pthread join");
            exit(-2);
        }
        printf("thread joined, result: %s\n", (char *)thread_result);
    }

    printf("all done.\n");
    return 0;
}

