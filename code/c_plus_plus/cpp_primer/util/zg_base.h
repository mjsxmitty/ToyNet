
#ifndef __CPP_PRIMER_ZGBASE_H__
#define __CPP_PRIMER_ZGBASE_H__


class ZGBase
{
    // 继承与静态成员
//private:
public:
    static void Statmem();
};

class ZGDerived : public ZGBase
{
public:
    void f(const ZGDerived &);
};

#endif // __CPP_PRIMER_ZGBASE_H__
