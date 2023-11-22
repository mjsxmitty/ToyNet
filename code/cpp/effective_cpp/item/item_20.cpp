
#include "item_20.h"
#include <iostream>

using namespace effective_item_20;

void Item20()
{
    std::cout << "**********item 20**********" << std::endl;
#if 1
    WindowWithScrollBars wwsb;
    PrintNameAndDisplay(wwsb);      // 对象切割
    std::cout << std::endl;
    PrintNameAndDisplay2(wwsb);
#endif
    std::cout << "***************************" << std::endl;
}

namespace effective_item_20 {

std::string Window::Name() const
{
    //std::cout << "Window::Name()" << std::endl;
    return "Window::Name()";
}

void Window::Display() const
{
    std::cout << "Window::Display()" << std::endl;
}

void WindowWithScrollBars::Display() const
{
    std::cout << "WindowWithScrollBars::Display()" << std::endl;
}

void PrintNameAndDisplay(Window w)
{
    std::cout << w.Name() << std::endl;
    w.Display();
}

void PrintNameAndDisplay2(const Window &w)
{
    std::cout << w.Name() << std::endl;
    w.Display();
}

}
