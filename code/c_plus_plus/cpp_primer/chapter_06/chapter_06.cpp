

#include "chapter_06.h"
#include "local_math.h"

#include <iostream>
#include <vector>
#include <initializer_list>
#include <cassert>

using namespace std;

void ch_06()
{
    /* 函数基础 */
    //ch_6_1();
    
    /* 参数传递 */
    //ch_6_2();

    /* 返回类型和return语句 */
    //ch_6_3();

    /* 特殊特性语言用途 */
    //ch_6_5();

    /* 函数指针 */
    ch_6_7();
}

/* 编写函数 */
int fact(int val)
{
    int ret = 1;
    while (val > 1)
        ret *= val--;

    return ret;
}

void ch_6_1()
{
    {
        /* 调用函数 */
        int j = fact(5);
        cout << "5! is "<< j << endl;
    }

    /* 局部静态函数 */
    ch_6_1_1();

    /* 离式编译,函数调用，递归(6-1-1) */
    ch_6_1_3();
}

size_t FuncCalls()
{
    static size_t cnt = 0;
    return ++cnt;
}


void ch_6_1_1()
{
    for (size_t i = 0; i != 10; ++i)
        cout << FuncCalls() << endl;
}

void ch_6_1_3()
{
	cout << Factorial(5) << endl;
	cout << Fact(5) << endl;
	cout << Factorial(0) << endl;
	cout << Fact(0) << endl;
}

void ch_6_2()
{
    /* 传引用参数 */
    ch_6_2_2();

    /* 数组形参 */
    ch_6_2_4();

    /* 含有可变参数列表 */
    ch_6_2_6();
}

/* 使用引用返回额外消息 */
string::size_type FindChar(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;

    for (decltype (ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size())    //判断是不是第一次查找到
                ret = i;
            ++occurs;
        }
    }

    return ret;
}

vector<int>::const_iterator FindChar(
    vector<int>::const_iterator beg,
    vector<int>::const_iterator end,
    int val, string::size_type &occurs)
{
    auto res_iter = end;
    occurs = 0;

    for ( ; beg != end; ++beg)
    {
        if (*beg == val)
        {
            if (res_iter == end)
                res_iter = beg;
            ++occurs;
        }
    }

    return res_iter;       
}

void ch_6_2_2()
{
    string s;
    getline(cin, s);

    size_t ctr = 0;
    auto index = FindChar(s, 'o', ctr);
    cout << index << " " << ctr << endl;

//	vector<int> ivec;
//	int i;
//	while (cin >> i)
//		ivec.push_back(i);

//    for (auto i : {43, 33, 92})
//    {
//        auto it = FindChar(ivec.begin(), ivec.end(), i, ctr);
//		if (it == ivec.end())
//			cout << i << " is not in the input data" << endl;
//		else
//			cout << i << " was at position " << it - ivec.begin() << endl;
//    }
}


void print(const int *cp)
{
    if (cp)
        while (*cp)
            cout << *cp++ << ' ';
}

void print(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << ' ';
}

void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
        cout << ia[i] << ' ';
}

void print(int (&ra)[10])
{
    for (auto &elem : ra)
        cout << elem << ' ';
}

void ch_6_2_4()
{
    int ia[] = {0,1,2,3,4,5,6,7,8,9};

    /* 使用标记指定数组长度 */
    print(ia);

    /* 使用标准库规范 */
    print(ia, ia + 10);

    /* 显示传递一个数组大小形参 */
    print(ia, 10);

    /* 数组引用形参 */
    print(ia);

    /* 传递多维数组 */
    {
        void print(int (*ra)[10], int rol_size);
        //void print(int ra[][10], int rol_size);
    }

    hw_6_33();
}

void ErrorMsg(ErrCode e, initializer_list<string> il)
{
    cout << e.Msg() << ": ";
    for (const auto &elem : il)
        cout << elem << " ";
    cout << endl;
}

void ErrorMsg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}

void ch_6_2_6()
{
    string expected = "description", actual = "some other case";
    ErrorMsg({"functionX", expected, actual});
    cout << endl;

    /* 序列值放在{}中 */
    ErrorMsg({"functionX", "okay"});
    cout << endl;

    /* 可变参数也可以有其他的参数 */
    ErrorMsg(ErrCode(1), {"functionX", expected, actual});
    cout << endl;

    ErrorMsg(ErrCode(0), {"functionX", "okay"});

    // TODO 省略符形参...
}

