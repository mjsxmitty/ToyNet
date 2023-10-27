
#ifndef __NLP_MORE_H__
#define __NLP_MORE_H__

#include <stdio.h>

/*more命令*/
void more(int argc, char **argv);

/*执行more*/
void do_more(FILE *fp);

/* 打印消息,等待输入 */
// int see_more();
int see_more(FILE *fp);

#endif //__NLP_MORE_H__