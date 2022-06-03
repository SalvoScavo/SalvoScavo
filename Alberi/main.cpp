#include <iostream>
#include "BST_H.h"
using namespace std;
int main()
{
    BST<int> tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(10);
    tree.insert(6);

    tree.print();
}
