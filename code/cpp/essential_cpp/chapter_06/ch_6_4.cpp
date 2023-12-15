
#include <iostream>

#include "bt_node.h"
#include "binary_tree.h"

using namespace std;
using namespace chapter_06;

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

    return 0;
}
