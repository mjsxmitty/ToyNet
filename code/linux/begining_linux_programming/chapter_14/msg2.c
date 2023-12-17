
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define     BUFF_SIZE 32

struct my_msg
{
    long int my_msg_type;
    char data[BUFF_SIZE];
};

int main(int argc, char *argv[])
{
    int running = 1;
    int msg_id;
    struct my_msg some_data;
    char buffer[BUFF_SIZE];

    msg_id = msgget((key_t)1234, 0666|IPC_CREAT);
    if (msg_id == -1) {
        perror("msgget");
        exit(-1);
    }

    while (running) {
        printf("enter some data: ");
        fgets(buffer, BUFF_SIZE, stdin);
        some_data.my_msg_type = 1;
        strcpy(some_data.data, buffer);

        if (msgsnd(msg_id, (void *)&some_data, BUFF_SIZE, 0) == -1) {
            perror("msgsnd");
            exit(-1);
        }

        if (strncmp(some_data.data, "end", 3) == 0) {
            running = 0;
        }
    }
    
    return 0;
}