
#ifndef __NLP_PWD_H__
#define __NLP_PWD_H__

#include <sys/stat.h>

/*pwd ����ʵ��*/
void pwd();

/*���ȫ·��*/
void print_path_to(ino_t this_node);

/*��ȡָ���ļ���inode*/
ino_t get_inode(char *fname);

/*��ȡָ��inode���ļ���*/
void inum_to_name(ino_t inode_to_find, char *name_buf, int buf_len);

#endif // __NLP_PWD_H__
