
#include "chapter_04.h"

#include <unistd.h>
#include <stdio.h>

void ch_04(int argc, char **argv)
{
    /* 程序参数 */
    //ch_4_1(argc, argv);

    /* 环境变量 */
    //ch_4_2(argc, argv);

    /* 时间和日期 */
    //ch_4_3(argc, argv);

    /* 临时文件 */
    ch_4_4(argc, argv);
}

void ch_4_1(int argc, char **argv)
{
    /* 短参数 */
    //ch_4_1_1(argc, argv);

    /* 长参数 */
    ch_4_1_2(argc, argv);
}

void ch_4_1_1(int argc, char **argv)
{
    int opt;

    while ((opt = getopt(argc, argv, ":if:lr")) != -1)      // ":"
    {
        switch (opt)
        {
            case 'i':
            case 'l':
            case 'r':
                printf("option: %c\n", opt);
                break;
            case 'f':
                printf("option: %c, param val: %s\n", opt, optarg);
                break;
            case ':':
                {
                    printf("option need a value\n");
                    printf("optarg: %s\n", optarg);
                    printf("optopt: %d\n", optopt);
                    printf("opterr: %d\n", opterr);
                }
                break;
            case '?':
                {
                    printf("unknown option: %s\n", argv[optind - 1] + 1);
                    printf("optarg: %s\n", optarg);
                    printf("optopt: %d\n", optopt);
                    printf("opterr: %d\n", opterr);
                }
                break;
            default:
                break;
        }
    }
    
    for ( ; optind < argc; optind++)
    {
        printf("argument: %s\n", argv[optind]);
    }
    
    return;
}

#define _GUN_SOURCE
#include <getopt.h>

void ch_4_1_2(int argc, char **argv)
{
    int opt;

    struct option longopts[] = {
        {"init", 0, NULL, 'i'},
        {"file", 1, NULL, 'f'},
        {"list", 0, NULL, 'l'},
        {"rest", 0, NULL, 'r'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, ":if:lr", longopts, NULL)) != -1)
    {
        switch (opt)
        {
            case 'i':
            case 'l':
            case 'r':
                printf("option: %c\n", opt);
                break;
            case 'f':
                printf("option: %c, param val: %s\n", opt, optarg);
                break;
            case ':':
                {
                    printf("option need a value\n");
                    printf("optarg: %s\n", optarg);
                    printf("optopt: %d\n", optopt);
                    printf("opterr: %d\n", opterr);
                }
                break;
            case '?':
                {
                    printf("unknown option: %c\n", optopt);
                    printf("optarg: %s\n", optarg);
                    printf("optopt: %d\n", optopt);
                    printf("opterr: %d\n", opterr);
                }
                break;
            default:
                break;
        }
    }
    
    for ( ; optind < argc; optind++)
    {
        printf("argument: %s\n", argv[optind]);
    }
    
    return;
}

#include <stdlib.h>
#include <string.h>

extern char **environ;

void ch_4_2(int argc, char **argv)
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
        value = argv[2];
        char *string = malloc(strlen(val) + strlen(value) + 2);
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

    // 输出环境变量
    char **env = environ;
    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
    
    return ;
}

#include <time.h>

void ch_4_3(int argc, char **argv)
{
    time_t the_time;

    /* time 函数 */
    // for (int i = 0; i < 10; i++)
    // {
    //     the_time = time((time_t *)0);
    //     fprintf(stdout, "the time is: %ld\n", the_time);
    //     sleep(2);
    // }
    
    // time(&the_time);    // 传入非NULL，则值写入参数
    // fprintf(stdout, "the time is: %ld\n", the_time);

    /* gmtime 函数 */
    struct tm   *tm_ptr;

    time(&the_time);
    //tm_ptr = gmtime(&the_time);
    tm_ptr = localtime(&the_time);
    
    printf("current time is: %ld\n", the_time);
    printf("gmtime func return: ");
    printf("date: %02d/%02d/%02d\n", tm_ptr->tm_year,
                                     tm_ptr->tm_mon + 1,
                                     tm_ptr->tm_mday);
    printf("time: %02d:%02d:%02d\n", tm_ptr->tm_hour,
                                     tm_ptr->tm_min,
                                     tm_ptr->tm_sec);
    
    printf("the date is: %s\n", ctime(&the_time));
    return ;
}

void ch_4_4(int argc, char **argv)
{
    char tmpname[L_tmpnam] = "aaaXXXXXX";
    //char *filename = tmpnam(tmpname);
    char *filename = mktemp(tmpname);
    printf("temporary file name is: %s - %s\n", filename, tmpname);

    FILE *tmpfp = tmpfile();
    if (tmpfp) {
        printf("open a temporary file succeed.\n");
    } else {
        perror("tmpfile");
    }

    char tmpname2[] = "aaaXXXXXX";
    int fd = mkstemp(tmpname2);
    printf("open temporary succeed, fd: %d\n", fd);
}