
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

    if((int)seq.size() <= pos)
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
    return 0;
}

int main4()
{
    LessThanPred<int> ltpi(1024);
    LessThanPred<string, StringLess> ltps("1024");

    cout << ltpi(1) << endl;
    cout << ltps("abc") << endl;

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

int main00()
{
    using namespace ver7;
	const int pos = 8;

	NumSequence<Fibonacci> fib;	
	display( cout, fib, pos );

	NumSequence<Pell> pell;
	display( cout, pell, pos );

	NumSequence<Lucas> lucas;
	display( cout, lucas, pos );

	NumSequence<Triangular> trian;
	display( cout, trian, pos );
	
	NumSequence<Square> square;
	display( cout, square, pos );

	NumSequence<Pentagonal> penta;
    display( cout, penta, pos );
    return 0;
}

int main01()
{
    using namespace ver7;
	NumSequence<Fibonacci>  fib( 3, 3 );
	cout << "fib: " << fib.WhatAmI() << endl;
	NumSequence<Pell>       pell( 4, 6 );
	NumSequence<Lucas>      lucas( 7, 10 );
	NumSequence<Triangular> trian( 12, 1 );
	NumSequence<Square>     square( 6, 6 );
	NumSequence<Pentagonal> penta( 8, 1 );
	
	cout << "fib: "    << fib    << '\n'
	     << "pell: "   << pell   << '\n'
		 << "lucas: "  << lucas  << '\n'
		 << "trian: "  << trian  << '\n'
		 << "square: " << square << '\n'
		 << "penta: "  << penta  << endl;

    return 0;
};

using namespace ver7;

template <typename seq_type>
void prog_3( seq_type ns, int elem_values )
{
	int elem_val = 0;
	const int pos = 8;
	const int find_pos = 14;

    elem_val = ns.Elem( pos );
    display( cout, ns, pos, elem_val );
	cout << ns.WhatAmI() << " : ( " 
		 << ns.BegPos()   << ", "
		 << ns.Length()    << " ) : "
		 << ns;
	cout << endl;

	ns.SetLength( 12 );
	cout << ns << endl;

	cout << "NumnSequence::is_elem() ";
	if ( ! ns.IsElem( elem_val ) ||
		   ns.IsElem( 2*elem_val ))
				 cout << "failed\n";
	else cout << "ok!\n";

	cout << "copy constructor and equality ";
	seq_type ns2 = ns;
	if ( ns != ns2 )
		 cout << "failed!\n";
	else cout << "ok!\n";

	ns2.SetPosition( 5 );
 
	int posit = ns.PosElem( elem_val );
	if ( ns.PosElem( elem_val ) != pos )
	     cout << "pos_elem() failed : " << posit << "\n";
	else cout << "pos_elem() -- ok: " << posit << "\n";

	posit = ns.PosElem( elem_values );
    if ( posit != find_pos ) 
		 cout << "pos_elem(): not found but grown: failed: " 
			  << posit << " correct: " << find_pos << "\n";
    else cout << "pos_elem(): not found but grown: ok\n";

	cout << "about to print final ns vector: \n";
	ns.Print();
	cout << endl;
		  
	cout << "ns2: should begin at position 5:\n" 
		 << ns2 << endl;
}

int main()
{
	int elem_values[] = 
		{ 377, 80782, 843, 105, 196, 287 };
	
	for ( int ix = 0; ix < 6; ++ix ) // test all
	// for ( int ix = 0; ix < 1; ++ix )    // test 1 at time
	{
		switch( ix ) {
		case 0: {
			NumSequence<Fibonacci> ns( 1,8 );
			prog_3( ns, elem_values[ix] );
			break;}
		case 1:{
			NumSequence<Pell> ns( 1,8 );
			prog_3( ns, elem_values[ix] );
			break;}
		case 2:{
			NumSequence<Lucas> ns( 1,8 );
			prog_3( ns, elem_values[ix] );
			break;}
		case 3:{
			NumSequence<Triangular> ns( 1,8 );
			prog_3( ns, elem_values[ix] );
			break;}
		case 4:{
			NumSequence<Square> ns( 1,8 );
			prog_3( ns, elem_values[ix] );
			break;}
		case 5:{
			NumSequence<Pentagonal> ns( 1,8 );
			prog_3( ns, elem_values[ix] );
			break;}
		default:
			break;
		}	
	}

    return 0;
}