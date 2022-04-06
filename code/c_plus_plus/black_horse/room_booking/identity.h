

#ifndef __IDENTITY_H__
#define __IDENTITY_H__

#include <string>


class Identity
{
public:
    std::string name_;
    std::string passwd_;
public:
    virtual void OperateMenu() = 0;
};





#endif //_IDENTITY_H__