
#include "chapter_04.h"

#include <unistd.h>
#include <stdio.h>

void ch_04(int argc, char **argv)
{
    /* 短参数 */
    //ch_4_1_1(argc, argv);

    ch_4_1_2(argc, argv);
}

void ch_4_1_1(int argc, char **argv)
{
    int opt;

    while ((opt = getopt(argc, argv, ":if:lr")) != -1)
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
                printf("unknown option: %s\n", argv[optind] + 1);
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