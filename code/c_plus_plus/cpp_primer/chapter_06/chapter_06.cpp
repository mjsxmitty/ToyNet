

#include "chapter_06.h"
#include "local_math.h"

#include <iostream>
#include <vector>
#include <initializer_list>

using std::initializer_list;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::cin;

void Chapter_06()
{
    //Practice_6_1_1();
    //Practice_6_1_3();
    Practice_6_2_6();
    //Practice_6_2_2();
    //Practice_6_3_2();
    //Practice_6_3_3();
    //Homework_6_33();
    //Practice_6_7();

    //Practice();
}

size_t FuncCalls()
{
    static size_t cnt = 0;
    return ++cnt;
}

/* 函数最外层作用域中局部变量不能与函数形参命名一样 */
int Practice_6_1(int i)
{
    //同一作用域
    //int i = 1;
    {
        int i = 1;
    }
    return i;
}

/*局部静态函数*/
void Practice_6_1_1()
{
    for (size_t i = 0; i != 10; ++i)
        cout << FuncCalls() << endl;
}

/*分离式编译,函数调用，递归(6-1-1)*/
void Practice_6_1_3()
{
	cout << Factorial(5) << endl;
	cout << Fact(5) << endl;
	cout << Factorial(0) << endl;
	cout << Fact(0) << endl;
}

/*可变参数也可以有其他的参数*/
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

/*使用引用传递额外参数*/
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

void Practice_6_2_2()
{
    // string s;
	// getline(cin, s); 
	size_t ctr = 0;
	// auto index = FindChar(s, 'o', ctr);
	// cout << index << " " << ctr << endl;

	vector<int> ivec;
	int i;
	while (cin >> i)
		ivec.push_back(i);

    for (auto i : {43, 33, 92})
    {
        auto it = FindChar(ivec.begin(), ivec.end(), i, ctr);
		if (it == ivec.end())
			cout << i << " is not in the input data" << endl;
		else
			cout << i << " was at position " << it - ivec.begin() << endl;
    }
}

/*含有可变参数列表*/
void Practice_6_2_6()
{
    string expected = "description", actual = "some other case";
    ErrorMsg({"functionX", expected, actual});
    cout << endl;
    ErrorMsg({"functionX", "okay"});
    cout << endl;
    ErrorMsg(ErrCode(1), {"functionX", expected, actual});
    cout << endl;
    ErrorMsg(ErrCode(0), {"functionX", "okay"});
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

void Practice_6_3_2()
{
    auto ret = FunctionX();
    for (auto i : ret)
        cout << i << " ";
    cout << endl;
}

/*数组类型相关*/
int Arr[10];
int *pArr[10];
int (*p)[10] = &Arr;

/*数组类型别名*/
//using arrT = int [5];
typedef int arrT[5];

/*返回指向数组相关类型的函数*/
arrT* Func(int i);
auto Func(int i) -> int (*)[5];
int (*Func(int i))[5];

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

int* ElemPtr(int i)
{
    return (i % 2) ? odd : even;
}

//arrT* Func(int i)
//auto Func(int i) -> int (*)[5]
//int (*Func(int i))[5]
decltype(odd)* ArrPtr(int i)
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

/*返回数组指针/引用*/
void Practice_6_3_3()
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
    //arrT& pppp = ArrRef(6);
    for (size_t i = 0; i < 5; ++i)
        cout << arrR[i] << ' ';
    cout << endl;
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

void Homework_6_33()
{
    int a[] = {1,3,5,7,9};
    vector<int> local_vec(std::begin(a), std::end(a));
    PrintVec(local_vec, 0);
}

string::size_type SumLength(const string &s1, const string &s2)
{
    return s1.size() + s2.size();
}

string::size_type LargerLength(const string &s1, const string &s2)
{
    return (s1.size() > s2.size()) ? s1.size() : s2.size();
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

void Practice_6_7_1()
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

/*返回指向函数的指针*/
decltype(SumLength)* GetFun(const string &);
auto GetFun(const string &) -> string::size_type (*)(const string &, const string &);
string::size_type (*GetFun(const string &))(const string &, const string &);
// using GetFun = string::size_type (*)(const string &, const string &);
// typedef string::size_type (*GetFun)(const string&, const string &);
decltype(SumLength)* GetFun(const string &fetch)
{
    if (fetch == "sum")
        return SumLength;
    return LargerLength;
}

void Practice_6_7_2()
{
    cout <<GetFun("sum")("hello", "world") << endl;
    cout <<GetFun("larger")("hello", "world") << endl;
}

int Func1(int a, int b)
{
    return a + b;
}

int Func2(int a, int b)
{
    return a - b;
}

int Func3(int a, int b)
{
    return a * b;
}

int Func4(int a, int b)
{
    return a / b;
}

int Func5(int a, int b)
{
    return a % b;
}

void Complute(int a, int b, int (*p)(int, int))
{
    std::cout << p(a, b) << std::endl;
}

//回调
void Practice()
{
    int i = 5, j = 10;
    decltype(Func1) *p1 = Func1, *p2 = Func2, *p3 = Func3, *p4 = Func4, *p5 = Func5;
    vector<decltype(Func5) *> vF = {p1, p2, p3, p4, p5};
    for (auto p : vF)
        Complute(i, j, p);

    return ;
}
