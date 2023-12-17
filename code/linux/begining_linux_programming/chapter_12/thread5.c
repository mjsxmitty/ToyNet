
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

int thread_finished = 0;

void* thread_func(void *arg) {
    printf("thread func is running ... \n");
    sleep(3);
    printf("thread func is done.\n");
    thread_finished = 1;
    pthread_exit(NULL);
}

int main(int argc, char **argv) 
{
    pthread_t thread_id;
    int res = 0;
    pthread_attr_t thread_attr;
    
    res = pthread_attr_init(&thread_attr);
    if (res != 0) {
        perror("pthread attr");
        exit(-1);
    }

    res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
    if (res != 0) {
        perror("pthread attr setdetachstate");
        exit(-1);
    }

    res = pthread_create(&thread_id, &thread_attr, thread_func, NULL);
    if (res != 0) {
        perror("pthread create");
        exit(-1);
    }
    pthread_attr_destroy(&thread_attr);
    
    while (!thread_finished) {
        printf("waiting for thread finished.\n");
        sleep(1);
    }
    printf("main thread finished.\n");
    
    return 0;
}
