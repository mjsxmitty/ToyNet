
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
        std::cout << "sorry! cannot calculate position: "
                    << pos << " elem."<< std::endl;
        return -1;
    }

    common::PrintFibon(pos);
    return 0;
}

int main()
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
            std::cout << "sorry! cannot calculate position: "
                        << pos << " elem "<< std::endl;

        std::cout << "would you want to try again?(Y/N): ";
        char ch;
        std::cin >> ch;
        if (ch != 'y' && ch != 'Y')
            more = false;
    }

    return 0;
}
