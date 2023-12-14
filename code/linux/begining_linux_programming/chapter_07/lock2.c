
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

const char *lock_file = "./LOCK.text";

int main() 
{
    int file_desc;
    int tries = 5;

    while (tries--)
    {
        file_desc = open(lock_file, O_RDWR|O_CREAT|O_EXCL, 0444);
        if (file_desc == -1) {
            printf("%d - LOCK file already exist!\n", getpid());
            sleep(2);
        } else {
            printf("%d - lock file create success!\n", getpid());
            close(file_desc);
            unlink(lock_file);
            sleep(1);
        }
    }

    return 0;
}