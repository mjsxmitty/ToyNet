

#ifndef __GZ_PERSON_INFO_H__
#define __GZ_PERSON_INFO_H__

#include <string>

#define MAX_NUM 1000    //最大人数

/* 联系人结构体 */
struct Person
{
    std::string name;   //姓名
    int         sex;    //性别：1男 2女
    int         age;    //年龄
    std::string phone;  //电话
    std::string addr;   //住址
};

//通讯录结构体
struct AddressBooks
{
    struct Person   person_array[MAX_NUM];      // 通讯录中保存的联系人数组
    int             size;                       // 通讯录中人员个数
};

#endif // __GZ_PERSON_INFO_H__
