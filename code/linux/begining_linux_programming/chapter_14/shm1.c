
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#include "shm_com.h"

int main(int argc, char *argv[])
{
    int shm_id;
    void *shared_memory;
    struct shared_data *pdata;
    int running = 1;

    srand((unsigned int) getpid());

    shm_id = shmget((key_t)1234, sizeof(struct shared_data), 0666|IPC_CREAT);
    if (shm_id == -1) {
        perror("shmget");
        exit(-1);
    }

    shared_memory = shmat(shm_id, (void *)0, 0);
    if (shared_memory == (void *)-1) {
        perror("shmat");
        exit(-1);
    }
    printf("recv memory attached at: %X\n", (int)shared_memory);

    pdata = (struct shared_data *)shared_memory;
    pdata->write_flag = 0;
    
    while (running) {
        if (pdata->write_flag) {
            printf("recv data: %s\n", pdata->data);
            sleep(rand() % 4);
            pdata->write_flag = 0;
            
            if (strncmp(pdata->data, "end", 3) == 0)
                running = 0;
        }
    }
    
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        exit(-1);
    }

    if (shmctl(shm_id, IPC_RMID, 0) == -1) {
        perror("shmctl");
        exit(-1);
    }
    return 0;
}