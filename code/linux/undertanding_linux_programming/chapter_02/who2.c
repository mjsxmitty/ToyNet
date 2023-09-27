

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
#include "who1.h"

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
    struct utmp *ret;
    if (utmp_fd == -1)
        return UTMP_NULL;
    
    if (cur_recs == num_recs && ReloadUtmp() == 0)
        return UTMP_NULL;

    ret = (struct utmp *)&utmp_buf[cur_recs * UTMP_SIZE];
    cur_recs++;
    
    return ret;
}


void CloseUtmp()
{
    if (utmp_fd != -1)
        close(utmp_fd);
    
}

// 缓存
int who2()
{
    struct utmp *ut_buf;
    if (OpenUtmp(UTMP_FILE) == -1) {
        perror(UTMP_FILE);
        exit(-1);
    }
    
    while ((ut_buf = NextUtmp()) != UTMP_NULL) {
        ShowInfo(ut_buf);
    }
}

// lseek
int LogoutTTY(char *name)
{
    int         fd;
    struct utmp ret;
    int         utmp_len = sizeof(struct utmp);
    int         ret_val = -1;

    if ((fd = OpenUtmp(UTMP_FILE)) == -1) {
        return -1;
    }

    while (read(fd, &ret, utmp_len) == utmp_len) {
        if (strncmp(ret.ut_user, name, sizeof(ret.ut_user)) == 0) {
            ret.ut_type = DEAD_PROCESS;
            //if (time(&ret.ut_tv.tv_sec) != -1) {
                if (lseek(fd, -utmp_len, SEEK_CUR) != -1) {
                    if (write(fd, &ret, utmp_len) == utmp_len) {
                        ret_val = 0;
                    }
                }
            //}

            break;
        }
    }
    
    CloseUtmp(fd);

    return ret_val;
}
