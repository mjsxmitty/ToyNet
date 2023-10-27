
#include <iostream>
#include "libmat.h"

using namespace std;

namespace chapter_05
{

void Print(const LibMat &mat)
{
    cout << "in global print(): about to print mat.Print()!\n";
    mat.Print();
}

}
