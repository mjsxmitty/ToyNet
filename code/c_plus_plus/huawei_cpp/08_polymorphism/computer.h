

#ifndef __HUAWEI_CHAPTER_08_POLYMORPHISM_COMPUTER_H__
#define __HUAWEI_CHAPTER_08_POLYMORPHISM_COMPUTER_H__
#include <iostream>
using namespace std;
class HardDisk
{
public:
    virtual void run() = 0;
    virtual ~HardDisk(){}
};
class Memory
{
public:
    virtual void run() = 0;
    virtual ~Memory(){}
};
class Cpu
{
public:
    virtual void run() =0 ;
    virtual ~Cpu(){}
};

class WDHardDisk:public HardDisk
{
public:
    void run()
    {
        cout<<"我是西数硬盘，500g 5400r/m"<<endl;
    }
};
class IntelCpu:public Cpu
{
public:
    void run()
    {
        cout<<"我是 intel Cpu,3.4gh "<<endl;
    }
};
class kingStonMem:public Memory
{
public:
    void run()
    {
        cout<<"我是金士顿内存，16g 1333"<<endl;
    }
};

class Computer
{
public:
    Computer(Cpu *c, Memory *m, HardDisk *d) :
        disk(d), mem(m), cpu(c) {}
public:
    void Work();
private:
    HardDisk    *disk;
    Memory      *mem;
    Cpu         *cpu;
};

#endif // __HUAWEI_CHAPTER_08_POLYMORPHISM_COMPUTER_H__