void PrintVec(const vector<int> &vec, unsigned index)
{
    unsigned sz = vec.size();
    if (!vec.empty() && index < sz)
    {
        cout << vec[index] << ' ';
        PrintVec(vec, ++index);
    }
}

void hw_6_33()
{
    int a[] = {1,3,5,7,9};
    vector<int> local_vec(std::begin(a), std::end(a));
    PrintVec(local_vec, 0);
}

void ch_6_3()
{
    /* 有返回值函数 */
    ch_6_3_2();
    
    /* 返回数组指针&引用的函数 */
    ch_6_3_3();
}

/*列表初始化返回值(c11)*/
vector<string> FunctionX()
{
    string expected = "description", actual = "some other case";
    if (expected.empty())
        return {};
    else if (expected == actual)
        return {"functionX", "okay"};
    else
        return {"functionX", expected, actual};
}

void ch_6_3_2()
{
    auto ret = FunctionX();
    for (auto i : ret)
        cout << i << " ";
    cout << endl;
}

/* 数组类型相关 */
int Arr[10];            // int  数组
int *pArr[10];          // int* 数组
int (*p)[10] = &Arr;    // 指向数组的指针 

/* 数组类型别名 */
//using arrT = int [5];
typedef int arrT[5];

/* 声明返回指向数组指针的函数 */
arrT*   Func(int i);                //类型别名
auto    Func(int i) -> int (*)[5];  //尾置类型
int     (*Func(int i))[5];          //直接声明

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

typedef decltype(odd) *arry_ptr;

int* ElemPtr(int i)
{
    return (i % 2) ? odd : even;
}

//arrT* Func(int i)
//auto Func(int i) -> int (*)[5]
//int (*Func(int i))[5]
//decltype(odd)* ArrPtr(int i)
arry_ptr ArrPtr(int i)
{
    return (i % 2) ? &odd : &even;
}

//arrT& ArrRef(int i);
//auto ArrRef(int i) -> int (&)[5];
//decltype (even)& ArrRef(int i);
int (&ArrRef(int i))[5]
{
    return (i % 2) ? odd : even;
}

void ch_6_3_3()
{
    int* p = ElemPtr(6);
    for (size_t i = 0; i < 5; ++i)
        cout << p[i] << ' ';
    cout << endl;

    //int (*arrP)[5] = ArrPtr(5);
    arrT* arrP = ArrPtr(5);
    for (size_t i = 0; i < 5; ++i)
        cout << (*arrP)[i] << ' ';
    cout << endl;

    int (&arrR)[5] = ArrRef(4);
    for (size_t i = 0; i < 5; ++i)
        cout << arrR[i] << ' ';
    cout << endl;

    arrT& pppp = ArrRef(6);
    for (size_t i = 0; i != 5; ++i)
    {
        cout << pppp[i] << ' ';
    }
    cout << endl;
}

void ch_6_5()
{
    /* 默认实参 */
    ch_6_5_1();

    /* 内联函数和constexptr函数 */
    ch_6_5_2();
}

typedef string::size_type sz;
//string Screen(sz ht = 24, sz wid = 80, char bkgrnd = ' ');
string Screen(sz ht, sz wid, char bkgrnd = ' ');
//string Screen(sz ht, sz wid, char bkgrnd = '*');  // error

string Screen(sz ht, sz wid = 80, char bkgrnd);
//string Screen(sz ht = 10, sz wid, char bkgrnd);
//string Screen(sz ht = 10, sz wid = 80, char bkgrnd);

sz wd = 111;
char def = '*';
sz ht() { return 123; }

string screen(sz p1 = ht(), sz p2 = wd, char p3 = def)
{
    cout << "para1: " << p1 << endl
         << "para2: " << p2 << endl
         << "para3: " << p3 << endl;
    
    return "";
}

void ch_6_5_1()
{

    /* 默认食材初始值 */
    screen(10);

    def = '#';
    //sz wd = 1;
    screen();
}

void ch_6_5_2()
{
    int Arr[Scale(2)] = {0};
    int i = 2;
    //int Arr2[Scale(i)] = {0};
}

#define NDEBUG

void ch_6_5_3()
{
    //assert(false);
    assert(true);
}

