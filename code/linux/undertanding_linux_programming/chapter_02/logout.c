
#include "logout.h"

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

// lseek
int logout(char *name)
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

