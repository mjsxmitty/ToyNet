

#ifndef __BOSS_H__
#define __BOSS_H__

#include <string>

#include "worker.h"

class Boss : public Worker
{
public:
    Boss(int id, std::string name, int did);
    void ShowInfo() const;
    std::string GetDeptName() const;
};

#endif //__BOSS_H__




