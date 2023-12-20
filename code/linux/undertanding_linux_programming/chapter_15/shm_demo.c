
#include <sys/shm.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

#define TIME_MEM_KEY    99
#define SEG_SIZE        ((size_t)100)

void shm_ts() {

    int seg_id;
    char *mem_ptr;
    int n;
    time_t now;

    seg_id = shmget(TIME_MEM_KEY, SEG_SIZE, IPC_CREAT | 0777);
    if (seg_id == -1) {
        perror("shmget");
        exit(-1);
    }

    mem_ptr = shmat(seg_id, NULL, 0);
    if (mem_ptr == (void *)-1) {
        perror("shmat");
        exit(-2);
    }

    for (n = 0; n < 60; ++n) {
        time(&now);
        strcpy(mem_ptr, ctime(&now));
        sleep(1);
    }

    shmctl(seg_id, IPC_RMID, NULL);
    wait(NULL);
}

void shm_tc() {
    int seg_id;
    char *mem_ptr;
    int n;
    time_t now;

    seg_id = shmget(TIME_MEM_KEY, SEG_SIZE, 0777);
    if (seg_id == -1) {
        perror("shmget");
        exit(-1);
    }

    mem_ptr = shmat(seg_id, NULL, 0);
    if (mem_ptr == (void *)-1) {
        perror("shmat");
        exit(-2);
    }

    for (n = 0; n < 20; ++n) {
        printf("the time, directory form memory: %s\n", mem_ptr);
        sleep(1):
    }
    
    shmdt(mem_ptr);
    exit(0);
}

void shm_demo() {
    int new_pid;

    if ((new_pid = fork()) == -1) {
        perror("fork()");
    } else if (new_pid == 0){
        shm_tc();
    } else {
        shm_ts();
    }
}

void shm_ts2() {

    int seg_id;
    char *mem_ptr;
    int n;
    time_t now;

    seg_id = shmget(TIME_MEM_KEY, SEG_SIZE, IPC_CREAT | 0777);
    if (seg_id == -1) {
        perror("shmget");
        exit(-1);
    }

    mem_ptr = shmat(seg_id, NULL, 0);
    if (mem_ptr == (void *)-1) {
        perror("shmat");
        exit(-2);
    }

    for (n = 0; n < 60; ++n) {
        time(&now);
        strcpy(mem_ptr, ctime(&now));
        sleep(1);
    }

    shmctl(seg_id, IPC_RMID, NULL);
    wait(NULL);
}

