

#ifndef __ADDRESS_BOOK_H__
#define __ADDRESS_BOOK_H__

#include <string>

#define MAX 1000

using namespace std;

struct Person
{
	string  name_;  //姓名
	int     sex_;   //性别：1男 2女
	int     age_;   //年龄
	string  phone_; //电话
	string  addr_;  //住址
};

struct AddressBooks
{
	//vector
    Person  person_array_[MAX];     //通讯录中保存的联系人数组
	int     size_;                  //通讯录中人员个数
};


void addPerson(AddressBooks *abs);
void showPerson(AddressBooks *abs);
void deletePerson(AddressBooks *abs);
void findPerson(AddressBooks *abs);
void modifyPerson(AddressBooks *abs);
void clearPerson(AddressBooks *abs);

#endif //__ADDRESS_BOOK_H__
