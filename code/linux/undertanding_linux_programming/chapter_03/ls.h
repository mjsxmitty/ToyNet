
#ifndef __NLP_CHAPTER_03_LS_H__
#define __NLP_CHAPTER_03_LS_H__

#include <sys/types.h>
#include <sys/stat.h>

/*ls 命令*/
void DoLs(char *dir_name);

/*获取文件信息*/
void DoStat(char *file_name);

/*显示文件属性*/
void ShowStatInfo(char *file_name, struct stat *buf);

/*显示文件模式*/
void ModeToLetters(int mode, char *str);

char* UidToName(uid_t uid);
char* GidToName(gid_t gid);

#endif //__NLP_CHAPTER_03_LS_H__