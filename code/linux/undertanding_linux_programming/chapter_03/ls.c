
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

#include "ls.h"

void DoLs(char *dir_name)
{
    DIR             *dir_ptr;
    struct dirent   *dir_entp;

    if ((dir_ptr = opendir(dir_name)) == NULL) {
        fprintf(stderr, "open dir:%s failed.", dir_name);
        perror(dir_name);
    } else {
        while ((dir_entp = readdir(dir_ptr)) != NULL) {
            //printf("name:%s\n", dir_entp->d_name);
            DoStat(dir_entp->d_name);
        }
        closedir(dir_ptr);
    }
}

void DoStat(char *file_name)
{
    struct stat info;
    if (stat(file_name, &info) != -1) {
        ShowStatInfo(file_name, &info);
    } else {
        perror(file_name);
    }
    return ;
}

void ShowStatInfo(char *file_name, struct stat *buf)
{
    char str[11];
    ModeToLetters(buf->st_mode, str);
    printf("%12s", str);

    printf("%4d", (int)buf->st_nlink);
    printf("%-8s ", UidToName(buf->st_uid));
    printf("%-8s ", GidToName(buf->st_gid));
    printf("%8ld ", (long)buf->st_size);
    //printf("%.12s ", 4 + ctime(&buf->st_mtime));
    printf("%s\n", file_name);
}

void ModeToLetters(int mode, char *str)
{
    strcpy(str, "----------");
    if (S_ISDIR(mode)) str[0] = 'd';
    if (S_ISCHR(mode)) str[0] = 'c';
    if (S_ISBLK(mode)) str[0] = 'b';

    if (mode & S_IRUSR) str[1] = 'r';
    if (mode & S_IWUSR) str[2] = 'w';
    if (mode & S_IXUSR) str[3] = 'x';

    if (mode & S_IRGRP) str[4] = 'r';
    if (mode & S_IWGRP) str[5] = 'w';
    if (mode & S_IXGRP) str[6] = 'x';

    if (mode & S_IROTH) str[7] = 'r';
    if (mode & S_IWOTH) str[8] = 'w';
    if (mode & S_IXOTH) str[9] = 'x';
}

char* UidToName(uid_t uid)
{
    struct passwd *pwd_ptr;
    static char num_str[10];

    if ((pwd_ptr = getpwuid(uid)) == NULL) {
        sprintf(num_str, "%d", uid);
        return num_str;
    } else {
        return pwd_ptr->pw_name;
    }
}

char* GidToName(gid_t gid)
{
    struct group *gid_ptr;
    static char num_str[10];

    if ((gid_ptr = getgrgid(gid)) == NULL) {
        sprintf(num_str, "%d", gid);
        return num_str;
    } else {
        return gid_ptr->gr_name;
    }
}




