
#ifndef __NLP_MORE_H__
#define __NLP_MORE_H__

#include <stdio.h>

void More(int argc, char **argv);

void DoMore(FILE *fp);

/* 打印消息,等待输入 */
// int SeeMore();
int SeeMore(FILE *fp);

#endif //__NLP_MORE_H__