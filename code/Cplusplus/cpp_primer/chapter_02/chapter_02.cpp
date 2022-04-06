

#include "chapter_02.h"
#include <iostream>

using namespace std;

void Chapter_02()
{
    //Practice_2_1_2();
    //Practice_2_2_1();
    //Practice_2_2_2();
    //Practice_2_2_4();
    //Practice_2_3_2();
    //Practice_2_3_3();
    //Practice_2_5_1();
    //Practice_2_5_3();

    Homework_2_35();
}

/* 内置类型类型转换 */
void Practice_2_1_2()
{
    int i = 42;
    std::cout << i << std::endl;
    if (i)          //int-->bool
        i = 0;
    std::cout << i << std::endl;

    bool b = 42;    //int-->bool
    std::cout << b << std::endl;

    int j = b;      //bool-->int
    std::cout << j << std::endl;

    double pi = 3.14;
    j = pi;        //double-->int
    std::cout << j << std::endl;

    unsigned char c = -1;
    i = c;
    std::cout << i << std::endl;
}

/* 字面值就是数据 */

/*内置类型列表初始化*/
void Practice_2_2_1()
{
    int v1(1024);
    int v2{1024};   //c++ 11
    int v3 = 1024;  //拷贝初始化      

    //此时aa赋值给cc表示的是aa的值可能超过范围，报警
    //const double aa = 12.34;
    //int cc{aa};

    double v4{33.43};       //不存在丢失信息的风险;同类型转换
    //int v4 = {1024.12};   //丢失信息风险（类型的范围超过最大值）
}

/*函数内部初始化extern变量报错*/
extern int init = 2;    //定义
extern int init;        //声明
void Practice_2_2_2()
{
    //extern int init = 2;
}

/*名字的作用域*/
int g_reused = 42;
void Practice_2_2_4()
{
    //内部可以使用外边变量
    std::cout << g_reused << std::endl;

    //内部同名变量屏蔽外部变量
    int g_reused = 0;
    std::cout << g_reused << std::endl;

    //指定是用外部变量
    std::cout << ::g_reused << std::endl;
}

void Practice_2_3_2()
{
    /* 类型不一致 */
    int val = 0;
    //int *ptr = val;

    int *ptr = 0;
    int *pptr = nullptr;
    int *ppptr = NULL;
}

/* 复合类型声明 */
void Practice_2_3_3()
{
    //多级指针
    int ival = 1024;
    int *pi = &ival;
    int **ppi = &pi;
    cout << "The value of ival\n"
         << "direct value: " << ival << "\n"
         << "indirect value: " << *pi << "\n"
         << "doubly indirect value: " << **ppi
         << endl;

    int i = 2;
    int *p1 = &i;
    *p1 = *p1 * *p1;
    cout << "i  = " << i << endl;

    *p1 *= *p1;
    cout << "i  = " << i << endl;

    /* 对指针的引用 */
    int val = 42, val2 = 0, *ptr = &val;
    int *&pref = ptr;
    cout << "val: " << *pref << endl;

    pref = &val2;
    cout << "val2: " << *pref << endl;
}

int         g_ival = 2;
const int   g_jval = 3;
int GetSize(int i) {
    return i;
}

constexpr int GetSize() {return 1000;}

/* constexptr 和常量表达式 */
void Practice_2_4_4()
{
    int i = 1;
    const int ci = i;
    //int iarray[ci] = {0};

    /* constexptr 修饰的变量是常量表达式 */
    constexpr int j = 2;
    int jarray[j] = {0};

    int iii = 1000;
    //constexpr int ci = iii;
    const int ti = 20;
    constexpr int cci = ti;

    //constexpr int sz = GetSize(iii);
    constexpr int sz = GetSize();

    /* constexpr 修饰指针需要指向固定地址、nullptr、0 */
    //constexpr int *ptr = &i;
    constexpr int *iptr = &g_ival; /* 指向非常量 */
    *iptr = 100;    /* constexptr 修饰的指针,仅对指针有效 */

    constexpr const int *jptr = &g_jval;     /* 指向常量 */
}

/* 类型别名 */
void Practice_2_5_1()
{
    char c = 'a';
    char temp = 't';
    typedef char *pstring;

    //const此时修饰的是指针（常量指针）
    const pstring cstr = &c;
    //cstr = &temp;    
    *cstr = 'b';
    cout << "val: " << *cstr << endl;

    //ps是一个指针(*ps),指向一个const常量指针（pstring）
    const pstring *ps = &cstr;
    cout << "val: " << **ps << endl;

    char *cptr = &c;
    pstring *pstr = &cptr;
    pstring ppp = cptr;
    **pstr = 'b';
    cout << "val: " << **pstr << endl;
}

/* auto 类型说明符 */
void Practice_2_5_2()
{
    /* 声明多个变量,其基本类型要保持一致 */
    auto i = 0, *pi = &i;
    //auto c = 'a', b = 3.123;

    /* 复合类型、常量和auto */
    //使用引用对象的类型
    int &r = i;
    auto a = r;     //int

    //常量和引用
    const int ci = i, &cr = ci;
    auto b = ci;    //int
    b = 10;
    auto c = cr;    // auto 忽略顶层const
    auto d = &i;    // int *
    *d = 10;
    auto e = &ci;   // const int*
    //*e = 1;
    e = &i;

    const auto ca = ci; //明确指出const类型
    //ca = 1;

    auto &g = ci;   //const引用保留顶层属性
    //g = 10;
    //auto &h = 42;
    const auto &j = 42;

    auto k = ci, &l = i;
    auto &m = ci, *n = &ci;
    //auto &o = i, *pp = &ci;   //*、&属于声明符;多个变量要保持基本类型一致
}

void Homework_2_35()
{
    const int i = 32;
    const auto &k = i;
    //k = 1;
    const auto j = i, &k2 = i;
    //  k2 = 3;

    cout << typeid(i).name() << endl;
    cout << typeid(k).name() << endl;
    cout << typeid(j).name() << endl;
    cout << typeid(k2).name() << endl;
}

/*decltype类型推导*/
void Practice_2_5_3()
{
    int a = 0;
    decltype(a) c = a;
    decltype((a)) d = a;
    ++c;
    cout << "a: " << a << " c: " << c << " d: " << d << endl;
    ++d;
    cout << "a: " << a << " c: " << c << " d: " << d << endl;

    int A = 0, B = 0;
    decltype((A)) C = A;
    decltype(A = B) D = A;
    ++C;
    cout << "A: " << A << " C: " << C << " D: " << D << endl;
    ++D;
    cout << "A: " << A << " C: " << C << " D: " << D << endl;
}

