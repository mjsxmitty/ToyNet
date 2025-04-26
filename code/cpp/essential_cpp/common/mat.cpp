
#include <iostream>
#include "mat.h"

using namespace std;

namespace common
{

void Print(const LibMat &mat)
{
    cout << "in global print(): about to print mat.Print()!\n";
    mat.Print();
}

}
