
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
    long int msg_to_type = 0;

    msg_id = msgget((key_t)1234, 0666|IPC_CREAT);
    if (msg_id == -1) {
        perror("msgget");
        exit(-1);
    }

    while (running) {
        if (msgrcv(msg_id, (void *)&some_data, BUFF_SIZE, msg_to_type, 0) == -1) {
            perror("msgrcv");
            exit(-1);
        }

        printf("recv: %s\n", some_data.data);
        if (strncmp(some_data.data, "end", 3) == 0) {
            running = 0;
        }
    }
    
    return 0;
}