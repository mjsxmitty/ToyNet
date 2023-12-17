
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

void* thread_func(void *arg) {
    int res, i;
    res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    if (res != 0) {
        perror("pthread setcancelstate");
        exit(-1);
    }

    // PTHREAD_CANCEL_DEFERRED
    res = pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    if (res != 0) {
        perror("pthread setcanceltype");
        exit(-1);
    }

    for (i = 0; i < 10; ++i) {
        printf("thread is still running (%d).\n", i);
        sleep(1);
    }

    pthread_exit("thread exit");
}


int main(int argc, char **argv) 
{
    pthread_t thread_id;
    int res = 0;
    void *thread_result;

    res = pthread_create(&thread_id, NULL, thread_func, NULL);
    if (res != 0) {
        perror("pthread create");
        exit(-1);
    }

    sleep(3);
    printf("canceling thread ... \n");
    res = pthread_cancel(thread_id);
    if (res != 0) {
        perror("pthread cancel");
        exit(-1);
    }

    printf("waiting for thread exit ...\n");
    res = pthread_join(thread_id, &thread_result);
    if (res != 0) {
        perror("pthread join");
        exit(-2);
    }
    
    return 0;
}

