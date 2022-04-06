
/**
 * 测试读文件内容 
 */

#ifndef __CHAPTER02_WHO_H__
#define __CHAPTER02_WHO_H__


#include <utmp.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define SHOWHOST

void ShowInfo(struct utmp *);
void ShowTime(long);

int Who()
{
    struct utmp current_record;
    int         utmp_fd;
    int         read_size = sizeof(current_record);

    if ((utmp_fd = open(UTMP_FILE, O_RDONLY)) == -1) {
        perror(UTMP_FILE);
        _exit(-1);
    }
        
    while (read(utmp_fd, &current_record, read_size) == read_size)
        ShowInfo(&current_record);

    close(utmp_fd);
    
    return 0;
}

void ShowTime(long time_val)
{
    char *cp = ctime(&time_val);
    printf("%12.12s", cp + 4);
}

void ShowInfo(struct utmp *ut_buf)
{
    if (ut_buf->ut_type != USER_PROCESS)
        return ;
    
    printf("%-8.8s", ut_buf->ut_name);
    printf(" ");
    printf("%-8.8s", ut_buf->ut_line);
    printf(" ");
    //printf("%10ld", ut_buf->ut_time);
    ShowTime(ut_buf->ut_time);
    printf(" ");
#ifdef SHOWHOST
    if (ut_buf->ut_host[0] != '\0')
        printf("(%s)", ut_buf->ut_host);
#endif
    printf("\n");        
}


#endif //__CHAPTER02_WHO_H__