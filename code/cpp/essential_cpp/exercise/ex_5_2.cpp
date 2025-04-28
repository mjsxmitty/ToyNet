
#include <iostream>

#include "lifo_stack.h"
#include "stack.h"

using namespace std;
using namespace ver2;

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
