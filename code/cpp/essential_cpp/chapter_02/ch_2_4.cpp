
#include <iostream>
#include "common.h"

using namespace chapter_02;

int main()
{
    bool more = true;
    while (more)
    {
        int cnt;
        std::cout << "enter a servies size: ";
        std::cin >> cnt;

        std::ofstream out("debug.txt");
        Display(FibonSeq1(cnt), &out);

        std::cout << "would you want to try again?(Y/N): ";
        char ch;
        std::cin >> ch;
        if (ch != 'y' && ch != 'Y')
            more = false;
    }
}