void ch_6_7()
{
    /* 使用函数指针 */
    {
        /*
        bool LengthCompare(const string &, const string &);
        bool (*pf)(const string &, const string &);

        pf = LengthCompare;
        pf = &LengthCompare;
        pf = 0;
        //bool ret1 = pf("hello", "nihao");
        //bool ret2 = (*pf)("hello", "nihao");
        //bool ret3 = LengthCompare("hello", "nihao");

        string::size_type SumLength(const string &, const string &);
        //pf = SumLength;
        */
    }

    /* 重载函数指针 */
    {
        /*
        void ff(int *);
        void ff(unsigned int);

        void (*pf1)(unsigned int) = ff;
//        void (*pf2)(int) = ff;
//        double (*pf3)(unsigned int) = ff;
        */
    }

    /* 函数指针形参 */
    {
        /*
        bool LengthCompare(const string &, const string &);

        void UseBigger(const string &, const string &,
                       bool pf(const string &, const string &));
        void UseBigger(const string &, const string &,
                       bool (*pf)(const string &, const string &));

        string s1("hello"), s2("nihao");
        UseBigger(s1, s2, LengthCompare);

        typedef bool Func(const string &, const string &);
        typedef decltype (LengthCompare) Func;
        typedef bool (*FuncP)(const string &, const string &);
        typedef decltype (LengthCompare) *FuncP;
        using Fp = bool (*)(const string &, const string &);

        void UseBigger(const string &, const string &, Func);
        void UseBigger(const string &, const string &, FuncP);
        void UseBigger(const string &, const string &, Fp);
        */
    }

    /* 返回指向函数的指针 */
    {
        /*
        using F = int (int *, int);
        using PF = int (*)(int *, int);

        PF f1(int);
//        F f2(int);
        F* f3(int);

        int (*pff(int))(int *, int);

//        typedef int (f)(int *, int);
//        int temp(int *, int);
//        typedef decltype(temp) *pt;
//        pt ft(int);
//        typedef decltype(temp) fp;
//        fp* ftt(int);
        */
    }

    ch_6_7_test_1();

    ch_6_7_test_2();

    hw_54_55_56();
}


int MinElement(vector<int>::iterator beg, vector<int>::iterator end)
{
    int min_val = 0;
    while (beg != end)
    {
        if (min_val > *beg)
            min_val = *beg;
        ++beg;
    }
    return min_val;
}

int (*pf)(vector<int>::iterator beg, vector<int>::iterator end) = MinElement;

void ch_6_7_test_1()
{
    vector<int> ivec;
    // give ivec some values
    cout << "Direct call: "   
         << MinElement(ivec.begin(), ivec.end()) << endl;

    cout << "Indirect call: " 
         << pf(ivec.begin(), ivec.end()) << endl;

	cout << "equivalent indirect call: "
	     << (*pf)(ivec.begin(), ivec.end()) << endl;
}

string::size_type SumLength(const string &s1, const string &s2)
{
    return s1.size() + s2.size();
}

string::size_type LargerLength(const string &s1, const string &s2)
{
    return (s1.size() > s2.size()) ? s1.size() : s2.size();
}

/*返回指向函数的指针*/
decltype(SumLength)* GetFun(const string &);
auto GetFun(const string &) -> string::size_type (*)(const string &, const string &);
string::size_type (*GetFun(const string &))(const string &, const string &);

decltype(SumLength)* GetFun(const string &fetch)
{
    if (fetch == "sum")
        return SumLength;
    return LargerLength;
}

void ch_6_7_test_2()
{
    cout <<GetFun("sum")("hello", "world") << endl;
    cout <<GetFun("larger")("hello", "world") << endl;
}

int Func1(int a, int b){return a + b;}
int Func2(int a, int b){return a - b;}
int Func3(int a, int b){return a * b;}
int Func4(int a, int b){return a / b;}
int Func5(int a, int b){return a % b;}

typedef int pF(int a, int b);
typedef int (*pFp)(int a, int b);
//using pF = int (int, int);
//using pFp = int (*)(int a, int b);
//typedef decltype(Func1) pF;
//typedef decltype(Func1) *pFp;

//void Complute(int a, int b, int (*p)(int, int))
void Complute(int a, int b, pFp para)
{
    cout << para(a, b) << endl;
}

//回调
void hw_54_55_56()
{
    int i = 5, j = 10;
    decltype(Func1) *p1 = Func1, *p2 = Func2, *p3 = Func3, *p4 = Func4, *p5 = Func5;
    vector<decltype(Func5) *> vF = {p1, p2, p3, p4, p5};
    for (auto p : vF)
        Complute(i, j, p);

    return ;
}
