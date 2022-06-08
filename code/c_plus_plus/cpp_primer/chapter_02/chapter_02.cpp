

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

    //Homework_2_35();
}

/* 内置类型类型转换 */
void Practice_2_1_2()
{
//    int i = 42;
//    std::cout << i << std::endl;
//    if (i)          //int-->bool
//        i = 0;
//    std::cout << i << std::endl;

//    bool b = 42;    //int-->bool
//    std::cout << b << std::endl;

//    int j = b;      //bool-->int
//    std::cout << j << std::endl;

//    double pi = 3.14;
//    j = pi;        //double-->int
//    std::cout << j << std::endl;

//    unsigned char c = -1;
//    i = c;
//    std::cout << i << std::endl;

    bool    b = 42;
    int     i = b;
    i = 3.14;
    double  pi = i;

    //TODO:赋给无（有）符号类型超范围值？？？
    unsigned char   c = -1;
    signed char     c2 = 256;
    cout << "c = " << c
         << "c2 = " << c2
         << endl;
}

/* 字面值就是数据 */

/*内置类型列表初始化*/
void Practice_2_2_1()
{
    int v1(1024);
    int v2{1024};   //c++ 11
    int v3 = 1024;  //拷贝初始化      

    //此时aa赋值给cc表示的是aa的值可能超过范围，报警
    const double aa = 12.34;
    //int cc{aa};

    double v4{33.43};       //不存在丢失信息的风险;同类型转换
    //int v4 = {1024.12};   //丢失信息风险（类型的范围超过最大值）
    int v5(3.14);           //丢失信息
}

extern int init = 2;    //定义
extern int initt;       //声明
int initt = 111;        //定义
void Practice_2_2_2()
{
    /* 函数内部初始化extern变量报错 */
    //extern int init = 2;
    
    //int initt = 2;
    initt = 1;

    extern int initt;   //可以声明多次
    cout << initt << endl;
}

/*名字的作用域*/
int g_reused = 42;
void Practice_2_2_4()
{
    //内部可以使用外边变量
    std::cout << g_reused << std::endl;

    //内部同名变量屏蔽外部变量
    //重定义
    int g_reused = 0;
    std::cout << g_reused << std::endl;

    //指定使用外部变量
    std::cout << ::g_reused << std::endl;
}

#include <cstdlib>

void Practice_2_3_2()
{
    /* 类型不一致 */
    int val = 0;
    //int *ptr = val;

    //空指针初始化方法
    int *ptr = 0;
    int *pptr = nullptr;
    int *ppptr = NULL;

    //void* 指针
    double obj = 3.14, *pd = &obj;
    void *pv = &obj;
    pv = pd;        //可以指向其他类型
    //pd = pv;
    //*pv = 3.333;  //不能访问数据
    if (pv < pd)
        ;

    cout << "true "  << pv
         << ", " << pd << endl;
}

/* 复合类型声明 */
void Practice_2_3_3()
{
    /* 多级指针 */
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

    /* 指向指针的引用 */
    int val = 42, val2 = 0, *ptr = &val;
    int *&pref = ptr;       //从右向左理解声明
    cout << "val: " << *pref << endl;

    pref = &val2;
    cout << "val2: " << *pref << endl;
}

/* const的引用 */
void practice_2_4_1()
{
    const int ci = 1024;
    //int &ri = ci;
    const int &rci = ci;
    //rci = 1025;

    /* 初始化和对const的引用 */
    int i = 1024;
    const int &r1 = i;  //const 的引用可能是一个非const对象
    const int &r2 = 1024;
    const int &r3 = i * 1024;
    //int &r4 = i * 1024;

    double dval = 3.14;
    const int &rd = dval;   //绑定临时变量
//    int temp = dval;
//    const int &rd = temp;
}

/* 指针和const */
void practice_2_4_2()
{
    const double cd = 3.14;
    //double *pd = &cd;
    const double *pcd = &cd;
    //*pcd = 3.125;

    double dval = 3.33;
    pcd = &dval;

    int i = 0;
    int * const cpi = &i;
    *cpi = 1024;
//    int i2 = 0;
//    cpi = &i2;

    const double *const cpdc = &cd;
//    *cpdc = 3.22;
//    cpdc + &dval;
}

/* 顶层const */
void practice_2_4_3()
{
    int i = 0;
    int * const p1 = &i;
    const int ci = 0;
    const int *p2 = &ci;
    const int *const p3 = p2;

    //拷贝的时候顶层属性不受影响
    i = ci;
    p2 = p3;    //都含有底层属性
    //p1 = p3;

    //int *p = p2;    //包含底层属性
    int *p = p1;        //不包含底层属性,可以赋值
    p2 = &ci;   //int * ---> const int *

    //int &ri = ci;
    const int &rci = ci;
}

int         g_ival = 2;
const int   g_jval = 3;

int GetSize(int i) { return i; }
constexpr int GetSize() {return 1000;}

/* constexptr 和常量表达式 */
void Practice_2_4_4()
{
    /* 常量表达式是由类型和初始值决定 */
    int i = 1;
    const int ci = i;   //不是常量表达式
    //int iarray[ci] = {0};

    /* constexptr 修饰的变量是常量表达式 */
    constexpr int j = 2;
    int jarray[j] = {0};

    /* 必须使用常量表达式初始化 */
    int iii = 1000;
    //constexpr int ci = iii;
    const int ti = 20;
    constexpr int cci = ti;
//    constexpr int ccci = ci + 1;
//    constexpr int cccci = i + 1;
    const int ic = 10;
    constexpr int icc = ic + 1;

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
    const char ch = 'c';
    const pstring *ps = &cstr;
    //ps = &ch;
    const pstring ccstr = &temp;
    ps = &ccstr;
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
    int &r = i;
    auto a = r;     //int

    //常量和引用
    const int ci = i, &cr = ci;
    auto b = ci;    //int
    b = 10;

    auto c = cr;    // auto 忽略顶层const(ci)

    auto d = &i;    // int *
    *d = 10;

    auto e = &ci;   // const int*(底层)
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

/* decltype类型推导 */
void Practice_2_5_3()
{
    const int ci = 1, &cj = ci;
    decltype (ci) x = 0;
    //x = 1;

    decltype (cj) y = ci;
    //y = 101;
    cout << cj << endl;

    int i = 100, &ri = i;
    decltype (ri) xxx = ri;
    xxx = 101;
    cout << "xxx = " << xxx << ", "
         << "i = " << i
         << endl;

    int *p = &i;
    decltype (*p) ccc = i;  //解引用 ---> 引用 --->必须初始化
    ccc = 110;
    cout << "xxx = " << ccc << ", "
         << "i = " << i
         << endl;

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



