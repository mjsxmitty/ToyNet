
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/mman.h>
#include <errno.h>

#include "chapter_03.h"

void ch_03(int argc, char **argv)
{
    /* 底层文件访问 */
    //write_demo();
    //read_write();
    //copy_demo();

    /* 格式化输入和输出 */
    //scanf_demo();

#if 0
    test_format_output();
    return ;
#endif

    /* 扫描文件 */
    //scan_file(argc, argv);

    /* 高级主题 */
    mmap_demo();
}

void write_demo()
{
    if (write(1, "here is some data\n", 18) != 18) 
        write(2, "a write error has occurred on file descriptor 1 \n", 50);
}

void read_write()
{
    char buf[128];
    int nread;

    nread = read(0, buf, 128);
    if (nread == -1)
        write(2, "a read error has occurred\n", 27);

    write(1, "output: ", strlen("output: "));
    if (write(1, buf, nread) != nread)
        write(2, "a write error has occurred\n", 28);
}

/* 文件复制程序 */
void copy_demo()
{
    char    c;
    int     in_fd, out_fd;
    char    buf[1024];

    in_fd = open("Makefile", O_RDONLY);
    if (in_fd == -1)
        perror("open input file");

    out_fd = open("file.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (out_fd == -1)
        perror("open output file");

    // while (read(in_fd, &c, 1) == 1)
    //     write(out_fd, &c, 1);

    int nread;
    while ((nread = read(in_fd, buf, 1024)) > 0)
        write(out_fd, buf, nread);
   
    printf("write finished.");
    exit(0);
}

void scanf_demo()
{
    char    s[256];
    int     n;
    float   f;
    char    c;

    scanf("hello, %d, %g, %c, %[^\n]", &n, &f, &c, s);
    //printf("%d\n%g\n%c\n%s\n", n, f, c, s);

    char out[256];
    sprintf(out, "%s-%d-%g-%c\n", s, n, f, c);
    printf("%s\n", out);
}

void ffunc_demo()
{
    int c;
    FILE *in, *out;

    in = fopen("Makefile", "r");
    while ((c = fgetc(in)) != EOF)
        fputc(c, stdout);
    
    printf("%d\n", feof(in));
    clearerr(in);

    printf("file id = %d\n", fileno(in));
    fclose(in);
    exit(0);
}

void print_dir(char *dir, int depth)
{
    DIR             *dp;
    struct dirent   *entry;
    struct stat     stat_buf;

    // 打开目录
    if ((dp = opendir(dir)) == NULL) {
        fprintf(stderr, "cannot open direntry: %s\n", dir);
        return ;
    }

    chdir(dir);
    while ((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name, &stat_buf);
        if (S_ISDIR(stat_buf.st_mode)) {
            if (strcmp(".", entry->d_name) == 0 ||
                strcmp("..", entry->d_name) == 0)
                    continue;
            
            printf("%*s%s/\n", depth, "", entry->d_name);
            print_dir(entry->d_name, depth + 4);
        } else {
            printf("%*s%s\n", depth, "", entry->d_name);
        }
    }
}

void test_format_output()
{
    printf("str=|%*s|%s|\n", 0, "***", "###");
    printf("str=|%*s|%s|\n", 4, "***", "###");
    printf("str=|%*s|%s|\n", 10, "***", "###");
    printf("str=|%*s|%*s|\n", -10, "***", 20, "###");
    printf("str=|%4.4s|%s|\n", "***", "###");
    printf("str=|%s|%2.4s|\n", "***", "###");
}

void scan_file(int argc, char **argv)
{
    char *top_dir = ".";
    if (argc >= 2)
        top_dir = argv[1];

    printf("dir scan of %s\n", top_dir);
    print_dir(top_dir, 0);
    printf("done\n");

    exit(0);
}

typedef struct 
{
    int     integer;
    char    str[24];
} RECORD;

#define NRECORDS    (10)

void print_file(const char *s)
{
    int i;
    RECORD record;

    FILE *fp = fopen(s, "r+");
     if (fp == NULL){
        fprintf(stderr, "open file failed.\n");
        return ;
    }

    for (i = 0; i < NRECORDS; ++i) {
        fread(&record, sizeof (RECORD), 1, fp);
        printf("%*s\n", record.str);
    }
    
    printf("\n");
    fclose(fp);
}

void mmap_demo()
{
    RECORD  record, *mapped;
    FILE    *fp;
    int     f;
    int     i;

    fp = fopen("record.dat", "w+");
    if (fp == NULL) {
        fprintf(stderr, "can not open record file!");
        return ;
    }

    //写文件
    for (i = 0; i < NRECORDS; ++i) {
        record.integer = i;
        sprintf(record.str, "RECORE-%d", i);
        fwrite(&record, sizeof (RECORD), 1, fp);
    }
    fclose(fp);
    
    print_file("record.dat");

    //修改文件
    fp = fopen("record.dat", "r+");
    if (fp == NULL) {
        fprintf(stderr, "can not open record file!");
        return ;
    }

    fseek(fp, 3 * sizeof (RECORD), SEEK_SET);
    fread(&record, sizeof (RECORD), 1, fp);
    record.integer = 1024;
    sprintf(record.str, "RECORE-%d", record.integer);

    fseek(fp, 3 * sizeof(RECORD), SEEK_SET);
    fwrite(&record, sizeof (RECORD), 1, fp);
    fclose(fp);
    
    print_file("record.dat");

    //映射
    f = open("record.dat", O_RDWR);
    if (f == -1) {
        printf("open file failed, errno: %d\n", errno);
        return ;
    }

    mapped = (RECORD *)mmap(0, NRECORDS * sizeof (RECORD), 
            PROT_READ | PROT_WRITE, MAP_SHARED, f, 0);

    mapped[7].integer = 0;
    sprintf(mapped[7].str, "RECORD-%d", mapped[7].integer);
    
    msync((void *)mapped, NRECORDS * sizeof(RECORD), MS_ASYNC);
    munmap((void *)mapped, NRECORDS * sizeof(RECORD));
    
    close(f);
    
    print_file("record.dat");

    exit(0);
}
