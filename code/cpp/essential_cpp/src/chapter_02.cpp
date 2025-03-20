
#include <iostream>
#include "common.h"

int main1()
{
    std::cout << "please enter a position: ";
    int pos;
    std::cin >> pos;

    int elem;
    if (common::FibonElem(pos, elem))
    {
        std::cout << "element at position: "
                    << pos << " is: " << elem
                    << std::endl;
    }
    else
    {
        std::cout << "sorry! cannot calculate position "
                    << pos << " elem."<< std::endl;
        return -1;
    }

    common::PrintFibon(pos);
    return 0;
}

int main2()
{
    bool more = true;
    while (more)
    {
        int pos;
        std::cout << "please enter a position: ";
        std::cin >> pos;

        int elem;
        if (common::FibonElem(pos, elem))
        {
            std::cout << "element at position: " << pos
                << " value is: " << elem << std::endl;
        }
        else
            std::cout << "sorry! cannot calculate position "
                        << pos << " elem "<< std::endl;

        std::cout << "would you want to try again?(Y/N): ";
        char ch;
        std::cin >> ch;
        if (ch != 'y' && ch != 'Y')
            more = false;
    }

    return 0;
}

int main3()
{
    int ia[8] = { 8, 34, 3, 13, 1, 21, 5, 2 };
    std::vector<int> vec(ia, ia + 8);
#if 0
    common::Display(vec);
    common::BubbleSort(vec, NULL);     // 0->避免二义性
    common::Display(vec);
#endif
#if 1
    std::ofstream out("out.txt");
    common::Display(vec, out);
    common::BubbleSort(vec, out);
    common::Display(vec, out);
#endif
    return 0;
}

int main()
{
    bool more = true;
    while (more)
    {
        int cnt;
        std::cout << "enter a servies size: ";
        std::cin >> cnt;

        std::ofstream out("debug.txt");
        common::Display(common::FibonSeq(cnt), &out);

        std::cout << "would you want to try again?(Y/N): ";
        char ch;
        std::cin >> ch;
        if (ch != 'y' && ch != 'Y')
            more = false;
    }
}