

#include "chapter_02.h"
#include <iostream>

using namespace std;

void ch_02()
{
    /* 2.1 基本内置类型 */
    //ch_2_1();

    /* 2.2 变量 */
    //ch_2_2();

    /* 2.3 复合类型 */
    ch_2_3();
}

/********************************************************************************/
/*****************************************2.1************************************/

/* 基本内置类型 */
void ch_2_1()
{
    /* 2.1.1 算数类型 */

    /* 2.1.2 类型转换 */
    ch_2_1_2();

    /* 2.1.3 字面值常量 */
}

void ch_2_1_2()
{
    bool    b = 42;
    int     i = b;
    i = 3.14;
    double  pi = i;
    cout << "b = " << b << "\n"
         << "i = " << i << "\n"
         << "pi = " << pi << "\n"
         << endl;

    cout << "each type size: " << endl;
    cout << "b: " << sizeof (b) << "\n"
         << "i: " << sizeof (i) << "\n"
         << "pi: " << sizeof (pi) << "\n"
         << endl;

    //TODO:赋给无（有）符号类型超范围值？？？
    unsigned char   c = -1;
    signed char     c2 = 256;
    cout << "c = " << c << "\n"
         << "c2 = " << c2 << "\n";
}

/********************************************************************************/
/*****************************************2.2************************************/

void ch_2_2()
{
    /* 2.2.1 变量定义 */
    ch_2_2_1();

    /* 2.2.2 变量声明和定义的关系 */
    ch_2_2_2();

    /* 2.2.3 标识符 */

    /* 2.2.4 名字的作用域 */
    ch_2_2_4();
}

void ch_2_2_1()
{
    /* 列表初始化 */
    int units_sold = 0;
    int units_sold2 = {0};
    int units_sold3{0};
    int units_sold4(0);

    double ld = 3.1415926;

    // int a{ld};        //丢失风险
    // int b = {ld};
    int c(ld);
    int d = ld;
    cout << "ld = " << ld << endl;
    cout << "c = " << c 
         << ", d = " << d
         << endl;
}

extern int init1 = 1;   // 定义
extern int init2;       // 声明
int init2 = 2;          // 定义
int init3 = 3;
void ch_2_2_2()
{
    //extern int init = 2;  // 函数内部初始化extern变量报错

    extern int init2;       // 可以声明多次
    init2 = 1;
    cout << "init2 = " << init2 << endl;

    int init3 = 2;          // 屏蔽外界定义
    cout << "init3 = " << init3 << endl;
}                                                                                                                                           

int reused = 1024;
void ch_2_2_4()
{
    // 内部可以使用外边变量
    cout << reused << endl;

    // 内部同名变量屏蔽外部变量
    int reused = 0;           // 重定义
    cout << reused << endl;

    // 指定使用外部变量
    cout << ::reused << endl;
}

/********************************************************************************/
/*****************************************2.3************************************/

void ch_2_3()
{
    /* 2.3.1 引用 */

    /* 2.3.2 指针 */
    ch_2_3_2();
}

#include <cstdlib>

void ch_2_3_2()
{
    /* 空指针 */
    int val = 0;
    //int *ptr = val;       // 类型不一致

    int *ptr1 = 0;
    int *ptr2 = nullptr;
    int *ptr3 = NULL;

    /* void* 指针 */
    double obj = 3.14, *pd = &obj;
    void *pv = &obj;
    pv = pd;                // 可以指向其他类型
    //pd = pv;
    //*pv = 3.333;          // 不能访问数据
    if (pv < pd)            // 可以比较
        ;
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



