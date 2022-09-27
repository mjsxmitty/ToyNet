
#include <string>

#include "chapter_06.h"
#include "../util/binary_tree.h"
#include "../util/fibonacci_ver4.h"

using namespace std;

void ch_6()
{
    //ch_6_4();
    //ch_6_6();
    ch_6_8();
}

void ch_6_4()
{
    BinaryTree<string> bt;
    bt.Insert("Piglet");
    bt.Insert("Eyeore");
    bt.Insert("Roo");
    bt.Insert("Tigger");
    bt.Insert("Chris");
    bt.Insert("Pooh");
    bt.Insert("Kanga");

    cout << "preorder traversal ..." << endl;
    bt.Preorder();
    cout << endl;

    cout << "inorder traversal ..." << endl;
    bt.Inorder();
    cout << endl;

    cout << "posetorder traversal ..." << endl;
    bt.Postorder();
    cout << endl;
}

void ch_6_6()
{
    FibonacciVer4<8>        fib1;
    FibonacciVer4<8, 8>     fib2;
    FibonacciVer4<12, 8>    fib3;

    //cout << "fib1: " << fib1 << endl;

}

void ch_6_8()
{
    PrintIt<ostream> to_standard_out(cout);
    to_standard_out.Print("Hello");
    to_standard_out.Print(1024);
}
