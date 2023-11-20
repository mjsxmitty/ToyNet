

#ifndef __EFFECTIVE_CPP_ITEM_03_H__
#define __EFFECTIVE_CPP_ITEM_03_H__

#include <string>
#include <list>
#include <iostream>

void Item03();

namespace effective_item_03 {

class PhoneNumber{};
class ABEntry
{
public:
    // 调用成员的default函数
    ABEntry() : the_name_(), the_address_(), the_phones_()//, num_times_consulted_(0)
    {
        InitNumTimesConsulted(0);
    }

    // 注意顺序
    ABEntry(const std::string &name, const std::string &addr,
            const std::list<PhoneNumber> &phones, int num_times_consulted)
        : the_name_(name), the_address_(addr), the_phones_(phones)//, num_times_consulted_(0)
    {
        InitNumTimesConsulted(num_times_consulted);
    }
private:
    void InitNumTimesConsulted(int num)
    {
        num_times_consulted_ = num;
    }
private:
    std::string             the_name_;
    std::string             the_address_;
    std::list<PhoneNumber>  the_phones_;
    int                     num_times_consulted_;
};

class FileSystem
{
public:
    FileSystem()
    {
        std::cout << "FileSystem default construct function." << std::endl;
    }
public:
    std::size_t NumDisks()const
    {
        return 0;
    }
};

//extern FileSystem tfs;
FileSystem& tfs();

// 另一个独立文件内
class Directory
{
public:
    Directory()
    {
        std::cout << "Directory default construct function" << std::endl;
        //std::size_t disks = tfs.NumDisks();
        std::size_t disks = tfs().NumDisks();
    }
};

Directory& dir();

}

#endif // __EFFECTIVE_CPP_ITEM_03_H__
