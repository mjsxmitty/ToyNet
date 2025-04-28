
#include <iostream>
#include <algorithm>
#include <common.h>

#include "bt_node.h"
#include "binary_tree.h"

using namespace std;
using namespace common;

int main1()
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
    
	int ia[] = { 24, 18, 36, 12, 14, 8, 24, 1, 42, 24, 8, 8, 16, 55 };
	vector< int > ivec( ia, ia + 14 );
	BinaryTree<int> bti( ivec );
    bti.Inorder();
    cout << endl;

    bti.Clear();
	sort( ivec.begin(), ivec.end() );
	bti.Insert( ivec );
    bti.Postorder();
    cout << endl;

    bt.Remove( "Piglet" );
    bt.Postorder();
    cout << endl;

    BinaryTree<string> bt2(bt);
    bt2.Preorder();
    cout << endl;

    return 0;
}

int main2()
{
    using namespace ver5;
    Fibonacci<8>        fib1;
    Fibonacci<8, 8>     fib2;
    Fibonacci<12, 8>    fib3;

    cout << "fib1: " << fib1 << endl;
    cout << "fib2: " << fib2 << endl;
    cout << "fib3: " << fib3 << endl;

    return 0;
}

void fibonacci(int pos, std::vector<int> &seq)
{
    if (seq.empty())
    {
        seq.push_back(1);
        seq.push_back(1);
    }

    if(seq.size() <= pos)
    {
        int ix = seq.size();
        int n2 = seq[ix - 2];
        int n1 = seq[ix - 1];

        for ( ; ix < pos; ++ix)
        {
            int elem = n1 + n2;
            seq.push_back(elem);
            n2 = n1;
            n1 = elem;
        }
    }
}

int main3()
{
    using namespace ver6;
    NumSequence<fibonacci> nf1(1);
    NumSequence<fibonacci> nf2(12, 1);
    cout << "nf1: " << nf1 << endl;
    cout << "nf2: " << nf2 << endl;
}

int main4()
{
    LessThanPred<int> ltpi(1024);
    LessThanPred<string, StringLess> ltps("1024");

    cout << ltpi(1) << endl;
    cout << ltps("abc") << endl;

    return 0;
}

int main()
{

    return 0;
}

int main6()
{
    PrintIt1 to_standard_out(cout);
    to_standard_out.Print("Hello");
    to_standard_out.Print(1023);

    return 0;
}

int main7()
{
    PrintIt<ostream> to_standard_out(cout);
    to_standard_out.Print("Hello");
    to_standard_out.Print(1024);

    return 0;
}
