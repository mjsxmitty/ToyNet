
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
    int byte_cnt;
    const char *byte_to_write = "*";
    struct flock region_1;
    struct flock region_2;
    int res = 0;
    
    file_desc = open(lock_file, O_RDWR | O_CREAT, 0666);
    if (file_desc == -1) {
        fprintf(stderr, "unable to open %s for read/write\n", lock_file);
        return -1;
    }

    for (byte_cnt = 0; byte_cnt < 100; ++byte_cnt) {
        write(file_desc, byte_to_write, 1);
    }

    // 10~30 共享锁
    region_1.l_type = F_RDLCK;
    region_1.l_whence = SEEK_SET;
    region_1.l_start = 10;
    region_1.l_len = 20;

    // 40~50 独占锁
    region_2.l_type = F_WRLCK;
    region_2.l_whence = SEEK_SET;
    region_2.l_start = 40;
    region_2.l_len = 10;

    printf("process %d locking file\n", getpid());
    res = fcntl(file_desc, F_SETLK, &region_1);
    if (res == -1) {
        fprintf(stderr, "failed to lock region 10~30.\n");
    }

    res = fcntl(file_desc, F_SETLK, &region_2);
    if (res == -1) {
        fprintf(stderr, "failed to lock region 40~50.\n");
    }

    sleep(60);
    printf("process %d closing file\n", getpid());
    close(file_desc);
    
    return 0;
}