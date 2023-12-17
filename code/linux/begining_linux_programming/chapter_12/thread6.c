
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
    int max_priority;
    int min_priority;
    struct sched_param scheduling_value;
    
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

    res = pthread_attr_setschedpolicy(&thread_attr, SCHED_OTHER);   // 分时调度
    if (res != 0) {
        perror("pthread attr set policy");
        exit(-1);
    }

    max_priority = sched_get_priority_max(SCHED_OTHER);
    min_priority = sched_get_priority_min(SCHED_OTHER);
    scheduling_value.sched_priority = min_priority;

    res = pthread_attr_setschedparam(&thread_attr, &scheduling_value);  // 优先级
    if (res != 0) {
        perror("pthread attr set param");
        exit(-1);
    }
    
    res = pthread_create(&thread_id, NULL, thread_func, NULL);
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
