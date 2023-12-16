
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

char msg[] = "hello world";

void* thread_func(void *arg) {
    printf("thread func running, param: %s\n", (char *)arg);
    sleep(3);
    strcpy(msg, "bye!");
    pthread_exit("thread exit");
}

int main(int argc, char **argv) 
{
    pthread_t thread_id;
    int res = 0;
    void *thread_result;

    res = pthread_create(&thread_id, NULL, thread_func, (void *)msg);
    if (res != 0) {
        perror("pthread create");
        exit(-1);
    }

    printf("waiting for thread exit ...\n");
    res = pthread_join(thread_id, &thread_result);
    if (res != 0) {
        perror("pthread join");
        exit(-2);
    }
    
    printf("thread joined, result: %s\n", (char *)thread_result);
    printf("msg: %s\n", msg);

    return 0;
}