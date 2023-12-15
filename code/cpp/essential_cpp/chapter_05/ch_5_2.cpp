
#include <iostream>

#include "mat.h"
#include "book.h"
#include "audio_book.h"

using namespace std;
using namespace chapter_05;

int main()
{
    {
        LibMat libmat;
        Print(libmat);
    }
    cout << "==================================" << endl;

    {
        Book book("a", "b");
        Print(book);
    }
    cout << "==================================" << endl;

    {
        AudioBook audio("1", "2", "3");
        Print(audio);
    }

    return 0;
}
