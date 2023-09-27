
#ifndef __NLP_CHAPTER_01_MORE_H__
#define __NLP_CHAPTER_01_MORE_H__

#include <stdio.h>

/*more命令*/
void More(int argc, char **argv);

/*执行more*/
void DoMore(FILE *fp);

/* 打印消息,等待输入 */
// int SeeMore();
int SeeMore(FILE *fp);

#endif //__NLP_CHAPTER_01_MORE_H__