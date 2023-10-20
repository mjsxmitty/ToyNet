
#include <string>

#include "chapter_07.h"
#include "../common/screen.h"
#include "../common/sales_data.h"

void ch_07()
{
    /* 类的其他特性 */
    //ch_7_3();

    /*构造函数再探*/
    ch_7_5();
}

void ch_7_3()
{
    /* 类成员再探 */
    //ch_7_3_1();

    /* 返回*this成员函数 */
    ch_7_3_2();
}

void ch_7_3_1()
{
    /* 重载成员函数 */
    {
        Screen my_screen(10,10);
        char ch = my_screen.Get();
        std::cout << ch << std::endl;

        ch = my_screen.Get(2, 3);
        std::cout << ch << std::endl;
    }

    /* 可变数据成员 */
    {
        Screen my_screen;
        my_screen.SomeNumber();
        std::cout << my_screen.GetAccessCtr() << std::endl;
        my_screen.SomeNumber();
        std::cout << my_screen.GetAccessCtr() << std::endl;
    }
}

void ch_7_3_2()
{
    {
        Screen my_screen;
        std::cout << my_screen.Get() << std::endl;
        my_screen.Move(1, 2).Set('*');
        std::cout << my_screen.Get() << std::endl;
    }

    /* 从const成员返回this */
    /* 基于const重载 */
    {
        Screen my_screen(3, 5);
        my_screen.Move(1,2).Set('#').Display(std::cout);
        std::cout << std::endl;

        const Screen my_cscreen(1, 2, '$');
        //my_cscreen.Display(std::cout).Set("*");
        my_cscreen.Display(std::cout);
    }
}

namespace chapter_07 {

/*7.3.4 友元再探*/

/*友元声明和作用域*/
//void f();
struct X
{
    friend void f() {}
    //X() { f(); }
    //void g();
    void h();
};

//void X::g() { return f(); }
void f();
void X::h() { return f(); }

};

void ch_7_5()
{
    /* 7.5.4 类型的隐式转换 */
    ch_7_5_4();

}

namespace chapter_07 {

/*7.5.1 构造函数初始值列表*/

/*构造函数初始值必不可少*/
class ConstRef
{
public:
#if 0
    ConstRef(int i)
    {
        ci = i;
        ri = i;
    }
#endif
    ConstRef(int i) : ci(i), ri(i) {}
private:
    const int   ci;
    int         ri;
};

/*成员初始化顺序*/
class x
{
public:
    //x(int val) : j(val), i(j) {}   //error
    x(int val) : i(val), j(val) {}     //尽可能用参数初始化
private:
    int i, j;
};

/*7.5.3 默认构造函数的作用*/
class NoDefault
{
public:
    NoDefault(int i){}
};

struct A
{
    NoDefault my_mem;
};

//A aaa;

struct B
{
    //B(){}
    NoDefault no;
};

class C
{
public:
    NoDefault nd;
    C(int i = 0) : nd(i){}
};


NoDefault no(1);
C cc;
C ccc(10);
//B bbb;
};

void ch_7_5_4()
{
    std::string null_book = "1-11-111-22";
    SalesData item;
    //item.Combine(null_book);                  //-->1

    //只允许一步转换
#if 0
    item.Combine("2-22-11-1111");
    item.Combine(string("1-11-1111-222"));    //-->2
    item.Combine(SalesData("111-222-111"));   //-->3
    item.Combine(cin);                        //-->4
    SalesData item2 = string("1111");         //-->5
#endif
#if 0
    加上explicit之后，抑制隐式转换，1,2,4,5不成立
    explicit只可以在函数声明处，单一参数的构造函数
    此时必须 显示调用转换函数（显示调用构造函数）
#endif
    item.Combine(static_cast<SalesData>(std::cin));
    item.Combine(static_cast<SalesData>(null_book));
}

void ch_7_6()
{
//    //使用静态成员
//    double r = Account::Rate();

//    Account::Rate(5);

//    Account ac1;
//    Account *ac2 = &ac1;
//    r = ac1.Rate();
//    r = ac2->Rate();
//    std::cout << "interest rate: " << r << std::endl;
}


constexpr double Example::rate;
const int Example::vec_size;
const std::vector<int> Example::ivec(vec_size);
//constexpr ???

void Homework_7_58()
{
    std::cout << Example::rate << ", " << Example::vec_size << std::endl;
}
