
#ifndef __NUP_CHAPTER02_WHO2_H__
#define __NUP_CHAPTER02_WHO2_H__

#include <utmp.h>

/*who命令升级版*/
int who2();

/*打开utmp文件,返回文件描述符*/
int OpenUtmp(char *file);

/*加载utmp记录到缓存*/
int ReloadUtmp();

/*读取一条记录*/
struct utmp* NextUtmp();

/*关闭utmp文件*/
void CloseUtmp();

/*注销登录账号*/
int LogoutTTY(char *name);

#endif // __NUP_CHAPTER02_WHO2_H__
