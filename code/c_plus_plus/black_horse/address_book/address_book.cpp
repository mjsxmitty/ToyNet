

#include <iostream>

#include "address_book.h"


void addPerson(AddressBooks *abs)
{
    if (abs->size_ == MAX) {
        std::cout << "通讯录已满，无法添加!" << std::endl;
        return ;
    } else {
        //姓名
        std::string name;
        std::cout << "请输入姓名： " << std::endl;
        std::cin >> name;
        abs->person_array_[abs->size_].name_ = name;

        //性别
        std::cout << "请输入性别: " << std::endl;
        std::cout << "1 -----> 男" << std::endl;
        std::cout << "2 -----> 女" << std::endl;

        int sex = 0;
        while (true) {
            std::cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->person_array_[abs->size_].sex_ = sex;
                break;
            }
            std::cout << "输入有误，清重新输入！" << std::endl;
        }

        //年龄
        std::cout << "请输入年龄： " << std::endl;
        int age = 0;
        std::cin >> age;
        abs->person_array_[abs->size_].age_ = age;

        //联系电话
        std::cout << "请输入联系电话： " << std::endl;
        std::string phone;
        std::cin >> phone;
        abs->person_array_[abs->size_].phone_ = phone;
        
        //家庭住址
        std::cout << "请输入家庭住址： " << std::endl;
        std::string addr;
        std::cin >> addr;
        abs->person_array_[abs->size_].addr_ = addr;

        //更新人数
        abs->size_++;
        std::cout << "添加成功！" << std::endl;
    }
    //system("clear");
}

void showPerson(AddressBooks *abs)
{
    if (abs->size_ == 0) {
        std::cout << "当前通讯录内容为空" << std::endl;
        return ;
    } else {
        for (size_t i = 0; i < abs->size_; i++) {
			std::cout << "姓名：" << abs->person_array_[i].name_ << "\t";
			std::cout << "性别：" << (abs->person_array_[i].sex_ == 1 ? "男" : "女") << "\t";
			std::cout << "年龄：" << abs->person_array_[i].age_ << "\t";
			std::cout << "电话：" << abs->person_array_[i].phone_ << "\t";
			std::cout << "住址：" << abs->person_array_[i].addr_ << endl;
        }
    }
    //system("clear");
}
    
int isExist(AddressBooks *abs, std::string name)
{
    for (int i = 0; i < abs->size_; i++) {
        if (abs->person_array_[i].name_ == name) {
            return i;
        }
    }
    return -1;
}

void deletePerson(AddressBooks *abs)
{
    std::cout << "请输入要删除的联系人： ";
    std::string name;
    std::cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1) {
        for (int i = ret; i < abs->size_; i++) {
            abs->person_array_[i] = abs->person_array_[i + 1];
        }
        
        abs->size_--;
        std::cout << "删除成功！" << std::endl;
    } else {
        std::cout << "查无此人！" << std::endl;
    }
    system("clear");
}

void findPerson(AddressBooks *abs)
{
    std::cout << "请输入要查找的联系人： ";
    std::string name;
    std::cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1) {
        std::cout << "姓名：" << abs->person_array_[ret].name_ << "\t";
        std::cout << "性别：" << (abs->person_array_[ret].sex_ == 1 ? "男" : "女") << "\t";
        std::cout << "年龄：" << abs->person_array_[ret].age_ << "\t";
        std::cout << "电话：" << abs->person_array_[ret].phone_ << "\t";
        std::cout << "住址：" << abs->person_array_[ret].addr_ << endl;
    } else {
        std::cout << "查无此人！" << std::endl;
    }

    //system("clear");
}

void modifyPerson(AddressBooks *abs)
{
    std::cout << "请输入要修改的联系人： ";
    std::string name;
    std::cin >> name;

    int ret = isExist(abs, name);
    if (ret == -1) {
        std::cout << "查无此人！" << std::endl;
        return ;
    }

    //姓名
    std::string name2;
    std::cout << "请输入姓名： " << std::endl;
    std::cin >> name2;
    abs->person_array_[ret].name_ = name2;

    //性别
    std::cout << "请输入性别: " << std::endl;
    std::cout << "1 -----> 男" << std::endl;
    std::cout << "2 -----> 女" << std::endl;

    int sex = 0;
    while (true) {
        std::cin >> sex;
        if (sex == 1 || sex == 2) {
            abs->person_array_[ret].sex_ = sex;
            break;
        }
        std::cout << "输入有误，清重新输入！" << std::endl;
    }

    //年龄
    std::cout << "请输入年龄： " << std::endl;
    int age = 0;
    std::cin >> age;
    abs->person_array_[ret].age_ = age;

    //联系电话
    std::cout << "请输入联系电话： " << std::endl;
    std::string phone;
    std::cin >> phone;
    abs->person_array_[ret].phone_ = phone;
    
    //家庭住址
    std::cout << "请输入家庭住址： " << std::endl;
    std::string addr;
    std::cin >> addr;
    abs->person_array_[ret].addr_ = addr;
    std::cout << "修改成功" << std::endl;
}

void clearPerson(AddressBooks *abs)
{
    //逻辑清空
    abs->size_ = 0;
    std::cout << "当前通讯录清空成功" << std::endl;
}