

#include "chapter_07.h"
#include <unistd.h>

void ch_07(int argc, char **argv)
{
    if (argc == 1) {
        lock_demo2();
    } else {
        lock_demo3();
    }
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

const char *lock_file = "/tmp/LOCK.text";

void lock_demo2() {
    int file_desc;
    int tries = 5;

    while (tries--)
    {
        file_desc = open(lock_file, O_RDWR|O_CREAT|O_EXCL, 0444);
        if (file_desc == -1) {
            printf("%d - LOCK file already exist!\n", getpid());
            sleep(2);
        } else {
            printf("%d - have exclusive access!\n", getpid());
            close(file_desc);
            unlink(lock_file);
            sleep(1);
        }
    }

    exit(0);
}

#include <fcntl.h>

void lock_demo3() {
    int file_desc;
    int byte_cnt;
    const char *byte_to_write = "*";
    struct flock region_1;
    struct flock region_2;
    int res = 0;
    
    file_desc = open(lock_file, O_RDWR|O_CREAT, 0666);
    if (file_desc == -1) {
        fprintf(stderr, "unable to open %s for read/write\n", lock_file);
        exit(-1);
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
    exit(0);
}

void show_lock_info(const struct flock *to_show) {
#if 0
    printf("\tl_type: %s, l_whence: %d, l_start: %d, l_len: %d, l_pid: %d\n", 
            to_show->l_type ? "RDLOCK" : "WRLOCK",
            to_show->l_whence,
            to_show->l_start,
            to_show->l_len);
#endif
}

#define SIZE_TO_MOVE    5

void lock_demo4() {
    int file_desc;
    int start_byte;
    struct flock region_to_test;
    int res = 0;

    file_desc = open(lock_file, O_RDWR|O_CREAT,0666);
    if (file_desc == -1) {
        fprintf(stderr, "failed to open lock test file, path: %s\n", lock_file);
        exit(-1);
    }

    for (start_byte = 0; start_byte < 99; start_byte += SIZE_TO_MOVE) {

#if 0        
        region_to_test.l_type = F_RDLCK;
        region_to_test.l_whence = SEEK_SET;
        region_to_test.l_start = start_byte;
        region_to_test.l_len = SIZE_TO_MOVE;
        region_to_test.l_pid = -1;
        printf("testing F_RDLCK on region from %d to %d\n",
                start_byte, start_byte += SIZE_TO_MOVE);
#endif
#if 1        
        region_to_test.l_type = F_WRLCK;
        region_to_test.l_whence = SEEK_SET;
        region_to_test.l_start = start_byte;
        region_to_test.l_len = SIZE_TO_MOVE;
        region_to_test.l_pid = -1;
        printf("testing F_WRLCK on region from %d to %d\n",
                start_byte, start_byte += SIZE_TO_MOVE);
#endif

        res = fcntl(file_desc, F_GETLK, &region_to_test);
        if (res == -1) {
            fprintf(stderr, "F_GETLK failed.\n");
            exit(-1);
        }

        if (region_to_test.l_pid != -1) {
            printf("Lock would failed, F_GETLK returned: ");
            show_lock_info(&region_to_test);
        } else {
            printf("Lock would succeed.\n");
        }
    }

    close(file_desc);
    exit(0);
}

void lock_demo5() {
    int file_desc;
    struct flock region_to_lock;
    int res;
    int start_byte;

    file_desc = open(lock_file, O_RDWR|O_CREAT,0666);
    if (file_desc == -1) {
        fprintf(stderr, "failed to open lock test file, path: %s\n", lock_file);
        exit(-1);
    }

    // 10~15 共享锁
    region_to_lock.l_type = F_RDLCK;
    region_to_lock.l_whence = SEEK_SET;
    region_to_lock.l_start = start_byte;
    region_to_lock.l_len = 10;
    region_to_lock.l_pid = 5;
    printf("processing %d trying F_RDLCK, region %d to %d\n", 
            getpid(), 
            (int)region_to_lock.l_start, 
            (int)(region_to_lock.l_start+region_to_lock.l_len));

    res = fcntl(file_desc, F_SETLK, &region_to_lock);
    if (res == -1) {
        printf("processing %d - failed to lock region.\n", getpid());
    } else {
        printf("processing %d - obtauned to lock region.\n", getpid());
    }

    // 10~15 释放锁
    region_to_lock.l_type = F_UNLCK;
    region_to_lock.l_whence = SEEK_SET;
    region_to_lock.l_start = start_byte;
    region_to_lock.l_len = 10;
    region_to_lock.l_pid = 5;
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
    region_to_lock.l_start = start_byte;
    region_to_lock.l_len = 10;
    region_to_lock.l_pid = 5;
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
    region_to_lock.l_start = start_byte;
    region_to_lock.l_len = 16;
    region_to_lock.l_pid = 5;
    printf("processing %d trying F_WRLCK, region %d to %d\n", 
            getpid(), 
            (int)region_to_lock.l_start, 
            (int)(region_to_lock.l_start+region_to_lock.l_len));

    res = fcntl(file_desc, F_SETLK, &region_to_lock);
    if (res == -1) {
        printf("processing %d - failed to lock region.\n", getpid());
    } else {
        printf("processing %d - obtauned to lock region.\n", getpid());
    }

    // 40~50 共享锁
    region_to_lock.l_type = F_RDLCK;
    region_to_lock.l_whence = SEEK_SET;
    region_to_lock.l_start = start_byte;
    region_to_lock.l_len = 40;
    region_to_lock.l_pid = 10;
    printf("processing %d trying F_RDLCK, region %d to %d\n", 
            getpid(), 
            (int)region_to_lock.l_start, 
            (int)(region_to_lock.l_start+region_to_lock.l_len));

    res = fcntl(file_desc, F_SETLK, &region_to_lock);
    if (res == -1) {
        printf("processing %d - failed to lock region.\n", getpid());
    } else {
        printf("processing %d - obtauned to lock region.\n", getpid());
    }

    // 16~21 独占锁
    region_to_lock.l_type = F_WRLCK;
    region_to_lock.l_whence = SEEK_SET;
    region_to_lock.l_start = start_byte;
    region_to_lock.l_len = 16;
    region_to_lock.l_pid = 5;
    printf("processing %d trying F_WRLCK, region %d to %d\n", 
            getpid(), 
            (int)region_to_lock.l_start, 
            (int)(region_to_lock.l_start+region_to_lock.l_len));

    res = fcntl(file_desc, F_SETLKW, &region_to_lock);
    if (res == -1) {
        printf("processing %d - failed to lock region.\n", getpid());
    } else {
        printf("processing %d - obtauned to lock region.\n", getpid());
    }

    printf("processing %d - ending.\n", getpid());
    exit(0);
}


