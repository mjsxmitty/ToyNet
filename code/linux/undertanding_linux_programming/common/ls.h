
#ifndef __NLP_LS_H__
#define __NLP_LS_H__

#include <sys/types.h>
#include <sys/stat.h>

int ls(int argc, char **argv);

/*ls 命令*/
void do_ls(char *dir_name);

/*获取文件信息*/
void do_stat(char *file_name);

/*显示文件属性*/
void show_stat_info(char *file_name, struct stat *buf);

/*显示文件模式*/
void model_to_letters(int mode, char *str);

char* uid_to_name(uid_t uid);
char* gid_to_name(gid_t gid);

#endif //__NLP_LS_H__
