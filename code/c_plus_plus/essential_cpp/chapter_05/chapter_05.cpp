
#include <iostream>
#include "chapter_05.h"
#include "libmat.h"
#include "book.h"

using namespace std;

void Chapter_05()
{
    cout << "Creating a LibMat object to print.\n";
//    LibMat libmat;
//    Print(libmat);

    Book book("aaa", "bb");
    Print(book);
}
