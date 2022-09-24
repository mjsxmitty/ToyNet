
#include <iostream>
#include "libmat.h"

using namespace std;

void Print(const LibMat &mat)
{
    cout << "in global print(): about to print mat.Print()!\n";
    mat.Print();
}
