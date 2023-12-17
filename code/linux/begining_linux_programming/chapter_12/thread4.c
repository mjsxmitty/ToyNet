
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

pthread_mutex_t work_mutex;
int time_to_exit;

#define WORK_SIZE 1024
char work_area[WORK_SIZE];

void* thread_func(void *arg) {
    sleep(1);
    pthread_mutex_lock(&work_mutex);
    while (strncmp("end", work_area, 3) != 0) {
        printf("you enter %ld characters.\n", strlen(work_area) - 1);
        work_area[0] = '\0';
        pthread_mutex_unlock(&work_mutex);
        sleep(1);
        pthread_mutex_lock(&work_mutex);
        while (work_area[0] == '\0') {
            pthread_mutex_unlock(&work_mutex);
            sleep(1);
            pthread_mutex_lock(&work_mutex);
        }
    }

    time_to_exit = 1;
    work_area[0] = '\0';
    pthread_mutex_unlock(&work_mutex);
    pthread_exit(NULL);
}

int main(int argc, char **argv) 
{
    pthread_t thread_id;
    int res = 0;
    
    res = pthread_mutex_init(&work_mutex, NULL);
    if (res != 0) {
        perror("inti mutex");
        exit(-1);
    }

    res = pthread_create(&thread_id, NULL, thread_func, NULL);
    if (res != 0) {
        perror("pthread create");
        exit(-1);
    }
    
    pthread_mutex_lock(&work_mutex);
    printf("enter s series of number, 'end' to quit.\n");
    while (!time_to_exit) {
        fgets(work_area, WORK_SIZE, stdin);
        pthread_mutex_unlock(&work_mutex);

        while(1) {
            pthread_mutex_lock(&work_mutex);
            if (work_area[0] != '\0') {
                pthread_mutex_unlock(&work_mutex);
                sleep(1);
            } else {
                break;
            }
        }
    }
    pthread_mutex_unlock(&work_mutex);
    
    printf("waiting for thread exit ...\n");
    res = pthread_join(thread_id, NULL);
    if (res != 0) {
        perror("pthread join");
        exit(-2);
    }
    printf("thread joined.\n");
    
    pthread_mutex_destroy(&work_mutex);
    return 0;
}
