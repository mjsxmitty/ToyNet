
#include <iostream>

#include "chapter_06.h"

using namespace std;
using namespace chapter_06;

int main()
{
    PrintIt<ostream> to_standard_out(cout);
    to_standard_out.Print("Hello");
    to_standard_out.Print(1024);

    return 0;
}
