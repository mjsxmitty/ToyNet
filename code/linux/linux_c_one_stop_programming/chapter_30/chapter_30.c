

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "chapter_30.h"

void Chapter_30()
{
    //chapter_30_1();
    //chapter_30_2();
    chapter_30_3();
}

/* 打印环境变量(所有) */
void chapter_30_1()
{
    //不包含在任一文件，使用需要加extern
    extern char **environ;
    for (int i = 0; environ[i] != NULL; ++i)
        printf("%s\n", environ[i]);
    
    return ;
}

/* 修改环境变量 */
void chapter_30_2()
{
    printf("%s\n", getenv("PATH"));
    setenv("PATH", "hello", 1);     //子进程操作不影响父进程
    printf("%s\n", getenv("PATH"));

    return ;
}

void chapter_30_3()
{
    pid_t   pid;
    char    *msg;
    int     n;

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    
    if (pid == 0) {
        msg = "this is child.\n";
        n = 6;
    } else {
        msg = "this is parent.\n";
        n = 3;
    }

    for ( ; n > 0; --n) {
        printf("%s\n", msg);
        sleep(1);
    }
    
    return;
}
