
#ifndef __EFFECTIVE_CPP_ITEM_20_H__
#define __EFFECTIVE_CPP_ITEM_20_H__

#include <string>

void Item20();

namespace effective_item_20 {

class Window
{
public:
    std::string     Name()const;
    virtual void    Display() const;
};

class WindowWithScrollBars : public Window
{
public:
    virtual void    Display() const;
};

void PrintNameAndDisplay(Window w);
void PrintNameAndDisplay2(const Window &w);

}

#endif // __EFFECTIVE_CPP_ITEM_20_H__
