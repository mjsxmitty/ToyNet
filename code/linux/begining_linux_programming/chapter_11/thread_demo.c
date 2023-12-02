
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

void* thread_func(void *arg) {
    printf("thread func runing, param: %s\n", (char *)arg);
    sleep(3);
    strcpy(msg, "bye!");
    pthread_exit("thread exit");
}

void thread_demo() {
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

    return;
}

void* thread_func1(void *arg) {
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

void thread_demo1() {
    pthread_t thread_id;
    int res = 0;
    void *thread_result;

    res = pthread_create(&thread_id, NULL, thread_func1, (void *)msg);
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

    return;
}

sem_t bin_sem;

void* thread_func2(void *arg) {
    sem_wait(&bin_sem);
    while (strncmp("end", work_area, 3) != 0) {
        printf("you enter %ld charaters.\n", strlen(work_area) - 1);
        sem_wait(&bin_sem);
    }
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

    res = pthread_create(&thread_id, NULL, thread_func2, (void *)msg);
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
    res = pthread_join(thread_id, NULL);
    if (res != 0) {
        perror("pthread join");
        exit(-2);
    }
    printf("thread joined.\n");
    
    sem_destroy(&bin_sem);
    return;
}

void* thread_func3(void *arg) {
    sleep(1);
    pthread_mutex_lock(&work_mutex);
    while (strncmp("end", work_area, 3) != 0) {
        printf("you enter %ld charaters.\n", strlen(work_area) - 1);
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

void thread_demo3() {
    pthread_t thread_id;
    int res = 0;
    void *thread_result;
    
    res = pthread_mutex_init(&work_mutex, NULL);
    if (res != 0) {
        perror("inti mutex");
        exit(-1);
    }

    res = pthread_create(&thread_id, NULL, thread_func3, (void *)msg);
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
    return;
}

int thread_finished = 0;

void* thread_func4(void *arg) {
    printf("thread func is runing ... \n");
    sleep(3);
    printf("thread func is done.\n");
    thread_finished = 1;
    pthread_exit(NULL);
}


void thread_demo4() {
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

    res = pthread_create(&thread_id, NULL, thread_func4, (void *)msg);
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
    
    return;
}

void thread_demo5() {
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

    res = pthread_attr_setshedpolicy(&thread_attr, SCHED_OTHER);
    if (res != 0) {
        perror("pthread attr setshedpolicy");
        exit(-1);
    }

    max_priority = sched_get_priority_max(SCHED_OTHER);
    min_priority = sched_get_priority_min(SCHED_OTHER);
    scheduling_value.sched_priority = min_priority;

    res = pthread_attr_setshedparam(&thread_attr, &scheduling_value);
    if (res != 0) {
        perror("pthread attr setshedparam");
        exit(-1);
    }
    
    res = pthread_create(&thread_id, NULL, thread_func4, (void *)msg);
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
    
    return;
}

void* thread_func6(void *arg) {
    int res, i;
    res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    if (res != 0) {
        perror("pthread setcancelstate");
        exit(-1);
    }

    res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    if (res != 0) {
        perror("pthread setcanceltype");
        exit(-1);
    }

    for (i = 0; i < 10; ++i) {
        printf("thread is still runing (%d).\n", i);
        sleep(1);
    }

    pthread_exit("thread exit");
}


void thread_demo6() {
    pthread_t thread_id;
    int res = 0;
    void *thread_result;

    res = pthread_create(&thread_id, NULL, thread_func6, NULL);
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
    
    printf("thread joined, result: %s\n", (char *)thread_result);
    printf("msg: %s\n", msg);

    return;
}

void* thread_func7(void *arg) {
    int my_number = *(int *)arg;
    printf("thread func runing, num: %s\n", my_number);
    sleep(my_number);
    printf("bye, num: %s\n", my_number);
    pthread_exit(NULL);
}

#define THREAD_CNT  10

void thread_demo7() {
    pthread_t thread_ids[THREAD_CNT];
    int res = 0;
    int index = 0;

    for (index = 0; index < THREAD_CNT; ++index) {
        res = pthread_create(&(thread_id[index]), NULL, thread_func7, (void *)(&index));
        if (res != 0) {
            perror("pthread create");
            exit(-1);
        }
        sleep(1);
    }

    printf("waiting for thread exit ...\n");
    for (index = THREAD_CNT - 1; index >= 0; --index) {
        res = pthread_join(thread_id[index], &thread_result);
        if (res != 0) {
            perror("pthread join");
            exit(-2);
        }
        printf("thread joined, result: %s\n", (char *)thread_result);
    }

    printf("all done.\n");
    return;
}

