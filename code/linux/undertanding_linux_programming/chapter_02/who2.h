
#ifndef __NUP_CHAPTER02_WHO2_H__
#define __NUP_CHAPTER02_WHO2_H__

#include <utmp.h>

int Who2();

int OpenUtmp(char *file);

int ReloadUtmp();

struct utmp* NextUtmp();

int CloseUtmp();

#endif // __NUP_CHAPTER02_WHO2_H__
