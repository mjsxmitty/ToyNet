
#include "smsh.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define DEL_PROMPT  ">"

void smsh() {

    char *cmd_line, *pro_line = DEL_PROMPT, **arg_list;
    int ret;

    while ((cmd_line = next_cmd(pro_line, stdin)) != NULL) {
        if ((arg_list = split_line(cmd_line)) != NULL) {
            //ret = execute_cmd(arg_list);
            ret = process(arg_list);
            free_list(arg_list);
        }
        free(cmd_line);
    }
}

void set_up() {
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
}

void fatal(const char *s1, const char *s2, int n) {
    fprintf(stderr, "error: %s, %s\n", s1, s2);
    exit(n);
}

int execute_cmd(char *arg_list[]) {
    int pid;
    int child_info = -1;

    if (arg_list[0] == NULL) {
        return 0;
    }

    if ((pid = fork()) == -1) {
        perror("fork");
    } else if (pid == 0) {
        signal(SIGINT, SIG_DFL);
        signal(SIGQUIT, SIG_DFL);

        if (execvp(arg_list[0], arg_list) == -1) {
            perror("can't execute cmd.");
            exit(-1);
        }
    } else {
        if (wait(&child_info) == -1) {
            perror("wait");
        }
        return child_info;
    }
}

void* emalloc(size_t n) {
    void *rv = NULL;
    if ((rv = malloc(n)) == NULL) {
        fatal("out of memory", "", -2);
    }
    return rv;
}

void* erealloc(void *p, size_t n) {
    void *rv;
    if ((rv = realloc(p, n)) == NULL) {
        fatal("realloc() failed.", "", -2);
    }
    return rv;

}

void free_list(char **list) {
    char **ptr = list;
    while (*ptr) {
        free(*ptr++);
    }
    free(list);
}

char* new_str(char *s, int len) {
    char *rv = emalloc(len + 1);
    strncpy(rv, s, len);
    rv[len] = '\0';
    return rv;
}

#define BUFF_SIZE    128

char* next_cmd(char *p, FILE *f) {
    char *buf;
    int buf_size = 0;
    int pos = 0;
    int c;

    printf("%s", p);
    while ((c = getc(f)) != EOF) {
        if (pos + 1 >= buf_size) {
            if (buf_size == 0) {
                buf = emalloc(BUFF_SIZE);
            } else {
                buf = erealloc(buf, buf_size + BUFF_SIZE);
            }
            buf_size += BUFF_SIZE;
        }

        if (c == '\n')
            break;

        buf[pos++] = c;
    }

    if (c == EOF && c == 0)
        return NULL;

    buf[pos] = '\0';
    return buf;
}

#define is_delim(x)  ((x) == ' ' || (x) == '\t')

char** split_line(char *s) {

    char *cp = s;
    int spots = 0;          // 数组大个数
    int arg_num = 0;        // 参数个数
    char **args;            // 参数
    int buff_spaces = 0;    // 数组空间大小
    char *start;            // 参数游标
    int len;                // 参数长度
    
    if (s == NULL)
        return NULL;

    // 预分配参数数组
    args = emalloc(BUFF_SIZE);
    buff_spaces = BUFF_SIZE;
    spots = BUFF_SIZE / sizeof(char *);     // 数组元素个数
    
    while (*cp != '\0') {
        // 过滤空格
        while (is_delim(*cp))
            ++cp;
        // 到最后跳出
        if(*cp == '\0')
            break;

        // 参数个数超出预分配
        if (arg_num + 1 >= spots) {
            args = erealloc(args, buff_spaces + BUFF_SIZE);
            buff_spaces += BUFF_SIZE;
            spots += (BUFF_SIZE / sizeof(char *));
        }

        // 确定单个参数
        start = cp;
        len = 1;
        while (*++cp != '\0' && !(is_delim(*cp)))
            ++len;

        args[arg_num++] = new_str(start, len);
    }

    args[arg_num] = NULL;
    return args;
}

int process(char **arg_list) {
    int ret = 0;

    if (arg_list[0] = NULL)
        return 0;
    else if (is_control_cmd(arg_list[0]))   // TODO ...
        ret = do_control_cmd(arg_list);
    else if (ok_to_execute())
        ret = execute_cmd(arg_list);

    return ret;
}

enum {NEUTRAL, WANT_THEN, THEN_BLOCK};
enum {SUCCESS, FAIL};

static int if_state = NEUTRAL;
static int if_result = SUCCESS;
static int last_state = 0;

int syn_err(char *msg) {
    if_state = NEUTRAL;
    fprintf(stderr, "syntex error: %s\n", msg);
    return -1;
}

int is_control_cmd(char *arg) {
    return (strcmp(arg, "if") == 0 ||
            strcmp(arg, "then") == 0 ||
            strcmp(arg, "fi") == 0);
}

int do_control_cmd(char **arg_list) {
    char *cmd = arg_list[0];
    int rv = -1;

    if (strcmp(cmd, "if") == 0) {
        if (if_state != NEUTRAL) {
            rv = syn_err("if");
        } else {
            last_state = process(arg_list + 1);
            if_result = (last_state ? SUCCESS : FAIL);
            if_state = WANT_THEN;
            rv = 0;
        }
    } else if (strcmp(cmd, "then") == 0) {
        if (if_state != WANT_THEN) {
            rv = syn_err("then");
        } else {
            if_state = THEN_BLOCK;
            rv = 0;
        }
    } else if (strcmp(cmd, "fi") == 0) {
        if (if_state != THEN_BLOCK) {
            rv = syn_err("fi");
        } else {
            if_state = NEUTRAL;
            rv = 0;
        }
    } 

    return rv;
}

int ok_to_execute() {
    int ret = 1;

    // 只有then之后可以执行命令
    if (if_state == WANT_THEN) {
        syn_err("then");
        ret = 0;
    } else if (if_state == THEN_BLOCK && if_result == SUCCESS) {
        ret = 1;
    } else if (if_state == THEN_BLOCK && if_result == SUCCESS) {
        ret = 0;
    }

    return ret;
}

