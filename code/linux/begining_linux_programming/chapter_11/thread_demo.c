
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

#include "thread_demo.h"

char msg[] = "hello world";
int run_now = 1;

#define WORK_SIZE 1024
char work_area[WORK_SIZE];

pthread_mutex_t work_mutex;
int time_to_exit;

void thread_demo() {
    pthread_t thread_id;
    int res = 0;
    void *thread_result;

    res = pthread_create(&thread_id, NULL, thread_func, (void *)msg);
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
    //res = pthread_join(thread_id, &thread_result);
    res = pthread_join(thread_id, NULL);
    if (res != 0) {
        perror("pthread join");
        exit(-2);
    }
    printf("thread joined.\n");
    
    //printf("thread joined, result: %s\n", (char *)thread_result);
    //printf("msg: %s\n", msg);

    return;
}

sem_t bin_sem;

void* thread_func(void *arg) {
#if 0
    printf("thread func runing, param: %s\n", (char *)arg);
    sleep(3);
    strcpy(msg, "bye!");
    pthread_exit("thread exit");
#endif
#if 0
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
#endif
#if 0
    sem_wait(&bin_sem);
    while (strncmp("end", work_area, 3) != 0) {
        printf("you enter %d charaters.\n", strlen(work_area) - 1);
        sem_wait(&bin_sem);
    }
    pthread_exit(NULL);
#endif
    sleep(1);
    pthread_mutex_lock(&work_mutex);
    while (strncmp("end", work_area, 3) != 0) {
        printf("you enter %d charaters.\n", strlen(work_area) - 1);
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

void thread_demo2() {
    pthread_t thread_id;
    int res = 0;
    void *thread_result;
    res = sem_init(&bin_sem, 0, 0);
    if (res != 0) {
        perror("sem init");
        exit(-1);
    }

    res = pthread_create(&thread_id, NULL, thread_func, (void *)msg);
    if (res != 0) {
        perror("pthread create");
        exit(-1);
    }

    printf("enter s series of number, 'end' to quit.\n");
    while (strncmp("end", work_area, 3) != 0) {
        if (strncmp("FAST", work_area, 4) == 0) {
            //sem_post(&bin_sem);
            strcpy(work_area, "Wheeee....");
        } else {
            fgets(work_area, WORK_SIZE, stdin);
        }
        sem_post(&bin_sem);
    }

    
    printf("waiting for thread exit ...\n");
    //res = pthread_join(thread_id, &thread_result);
    res = pthread_join(thread_id, NULL);
    if (res != 0) {
        perror("pthread join");
        exit(-2);
    }
    printf("thread joined.\n");
    
    //printf("thread joined, result: %s\n", (char *)thread_result);
    //printf("msg: %s\n", msg);
    sem_destory(&bin_sem);
    return;

}

void thread_demo3() {
    pthread_t thread_id;
    int res = 0;
    void *thread_result;
    
    res = pthread_mutex_init(&work_mutex, NULL);
    if (res != 0) {
        perror("inti mutex");
        exit(-1);
    }

    res = pthread_create(&thread_id, NULL, thread_func, (void *)msg);
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
    
    pthread_mutex_destory(&work_mutex);
    return;

}

