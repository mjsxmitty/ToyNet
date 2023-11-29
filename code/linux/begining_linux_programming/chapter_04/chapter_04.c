
#include "chapter_04.h"

#include <unistd.h>
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>

#define _GUN_SOURCE

void ch_04(int argc, char **argv)
{
    /* 程序参数 */
    //argopt(argc, argv);

    //environ_demo(argc, argv);

    //time_demo(argc, argv);

    //tmp_file(argc, argv);

    //hostget();

    limits();
}

void argopt(int argc, char **argv)
{
    int opt;

    struct option longopts[] = {
        {"init", 0, NULL, 'i'},
        {"file", 1, NULL, 'f'},
        {"list", 0, NULL, 'l'},
        {"rest", 0, NULL, 'r'},
        {0, 0, 0, 0}
    };

    //while ((opt = getopt(argc, argv, ":if:lr")) != -1) {
    while ((opt = getopt_long(argc, argv, ":if:lr", longopts, NULL)) != -1) {
        switch (opt) {
            case 'i':
            case 'l':
            case 'r':
                printf("option: %c\n", opt);
                break;
            case 'f':
                printf("option: %c, param val: %s\n", opt, optarg);
                break;
            case ':':   // 未提供值
                printf("option need a value, option: %c\n", optopt);
                break;
            case '?':
                printf("unknown option: %c\n", optopt); // --w
                break;
            default:
                break;
        }
    }

    for ( ; optind < argc; optind++) {
        printf("argument: %s\n", argv[optind]);
    }
    
    return;
}

extern char **environ;

void environ_demo(int argc, char **argv)
{
    char    *val, *value;

    if (argc == 1 || argc > 3) {
        fprintf(stderr, "usage: environ val [value]\n");
        return ;
    }

    val = argv[1];
    value = getenv(val);
    if (value) 
        printf("variable %s has a value %s\n", val, value);
    else
        printf("variable %s has no value\n", val);

    if (argc == 3) {
        char *string;
        value = argv[2];
        string = malloc(strlen(val) + strlen(value) + 2);
        if (!string) {
            fprintf(stderr, "out of memory.\n");
            return ;
        }

        strcpy(string, val);
        strcat(string, "=");
        strcat(string, value);
        printf("calling putenv with %s\n", string);

        if (putenv(string) != 0) {
            fprintf(stderr, "putenv failed!\n");
            free(string);
            return ;
        }

        value = getenv(val);
        if (value) 
            printf("variable %s has a value %s\n", val, value);
        else
            printf("variable %s has no value\n", val);
    }
#if 0
    // 输出环境变量
    char **env = environ;
    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
#endif
}

#include <time.h>

void time_demo(int argc, char **argv)
{
    time_t the_time;
    struct tm   *tm_ptr;
    int i;
    char buf[128];
    char *result;
    
    /* time 函数 */
    for (i = 0; i < 5; i++)
    {
        the_time = time((time_t *)0);
        fprintf(stdout, "the time is: %ld\n", the_time);
        sleep(2);
    }
    
    time(&the_time);    // 传入非NULL，则值写入参数

    /* gmtime 函数 */
    tm_ptr = gmtime(&the_time);
    //tm_ptr = localtime(&the_time);
    
    printf("current time is: %ld\n", the_time);
    printf("date: %02d/%02d/%02d\n", tm_ptr->tm_year,
                                     tm_ptr->tm_mon + 1,
                                     tm_ptr->tm_mday);
    printf("time: %02d:%02d:%02d\n", tm_ptr->tm_hour,
                                     tm_ptr->tm_min,
                                     tm_ptr->tm_sec);

    printf("the astime is: %s\n", asctime(tm_ptr));
    printf("the cime is: %s\n", ctime(&the_time));


    strftime(buf, 128, "%A %d % B : %I %S %p\n", tm_ptr);
    printf("the strftime is: %s\n", buf);
}

void tmp_file(int argc, char **argv)
{
    char tmpname[L_tmpnam] = "tmp_file_XXXXXX";
    int fd;
    
    char *filename = tmpnam(tmpname);
    char *filename1 = mktemp(tmpname);
    printf("temporary file name is: %s - %s\n", filename, filename1);

    FILE *tmpfp = tmpfile();
    if (tmpfp) {
        printf("open a temporary file succeed.\n");
    } else {
        perror("tmpfile");
    }
#if 1
    fd = mkstemp(tmpname);
    printf("open temporary succeed, fd: %d\n", fd);
#endif
}

#include <unistd.h>
#include <sys/utsname.h>

void hostget()
{
    char buf[256];
    struct utsname uts;

    if (gethostname(buf, 255) != 0 || uname(&uts) < 0) {
        fprintf(stderr, "can not het hostname/uname.");
        exit(-1);
    }

    printf("hostname: %s\n", buf);
    printf("sysname: %s\n", uts.sysname);
    printf("nodename: %s\n", uts.nodename);
    printf("release: %s\n", uts.release);
    printf("version: %s\n", uts.version);
    printf("machine: %s\n", uts.machine);
}

#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <math.h>
#include <stdlib.h>

void work()
{
    FILE    *f;
    int     i;
    double  d = 4.5;

    f = tmpfile();
    for (i = 0; i < 10000; ++i) {
        fprintf(f, "do some output\n");
        if (ferror(f)) {
            fprintf(stderr, "error to writing to tempory file\n");
            exit(-1);
        }
    }

    for (i = 0; i < 1000000; ++i) {
        d = log(d*d + 3.21);
    }
}

void limits()
{
    struct rusage r_usage;
    struct rlimit r_limit;
    int priority;

    // 产生负载
    work();

    // 获取系统使用时间
    getrusage(RUSAGE_SELF, &r_usage);
    printf("cpu usage: user=%ld.%06ld, system=%ld.%06ld\n",
           r_usage.ru_utime.tv_sec, r_usage.ru_utime.tv_usec,
           r_usage.ru_stime.tv_sec, r_usage.ru_stime.tv_usec);

    // 获取优先级
    priority = getpriority(PRIO_PROCESS, getpid());
    printf("current priority: %d\n", priority);

    // 获取资源限制
    getrlimit(RLIMIT_FSIZE, &r_limit);
    printf("current file size limit: soft=%ld, hard=%ld\n",
           r_limit.rlim_cur, r_limit.rlim_max);


    // 设置资源限制
    r_limit.rlim_cur = 2048;
    r_limit.rlim_max = 4096;
    printf("setting file size 2K ...\n");
    if (setrlimit(RLIMIT_FSIZE, &r_limit) == -1) {
        fprintf(stderr, "set file size failed\n");
        exit(-1);
    }

    work();
    exit(0);
}
