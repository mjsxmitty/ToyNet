
#include <iostream>

#include "lifo_stack.h"

using namespace std;
using namespace chapter_05;

int main()
{
    LifoStack ls;
    string str;
    while (cin >> str && !ls.full())
    {
        ls.push(str);
    }

    cout << ls << endl;
    cout << ls.top() << endl;

    string s;
    ls.pop(s);
    cout << s << endl;
    ls.peek(ls.top() - 1, s);
    cout << s << endl;

    return 0;
}
