
#ifndef __NUP_CHAPTER_02_WHO2_H__
#define __NUP_CHAPTER_02_WHO2_H__

#include <utmp.h>

/*who命令升级版*/
int who2();

/*打开utmp文件,返回文件描述符*/
int open_utmp(char *file);

/*加载utmp记录到缓存*/
int reload_utmp();

/*读取一条记录*/
struct utmp* next_utmp();

/*关闭utmp文件*/
void close_utmp();

void show_info2(struct utmp *);

#endif // __NUP_CHAPTER_02_WHO2_H__
