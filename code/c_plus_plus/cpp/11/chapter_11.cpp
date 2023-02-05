

#include "chapter_11.h"

namespace chapter_11
{

int FuncHello(int a, int b)
{
    printf("FuncHello(int, int) -> param: %d, %d\n", a, b);
    return a + b;
}

int FuncHello1(int a, int b, int c)
{
    printf("FuncHello(int, int, int) -> param: %d, %d, %d\n", a, b, c);
    return a + b;
}

void Call(function<int(int, int)> func)
{
    func(1, 2);
}


void Test1()
{
    function<int(int, int)> func = FuncHello;
    func(1, 2);
    Call(FuncHello);

    function<int(int, int)> func1 = Lambda;
    func1(1, 2);
    Call(Lambda);

//        FunctionPtr = FuncHello;
//        function<int(int, int)> func2 = FunctionPtr;
//        func2(1, 2);

    Hello hello;
    function<int(int, int)> func3 = bind(&Hello::hello, &hello, placeholders::_1, placeholders::_2);
    func3(1, 2);

    function<int(int, int)> func4 = Hello::StaticHello;
    func4(1, 2);
    Call(Hello::StaticHello);

    function<int(int, int)> func5 = OperatorHello();
    func5(1, 2);
    Call(OperatorHello());

    function<int(int, int)> func6 = FuncTemplate<int>;
    func6(1, 2);
    Call(FuncTemplate<int>);
}

void Test2()
{
    // 延迟
    auto func = std::bind(FuncHello, 1, 2);
    cout << func(20, 10) << endl;

    // 占位
    auto func1 = std::bind(OperatorHello(), std::placeholders::_1, std::placeholders::_2);
    cout << func1(20, 10) << endl;
    // ……
}
}
