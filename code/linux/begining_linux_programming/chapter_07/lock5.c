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
    struct flock region_to_lock;
    int res;

    file_desc = open(lock_file, O_RDWR|O_CREAT,0666);
    if (file_desc == -1) {
        fprintf(stderr, "failed to open lock test file, path: %s\n", lock_file);
        return -1;
    }

    // 10~15 共享锁
    region_to_lock.l_type = F_RDLCK;
    region_to_lock.l_whence = SEEK_SET;
    region_to_lock.l_start = 5;
    region_to_lock.l_len = 10;
    printf("processing %d trying F_RDLCK, region %d to %d\n", 
            getpid(), 
            (int)region_to_lock.l_start, 
            (int)(region_to_lock.l_start+region_to_lock.l_len));

    res = fcntl(file_desc, F_SETLK, &region_to_lock);
    if (res == -1) {
        printf("processing %d - failed to lock region.\n", getpid());
    } else {
        printf("processing %d - succeed to lock region.\n", getpid());
    }

    // 10~15 释放锁
    region_to_lock.l_type = F_UNLCK;
    region_to_lock.l_whence = SEEK_SET;
    region_to_lock.l_start = 10;
    region_to_lock.l_len = 5;
    printf("processing %d trying F_UNLCK, region %d to %d\n", 
            getpid(), 
            (int)region_to_lock.l_start, 
            (int)(region_to_lock.l_start+region_to_lock.l_len));

    res = fcntl(file_desc, F_SETLK, &region_to_lock);
    if (res == -1) {
        printf("processing %d - failed to unlock region.\n", getpid());
    } else {
        printf("processing %d - unlock region.\n", getpid());
    }

    // 0~50 释放锁
    region_to_lock.l_type = F_UNLCK;
    region_to_lock.l_whence = SEEK_SET;
    region_to_lock.l_start = 0;
    region_to_lock.l_len = 50;
    printf("processing %d trying F_UNLCK, region %d to %d\n", 
            getpid(), 
            (int)region_to_lock.l_start, 
            (int)(region_to_lock.l_start+region_to_lock.l_len));

    res = fcntl(file_desc, F_SETLK, &region_to_lock);
    if (res == -1) {
        printf("processing %d - failed to unlock region.\n", getpid());
    } else {
        printf("processing %d - unlock region.\n", getpid());
    }

    // 16~21 独占锁
    region_to_lock.l_type = F_WRLCK;
    region_to_lock.l_whence = SEEK_SET;
    region_to_lock.l_start = 5;
    region_to_lock.l_len = 20;
    printf("processing %d trying F_WRLCK, region %d to %d\n", 
            getpid(), 
            (int)region_to_lock.l_start, 
            (int)(region_to_lock.l_start+region_to_lock.l_len));

    res = fcntl(file_desc, F_SETLK, &region_to_lock);
    if (res == -1) {
        printf("processing %d - failed to lock region.\n", getpid());
    } else {
        printf("processing %d - succeed to lock region.\n", getpid());
    }

    // 40~50 共享锁
    region_to_lock.l_type = F_RDLCK;
    region_to_lock.l_whence = SEEK_SET;
    region_to_lock.l_start = 40;
    region_to_lock.l_len = 10;
    printf("processing %d trying F_RDLCK, region %d to %d\n", 
            getpid(), 
            (int)region_to_lock.l_start, 
            (int)(region_to_lock.l_start+region_to_lock.l_len));

    res = fcntl(file_desc, F_SETLK, &region_to_lock);
    if (res == -1) {
        printf("processing %d - failed to lock region.\n", getpid());
    } else {
        printf("processing %d - succeed to lock region.\n", getpid());
    }

    // 16~21 独占锁
    region_to_lock.l_type = F_WRLCK;
    region_to_lock.l_whence = SEEK_SET;
    region_to_lock.l_start = 16;
    region_to_lock.l_len = 5;
    printf("processing %d trying F_WRLCK, region %d to %d\n", 
            getpid(), 
            (int)region_to_lock.l_start, 
            (int)(region_to_lock.l_start+region_to_lock.l_len));

    res = fcntl(file_desc, F_SETLKW, &region_to_lock);
    if (res == -1) {
        printf("processing %d - failed to lock region.\n", getpid());
    } else {
        printf("processing %d - succeed to lock region.\n", getpid());
    }

    printf("processing %d - ending.\n", getpid());
    exit(0);
}

