
#ifndef __ULP_WHO_H__
#define __ULP_WHO_H__

#include <utmp.h>

/*who命令第一个版本*/
int who1();

/*who命令升级版*/
int who2();

/*显示utmp结构信息*/
void show_info(struct utmp *);

/*格式化时间*/
void  show_time(long);

/*打开utmp文件,返回文件描述符*/
int open_utmp(char *file);

/*加载utmp记录到缓存*/
int reload_utmp();

/*读取一条记录*/
struct utmp* next_utmp();

/*关闭utmp文件*/
void close_utmp();

#endif //__ULP_CHAPTER_02_WHO_H__