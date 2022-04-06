
#include <iostream>
#include "shape.h"

using namespace std;

//void Shape::Draw()
//{
//    cout << "draw shape ..." << endl;
//    cout << "( " << x_ << ", " << y_ << " )" << endl;
//}

void Circle::Draw()
{
    cout << "draw circle ..." << endl;
    cout << "( " << x_ << ", " << y_ << " )" << endl;
    cout << "radio r = " << r_ << endl;
}

void Rect::Draw()
{
    cout << "draw rect ..." << endl;
    cout << "( " << x_ << ", " << y_ << " )" << endl;
    cout << "len = " << len_  << ", wid = " << wid_ << endl;
}
