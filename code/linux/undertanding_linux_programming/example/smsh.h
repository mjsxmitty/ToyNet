
#ifndef __ULP_SMSH_H__
#define __ULP_SMSH_H__

#include <stdio.h>

void smsh();

void set_up();

void fatal(const char *s1, const char *s2, int n);

int execute_cmd(char *arg_list[]);

void* emalloc(size_t n);

void* erealloc(void *p, size_t n);

void free_list(char **list);

char* new_str(char *s, int len);

char* next_cmd(char *p, FILE *f);

char** split_line(char *s);

int process(char **arg_list);

int is_control_cmd(char *arg);

int do_control_cmd(char **arg_list);

int ok_to_execute();

int syn_err(char *msg);

#endif //__ULP_SMSH_H__