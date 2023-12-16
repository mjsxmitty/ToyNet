
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE_TO_MOVE 5

const char *lock_file = "./LOCK.text";

void show_lock_info(const struct flock *to_show) {
#if 1
    printf("\tl_type: %s, l_whence: %d, l_start: %ld, l_len: %ld, l_pid: %d\n", 
            to_show->l_type ? "RDLOCK" : "WRLOCK",
            to_show->l_whence,
            to_show->l_start,
            to_show->l_len);
#endif
}

int main() 
{
    int file_desc;
    int start_byte = 0;
    int end_byte = 99;
    struct flock region_to_test;
    int res = 0;

    file_desc = open(lock_file, O_RDWR|O_CREAT,0666);
    if (file_desc == -1) {
        fprintf(stderr, "failed to open lock test file, path: %s\n", lock_file);
        exit(-1);
    }

    for (start_byte = 0; start_byte < end_byte; ) {
#if 0       
        region_to_test.l_type = F_RDLCK;
        region_to_test.l_whence = SEEK_SET;
        region_to_test.l_start = start_byte;
        region_to_test.l_len = 5;
        region_to_test.l_pid = -1;
        end_byte = start_byte + SIZE_TO_MOVE;
        printf("testing F_RDLCK on region from %d to %d\n", start_byte, end_byte);
#endif
#if 1        
        region_to_test.l_type = F_WRLCK;
        region_to_test.l_whence = SEEK_SET;
        region_to_test.l_start = start_byte;
        region_to_test.l_len = 5;
        region_to_test.l_pid = -1;
        start_byte = start_byte + SIZE_TO_MOVE;
        printf("testing F_WRLCK on region from %d to %d\n", start_byte, end_byte);
#endif
        res = fcntl(file_desc, F_GETLK, &region_to_test);
        if (res == -1) {
            fprintf(stderr, "F_GETLK failed.\n");
            return -1;
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