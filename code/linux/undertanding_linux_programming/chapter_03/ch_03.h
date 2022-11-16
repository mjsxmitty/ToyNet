#ifndef __ULP_CHAPTER_03_H__
#define __ULP_CHAPTER_03_H__

#include <unistd.h>

void testLs(int ac, char **av);

void DoLs(char *dir_name);
void testLs(int ac, char **av);
void ModeToLetters(int mode, char *str);
char* UidToName(uid_t uid);
char* GidToName(gid_t gid);
void ShowStatInfo(char *file_name, struct stat *buf);
void DoStat(char *file_name);

#endif //__ULP_CHAPTER_03_H__