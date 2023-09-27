
#ifndef __ULP_CHAPTER_02_WHO1_H__
#define __ULP_CHAPTER_02_WHO1_H__

#include <utmp.h>

/*who命令第一个版本*/
int who1();

/*显示utmp结构信息*/
void ShowInfo(struct utmp *);

/*格式化时间*/
void  ShowTime(long);

#endif //__ULP_CHAPTER_02_WHO_H__