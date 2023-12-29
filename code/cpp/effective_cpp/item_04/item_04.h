

#ifndef __EFFECTIVE_CPP_ITEM_04_H__
#define __EFFECTIVE_CPP_ITEM_04_H__

#include <string>
#include <list>
#include <iostream>

class PhoneNumber{};
class ABEntry
{
public:
    // 
    ABEntry() : the_name_(), the_address_(), the_phones_()//, num_times_consulted_(0)
    {
        InitNumTimesConsulted(0);
    }

    // 
    ABEntry(const std::string &name, const std::string &addr,
            const std::list<PhoneNumber> &phones, int num_times_consulted)
        : the_name_(name), the_address_(addr), the_phones_(phones)//, num_times_consulted_(0)
    {
        InitNumTimesConsulted(num_times_consulted);
    }
private:
    // 多个构造函数共有,与初始化表现一样好
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

// 
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

#endif // __EFFECTIVE_CPP_ITEM_04_H__
