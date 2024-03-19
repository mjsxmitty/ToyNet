
#include <iostream>

using namespace std;

int main1()
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
    // signed char     c2 = 256;
    // cout << "c = " << c << "\n"
    //      << "c2 = " << c2 << "\n";

    return 0;
}

int main2()
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

    return 0;
}

extern int init1 = 1;   // 定义
extern int init2;       // 声明
int init2 = 2;          // 定义
int init3 = 3;
int main3()
{
    //extern int init = 2;  // 函数内部初始化extern变量报错

    extern int init2;       // 可以声明多次
    cout << "init2 = " << init2 << endl;
    init2 = 1;
    cout << "init2 = " << init2 << endl;

    int init3 = 2;          // 屏蔽外界定义
    cout << "init3 = " << init3 << endl;

    return 0;
}                                                                                                                                           

int reused = 1024;
int main4()
{
    // 内部可以使用外边变量
    cout << reused << endl;

    // 内部同名变量屏蔽外部变量
    int reused = 0;           // 重定义
    cout << reused << endl;

    // 指定使用外部变量
    cout << ::reused << endl;
    return 0;
}

#include <cstdlib>

int main5()
{
    /* 空指针 */
#if 0
    int val = 0;
    //int *ptr = val;       // 类型不一致
#endif

#if 0
    int *ptr1 = 0;
    int *ptr2 = nullptr;
    int *ptr3 = NULL;

    int zero = 0;
    //int *ptr4 = zero;
#endif

    /* 其他指针操作 */
#if 0
    int ival = 1024;
    int *pi = 0;
    int *pi2 = &ival;

    if (pi)
        cout << "pi is empty!" << endl;
    if (pi2)
        cout << "pi is empty!" << endl;

    //
    //pi2 = 0;
    //pi = &ival;
    cout << "pi = " << pi << ", pi2 = " << pi2 << endl;
    pi = &ival + 1;
    pi2 += 1;
    cout << "pi = " << pi << ", pi2 = " << pi2 << endl;
    if (pi == pi2)
        cout << "pi equal tp pi2." << endl;
#endif

    /* void* 指针 */
#if 1
    double obj = 3.14, *pd = &obj;
    void *pv = &obj;
    pv = pd;                            // 可以指向其他类型
    //pd = pv;
    //*pv = 3.333;                      // 不能访问数据
    cout << (pv < pd ? "pv" : "pb");    // 可以比较
#endif

    return 0;
}

int main6()
{
    /* 指向指针的指针 */
#if 0
    int ival = 1024;
    int *pi = &ival;
    int **ppi = &pi;
    cout << "The value of ival\n"
         << "direct value: " << ival << "\n"
         << "indirect value: " << *pi << "\n"
         << "doubly indirect value: " << **ppi
         << endl;
#endif

#if 0
    int i = 2;
    int *p1 = &i;
    *p1 = *p1 * *p1;
    cout << "i  = " << i << endl;

    *p1 *= *p1;
    cout << "i  = " << i << endl;
#endif

    /* 指向指针的引用 */
    {
        int val = 1024, val2 = 0, *ptr = &val;
        int *&pref = ptr;       //从右向左理解声明
        cout << "*pref: " << *pref << endl;

        pref = &val2;
        cout << "*pref: " << *pref << endl;
    }

    return 0;
}

int main7()
{
#if 0
    const int ci = 1024;
    const int &rci = ci;
    //int &ri = ci;
    //rci = 1025;
#endif

    /* 初始化和对const的引用 */
#if 0
    int i = 1024;
    const int &r1 = i;          // 普通变量
    const int &r2 = 1024;       // 字面值
    const int &r3 = i * 1024;   // 算数表达式
    //int &r4 = i * 1024;
#endif

#if 0
    double dval = 3.14;
    const int &rd = dval;       // 绑定临时变量
    /*
    const int temp = dval;
    const int &rd = temp;
        */
#endif

    /* const引用可能是一个非const对象 */
#if 0
    int i = 1024;
    int &r1 = i;
    const int &r2 = i;

    r1 = 0;
    //r2 = 0;
#endif

    return 0;
}

int main8()
{
#if 0
    const double cd = 3.14;
    //double *pd = &cd;
    const double *pcd = &cd;
    //*pcd = 0.0;

    double dval = 3.33;
    pcd = &dval;
#endif

    /* const 指针 */
#if 0
    int err_numb = 0;
    int * const cur_err = &err_numb;
    *cur_err = 1024;
    int err_numb2 = 1024;
    //cur_err = &err_numb2;

    const double pi = 3.14;
    const double * const pip = &pi;
    //*pip = 0.0;
#endif

    return 0;
}

int main9()
{
    int i = 0;
    int * const p1 = &i;
    const int ci = 0;
    const int *p2 = &ci;
    const int *const p3 = p2;

    // 拷贝的时候顶层属性不受影响
    i = ci;
    p2 = p3;            // 都含有底层属性
    //p1 = p3;

    //int *p = p3;      // 包含底层属性
    int *p = p1;        // 不包含底层属性,可以赋值
    p2 = &ci;
    p2 = &i;            // int* ---> const int*

    //int &ri = ci;
    const int &rci = ci;

    return 0;
}

int         g_ival = 2;
const int   g_jval = 3;

int             GetSize(int i) { return i; }
constexpr int   GetSize() {return 1000;}

