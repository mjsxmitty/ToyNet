
#include <string>

#include "chapter_06.h"
#include "binary_tree.h"
#include "fibonacci_ver3.cpp"
#include "num_sequence_ver4.h"

using namespace std;

namespace chapter_06
{

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
    using namespace ver3;

    Fibonacci<8>        fib1;
    Fibonacci<8, 8>     fib2;
    Fibonacci<12, 8>    fib3;

    cout << "fib1: " << fib1 << endl;
    cout << "fib2: " << fib2 << endl;
    cout << "fib3: " << fib3 << endl;

    {
        ver4::NumSequence<ver4::fibonacci> nf1(1);
        ver4::NumSequence<ver4::fibonacci> nf2(12, 1);
    }
}

void ch_6_7()
{
    {
        LessThanPred<int> ltpi(1024);
        LessThanPred<string, StringLess> ltps("1024");

        cout << ltpi(1) << endl;
    }
}

void ch_6_8()
{
    PrintIt<ostream> to_standard_out(cout);
    to_standard_out.Print("Hello");
    to_standard_out.Print(1024);
}

}
