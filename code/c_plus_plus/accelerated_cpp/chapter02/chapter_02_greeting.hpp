

#ifndef __CHAPTER_02_GREETING_H__
#define __CHAPTER_02_GREETING_H__

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int Chapter02Greeting()
{
    cout <<"Please enter your first name: ";
    string name;
    cin >> name;

    const string greeting = "Hello " + name + " !";

    cout <<"Please enter pad: ";
    int pad;
    cin >> pad;

    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;
    const string spaces = string(greeting.size() + pad * 2, ' ');
    cout << endl;

    for (int r = 0; r != rows; ++r) {
        string::size_type c = 0;
        while (c != cols) {
            if (r == pad + 1 && c == pad + 1) {
                cout << greeting;
                c += greeting.size();
            } else {
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                    cout << "*";
                    ++c;
                } else if (r == pad + 1) {
                    cout << " ";
                    ++c;
                } else {
                    cout << spaces;
                    c += spaces.size();
                }
            }
        }
        cout << endl;
    }
    return 0;
}

#endif //__CHAPTER_02_GREETING_H__