int main10()
{
    // 常量表达式是由类型和初始值决定
#if 0
    const int max_files = 1023;
    const int limit = max_files + 1;

    int staff_size = 27;
    const int sz = GetSize(staff_size);
    //int iarray[sz] = {0};

    int i = 1;
    const int ci = i;   //不是常量表达式
    //int iarray[ci] = {0};
#endif

    /* constexptr 变量 */
#if 0
    constexpr int mf = 1021;
    constexpr int limit = mf + 1;
    constexpr int sz = GetSize();

    constexpr int j = 2;
    int jarray[j] = {0};

    int ival = 1000;
    //constexpr int ci = ival;
    const int cval = 20;
    constexpr int ci = cval;

    constexpr int ccci = cval + 1;
    //constexpr int cccci = ival + 1;

    const int ival2 = 10;
    constexpr int icc = ival2 + 1;

    //constexpr int sz2 = GetSize(ival);
    //constexpr int sz3 = GetSize(ival2);
#endif

    /* 字面值类型 */
# if 0
    int i = 1024;
    //constexpr int *ptr = &i;
    constexpr int *iptr = &g_ival;
#endif

    /* 指针和constexptr */
# if 1
    const int *p = nullptr;
    p = &g_ival;
    constexpr int *q = nullptr;
    //q = &g_jval;
    *q = 1024;

    // 只能指向固定地址
    constexpr int *iptr = &g_ival;
    *iptr = 100;
    constexpr const int *jptr = &g_jval;
    constexpr const int *jptr2 = &g_ival;

    //constexpr int i = 1024;
    //constexpr int *pi = &i;
#endif

    return 0;
}

int main11()
{
#if 0
    typedef double wages;
    typedef wages base, *p;

    base dval = 3.14;
    p pd = &dval;
    cout << dval << ", " << *pd << endl;

    using Int = int;
    Int ival = 1024;
    cout << ival << endl;

    using ptrd = double *;
    ptrd pdd = &dval;
#endif

    /* 指针、常量和类型别名 */
#if 0
    typedef char *pchar;

    char ch1 = 'a';
    char ch2 = 'b';

    pchar pc = &ch1;
    pc = &ch2;
    *pc = 'c';

    const pchar cpc = &ch1;
    //cpc = &ch2;
    *cpc = 'd';

    pchar pc2 = &ch2;
    pchar *pcp = &pc;
    pcp = &pc2;
    *pcp = &ch1;
    **pcp = 'e';

    const pchar *cpcp = &pc2;
    cpcp = &pc;
    **cpcp = 'f';
    //*cpcp = &pcp;

    char *cptr = &ch1;
    pchar *pstr = &cptr;

    pchar pstr2 = cptr;
    **pstr = 'e';
#endif

    return 0;
}

int main12()
{
#if 0
    auto i = 0, *pi = &i;
    //auto c = 'a', b = 3.123;
#endif

    /* 复合类型、常量和auto */
# if 1
    int i = 1024, &r = i;
    auto a = r;                     //int
    cout << "a = " << a << endl;

    //常量和引用
    const int ci = i, &cr = ci;
    auto b = ci;                    //int
    b = 1;
    cout << "b = " << b << endl;

    auto c = cr;                    // auto 忽略顶层const(ci)
    c = 2;
    cout << "c = " << c << endl;

    auto d = &i;                    // int *
    *d = 3;
    cout << "d = " << d << endl;

    auto e = &ci;                   // const int*(底层)
    //*e = 1;
    e = &i;
    cout << "e = " << e << endl;

    const auto f = ci;              // 明确指出const类型
    //f = 1;
    cout << "f = " << f << endl;

    auto &g = ci;                   //const引用保留顶层属性
    //g = 10;
    cout << "g = " << g << endl;

    //auto &h = 42;

    const auto &j = 42;
    //j = 0;
    cout << "j = " << j << endl;

    //*、&属于声明符;多个变量要保持基本类型一致
    auto k = ci, &l = i;        // int
    auto &m = ci, *n = &ci;     // const int
    //auto &o = i, *pp = &ci;
#endif

    return 0;
}

void hw_2_35()
{
    const int i = 1024;
    auto j = i;
    j = 0;

    auto &w = i;
    //w = 0;

    const auto &k = i;  // const int
    //k = 1;

    auto *p = &i;
    //*p = 0;
    p = &j;

    const auto j2 = i, &k2 = i;
    //j2 = 0;
    //k2 = 3;

    auto &k3 = i;

    cout << typeid(i).name() << endl;
    cout << typeid(j).name() << endl;
    cout << typeid(k).name() << endl;
    cout << typeid(p).name() << endl;
    cout << typeid(k2).name() << endl;
    cout << typeid(k3).name() << endl;
}

int main()
{
#if 0
    const int ci = 1, &cj = ci;
    decltype (ci) x = 0;
    //x = 1;

    decltype (cj) y = ci;
    //y = 101;
    // decltype (cj) z;
#endif

    /* decltype 和 引用 */
#if 0
    int i = 1024, *p = &i, &r = i;
    decltype (r) a = i;
    a = 1;
    cout << "i = " << i << ", a = " << a << endl;

    decltype (r + 0) b;
    b = 2;
    cout << "i = " << i << ", b = " << b << endl;

    //decltype (*p) c;
    decltype (*p) c = i;
    c = 3;
    cout << "i = " << i << ", c = " << c << endl;
#endif

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

    return 0;
}

void hw_2_36()
{
    int a = 3, b = 4;
    decltype (a) c = a;
    decltype ((b)) d = a;
    ++c;
    ++d;
    cout << "a = " << a  << endl//4
         << "b = " << b  << endl//4
         << "c = " << c  << endl//4
         << "d = " << d  << endl//4
         << endl;
}

void hw_2_37()
{
    int a = 3, b = 4;
    decltype (a = b) c = a;
    decltype ((b)) d = a;
    ++c;
    ++d;
    cout << "a = " << a  << endl
         << "b = " << b  << endl
         << "c = " << c  << endl
         << "d = " << d  << endl
         << endl;
}

