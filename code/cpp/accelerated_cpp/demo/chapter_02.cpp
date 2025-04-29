
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout <<"Please enter your first name: ";
    string name;
    cin >> name;

    const string greeting = "Hello " + name + "!";

    cout <<"Please enter pad: ";        //
    size_t pad;
    cin >> pad;

    const size_t rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;
    cout << endl;

    for (size_t r = 0; r != rows; ++r)
    {
        string::size_type c = 0;
        while (c != cols)
        {
            if (r == pad + 1 && c == pad + 1)
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                if (r == 0 || r == rows - 1 ||
                    c == 0 || c == cols - 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
                ++c;
            }
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

