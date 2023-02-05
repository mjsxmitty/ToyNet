
// C语言不支持结构内定义函数,支持指针

/*

void Hello(int a, int b)
{

}

struct Test
{
    void (*FuncPtr)(int, int);

    int a;
    int b;

} test;

void main()
{
    test.FuncPtr = Hello;
}

*/
