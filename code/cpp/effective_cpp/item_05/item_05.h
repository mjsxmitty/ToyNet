
#ifndef __EFFECTIVE_CPP_ITEM_05_H__
#define __EFFECTIVE_CPP_ITEM_05_H__

#include <string>


template<typename T>
class NameObject
{
public:
    NameObject(std::string &name, const T &value) : name_value_(name), object_value_(value) {}
    //NameObject(const NameObject &lhs) : name_value_(lhs.name_value_), object_value_(lhs.object_value_){}
public:
    std::string &name_value_;
    const T     object_value_;
};

#endif // __EFFECTIVE_CPP_ITEM_05_H__
