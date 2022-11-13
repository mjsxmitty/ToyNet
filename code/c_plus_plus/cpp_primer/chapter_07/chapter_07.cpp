
#include <string>

#include "chapter_07.h"
#include "../common/gz_screen.h"
#include "../common/gz_sales_data.h"

//#include "../lib_common/account.h"
//#include "../lib_common/sales_data.h"
//#include "../lib_common/screen.h"

using namespace std;

void ch_07()
{
    /* 类的其他特性 */
    ch_7_3();
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
        GZScreen my_screen;
        char ch = my_screen.Get();
        cout << ch << endl;
        //ch = my_screen.Get(i, j);
        cout << ch << endl;
    }

    {
        GZScreen my_screen;
        my_screen.SomeNumber();
        cout << my_screen.GetAccessCtr() << endl;
        my_screen.SomeNumber();
        cout << my_screen.GetAccessCtr() << endl;
    }
}

void ch_7_3_2()
{
    {
        GZScreen my_screen;
        cout << my_screen.Get() << endl;
        //my_screen.Move(1, 2).Set('*');
        cout << my_screen.Get() << endl;
    }

    {
        GZScreen my_screen(3, 5);
        const GZScreen my_cscreen(1, 2);
        my_screen.Set('#').Display(cout);
        cout << endl;
        //my_cscreen.Display(cout).set("*");
        my_cscreen.Display(cout);
    }
}

// 友元声明和作用域
struct GZX
{
    friend void f() {}
    //GZX() { f(); }

    void g();
    void h();
};

//void GZX::g() { return f(); }
void f();
void GZX::h() { return f(); }

typedef double Money;
class Acc
{
    //typedef int Money;  //未被使用 ---> 正确
public:
    Money balance() {return bal;}
private:
    /* 7-4-1 名字查找与类的作用域 */
    //已使用不可以重新定义
    //编译器不做检查,不报错
    //typedef int Money;
    Money bal;
};


/*****************************************************************/



NoDefault no(1);
C cc;
C ccc(10);
//B bbb;

/* 7-5-4 类型的隐式转换 */
void ch_7_5_4()
{
    string null_book = "1-11-111-22";
    GZSalesData item;
    //item.Combine(null_book);                  //-->1

    //只允许一步转换
    //item.Combine("2-22-11-1111");
    //item.Combine(string("1-11-1111-222"));    //-->2
    //item.Combine(GZSalesData("111-222-111"));     //-->3
    //item.Combine(cin);                        //-->4
    //SalesData item2 = string("1111");         //-->5

    //加上explicit之后，抑制隐式转换，1，2，4,5不成立
    //explicit只可以在函数声明处，单一参数的构造函数
    //此时必须 显示调用转换函数（显示调用构造函数）
    item.Combine(static_cast<GZSalesData>(cin));
    item.Combine(static_cast<GZSalesData>(null_book));
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
//    cout << "interest rate: " << r << endl;
}


constexpr double Example::rate;
const int Example::vec_size;
const std::vector<int> Example::ivec(vec_size);
//constexpr ???

void Homework_7_58()
{
    cout << Example::rate << ", " << Example::vec_size << endl;
}
