
#include <iostream>
#include <algorithm>

#include "bt_node.h"
#include "binary_tree.h"

using namespace std;
using namespace common;

int main()
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
