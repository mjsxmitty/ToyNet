

/**
 * 缓冲读文件
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <utmp.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "who2.h"

#define CACHE_NUM   16
#define UTMP_SIZE   (sizeof(struct utmp))       // 缓存大小
#define UTMP_NULL   ((struct utmp *)NULL)

static char utmp_buf[CACHE_NUM * UTMP_SIZE];    // 缓存
static int  num_recs;                           // 读取数量
static int  cur_recs;                           // 当前索引
static int  utmp_fd = -1;                       // 文件描述符

int open_utmp(char *file)
{
    utmp_fd = open(file, O_RDONLY);
    if (utmp_fd == -1) {
        perror(UTMP_FILE);
        return utmp_fd;
    }
    
    cur_recs = num_recs = 0;
    return utmp_fd;
}

int reload_utmp()
{
    int read_num = read(utmp_fd, utmp_buf, CACHE_NUM * UTMP_SIZE);
    num_recs = read_num / UTMP_SIZE;
    cur_recs = 0;
    return num_recs;
}

struct utmp* next_utmp()
{
    struct utmp *ret;
    if (utmp_fd == -1)
        return UTMP_NULL;
    
    if (cur_recs == num_recs && reload_utmp() == 0)
        return UTMP_NULL;

    ret = (struct utmp *)&utmp_buf[cur_recs * UTMP_SIZE];
    cur_recs++;
    
    return ret;
}


void close_utmp()
{
    if (utmp_fd != -1)
        close(utmp_fd);
    
}

// 缓存
int who2()
{
    struct utmp *ut_buf;
    if (open_utmp(UTMP_FILE) == -1) {
        perror(UTMP_FILE);
        exit(-1);
    }
    
    while ((ut_buf = next_utmp()) != UTMP_NULL) {
        show_info2(ut_buf);
    }
}


void show_info2(struct utmp *ut_buf)
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