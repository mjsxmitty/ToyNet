
#include <iostream>

#include "mat.h"
#include "book.h"
#include "audio_book.h"

using namespace std;

int main()
{
    {
        common::LibMat libmat;
        Print(libmat);
    }
    cout << "==================================" << endl;

    {
        common::Book book("a", "b");
        Print(book);
    }
    cout << "==================================" << endl;

    {
        common::AudioBook audio("1", "2", "3");
        Print(audio);
    }

    return 0;
}
