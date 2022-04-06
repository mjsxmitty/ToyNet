

#ifndef __MY_DELEGATION_H__
#define __MY_DELEGATION_H__

namespace stank{

class StringRep
{
private:
    int     count;
    char    *rep;
public:
    StringRep(/* args */);
    ~StringRep();
};



//接口可以不改变，指向的类实现内容发生变化
//编译防火墙
class String
{
private:
    StringRep   *rep;
public:
    String(/* args */);
    ~String();
};


}





#endif //
