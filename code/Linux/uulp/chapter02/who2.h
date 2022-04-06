

/**
 * 缓冲读文件
*/

#ifndef __CHAPTER02_WHO2_H__
#define __CHAPTER02_WHO2_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <utmp.h>
#include <unistd.h>

#include "who.h"

#define CACHE_NUM   16
#define UTMP_SIZE   (sizeof(struct utmp))
#define UTMP_NULL   ((struct utmp *)NULL)

static char utmp_buf[CACHE_NUM * UTMP_SIZE];
static int  num_recs;
static int  cur_recs;
static int  utmp_fd = -1;


int OpenUtmp(char *file)
{
    utmp_fd = open(file, O_RDONLY);
    if (utmp_fd == -1) {
        perror(UTMP_FILE);
        return utmp_fd;
    }
    
    cur_recs = num_recs = 0;
    return utmp_fd;
}

int ReloadUtmp()
{
    int read_num = read(utmp_fd, utmp_buf, CACHE_NUM * UTMP_SIZE);
    num_recs = read_num / UTMP_SIZE;
    cur_recs = 0;
    return num_recs;
}

struct utmp* NextUtmp()
{
    struct utmp *recp;
    if (utmp_fd == -1)
        return UTMP_NULL;
    
    if (cur_recs == num_recs && ReloadUtmp() == 0)
        return UTMP_NULL;

    recp = (struct utmp *)&utmp_buf[cur_recs * UTMP_SIZE];
    cur_recs++;
    return recp;
}


int CloseUtmp()
{
    if (utmp_fd != -1)
        close(utmp_fd);
    
}

int testCacheWho()
{
    struct utmp *ut_buf;
    if (OpenUtmp(UTMP_FILE) == -1) {
        perror(UTMP_FILE);
        _exit(-1);
    }
    
    while ((ut_buf = NextUtmp()) != UTMP_NULL) {
        ShowInfo(ut_buf);
    }
    
}
#endif //__CHAPTER02_WHO2_H__