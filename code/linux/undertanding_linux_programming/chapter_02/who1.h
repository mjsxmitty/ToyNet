
#ifndef __ULP_CHAPTER_02_WHO1_H__
#define __ULP_CHAPTER_02_WHO1_H__

#include <utmp.h>

int     who1();
void    ShowInfo(struct utmp *);
void    ShowTime(long);

#endif //__ULP_CHAPTER_02_WHO_H__