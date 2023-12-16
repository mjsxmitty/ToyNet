
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

#define WORK_SIZE 1024
char work_area[WORK_SIZE];
sem_t bin_sem;

void* thread_func(void *arg) {
    sem_wait(&bin_sem);
    while (strncmp("end", work_area, 3) != 0) {
        printf("you enter %ld characters.\n", strlen(work_area) - 1);
        sem_wait(&bin_sem);
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    pthread_t thread_id;
    int res = 0;

    res = sem_init(&bin_sem, 0, 0);
    if (res != 0) {
        perror("sem init");
        exit(-1);
    }

    res = pthread_create(&thread_id, NULL, thread_func, NULL);
    if (res != 0) {
        perror("pthread create");
        exit(-1);
    }

    printf("enter s series of number, 'end' to quit.\n");
    while (strncmp("end", work_area, 3) != 0) {
        if (strncmp("FAST", work_area, 4) == 0) {
            //sem_post(&bin_sem);
            strcpy(work_area, "fast....");
        } else {
            fgets(work_area, WORK_SIZE, stdin);
        }
        sem_post(&bin_sem);
    }

    printf("waiting for thread exit ...\n");
    res = pthread_join(thread_id, NULL);
    if (res != 0) {
        perror("pthread join");
        exit(-2);
    }
    printf("thread joined.\n");
    
    sem_destroy(&bin_sem);
    return 0;
}