
/**
 * 测试读文件内容 
 */

#include "who.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define SHOW_HOST

int who1()
{
    struct utmp current_record;
    int         utmp_fd;
    int         read_size = sizeof(current_record);

    if ((utmp_fd = open(UTMP_FILE, O_RDONLY)) == -1) {
        perror(UTMP_FILE);
        exit(-1);
    }
        
    while (read(utmp_fd, &current_record, read_size) == read_size)
        show_info(&current_record);

    close(utmp_fd);
    return 0;
}

void show_time(long time_val)
{
    char *cp = ctime(&time_val);
    printf("%12.12s", cp + 4);
}

void show_info(struct utmp *ut_buf)
{
    if (ut_buf->ut_type != USER_PROCESS)
        return ;
    
    printf("%-8.8s", ut_buf->ut_name);      // 总宽为8,输出宽度为8
    printf(" ");
    printf("%-8.8s", ut_buf->ut_line);
    printf(" ");
    //printf("%10ld", ut_buf->ut_time);
    show_time(ut_buf->ut_time);
    printf(" ");

#ifdef SHOW_HOST
    if (ut_buf->ut_host[0] != '\0')
        printf("(%s)", ut_buf->ut_host);
#endif

    printf("\n");        
}

