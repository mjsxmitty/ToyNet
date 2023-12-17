
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "semun.h"

static int sem_id;

static int set_sem_value()
{
    union semun sem_union;
    sem_union.val = 1;
    if (semctl(sem_id, 0, SETVAL, sem_union) == -1)
        return 0;

    return 1;
}

static void del_sem_value()
{
    union semun sem_union;
    if (semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
        fprintf(stderr, "failed to delete semaphore.\n");
}

static int semaphore_p()
{
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = -1;
    sem_b.sem_flg = SEM_UNDO;

    if (semop(sem_id, &sem_b, 1) == -1) {
        fprintf(stderr, "failed semaphore_p.\n");
        return 0;
    }

    return 1;
}

static int semaphore_v()
{
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = 1;
    sem_b.sem_flg = SEM_UNDO;

    if (semop(sem_id, &sem_b, 1) == -1) {
        fprintf(stderr, "failed semaphore_v.\n");
        return 0;
    }

    return 1;
}

int main(int argc, char *argv[])
{
    int i, pause_time;
    char op = 'X';

    srand((unsigned int) getpid());

    sem_id = semget((key_t)1234, 1, 0666 | IPC_CREAT);

    if (argc > 1) {
        if (!set_sem_value()) {
            fprintf(stderr, "failed to set sem value.\n");
            exit(-1);
        }

        op = 'O';
        sleep(2);
    }

    for (i = 0; i < 10; ++i) {
        if (!semaphore_p())
            exit(-1);

        printf("%c", op);
        fflush(stdout);
        pause_time = rand() % 3;
        sleep(pause_time);
        printf("%c", op);
        fflush(stdout);
        
        if (!semaphore_v())
            exit(-1);
        pause_time = rand() % 2;
        sleep(pause_time);
    }

    printf("\n%d - finished.\n", getpid());

    if (argc > 1) {
        sleep(10);
        del_sem_value();
    }
    return 0;
}