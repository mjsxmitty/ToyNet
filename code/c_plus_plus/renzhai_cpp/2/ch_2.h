
#ifndef __GZ_CPP_CH_2_HPP__
#define __GZ_CPP_CH_2_HPP__

#include <iostream>
//#include <winerror.h>

using namespace std;

struct GZHello
{
    GZHello()
    {
        aa = new int;
    }

    ~GZHello()
    {
        if (aa)
        {
            delete aa;
            aa = NULL;
        }
    }

    int     a;
    int     b;
    float   c;
    float   d;
private:
    int     m;
    int     *aa;
public:
    void Hello()
    {
        a = 0;
        b = 0;

        HHH();  // ����˽�к���
    }

    static void SHello();
    inline int GetP() const { return p; }
private:
    void HHH() {}
    int p;
};

void GZHello::SHello(){}

class GZMonster
{
public:
    GZMonster();
    ~GZMonster();

    int a;
    int b;

    static int SHello() { return 4; }

    int Hello()
    {
        GZMonster::SHello();    // ���þ�̬��Ա
        return 4;
    }

    //FORCEINLINE int GetAA()const { return a; }
    inline int GetP() const { return p; }

private:
    int p;
};

inline int GetA()
{
    return 0;
}

int GHello()
{
    return 1 + 3;
}

GZMonster::GZMonster()
{
    int cc = ::GHello();    // ʹ��ȫ�ֳ�Ա
    cout << cc << endl;
}

GZMonster::~GZMonster(){}

class FWorkers //���� ����
{
public:
    void Work(){/*/...*/}
private:
    void Work1() {/*/...*/ }
protected:
    void Work3(){}
};

void ch_2();

#endif // __GZ_CPP_CH_2_HPP__
