#include "bst.h"

#include <iostream>

using namespace std;

int main()
{
	cout << "BST code runs!" << endl;
	
	BST<int> tree;
        cout<<tree.search(5)<<endl;
        tree.remove(5);
        tree.print();
        tree.insert(15);
        tree.insert(20);
        tree.insert(7);
        tree.insert(10);
        tree.insert(22);
        tree.insert(18);
        tree.insert(4);
        tree.insert(30);
        tree.insert(25);
        tree.print();
        cout<<tree.search(15)<<endl<<tree.search(25)<<endl<<tree.search(3)<<endl;
        tree.remove(10);
        tree.print();
        tree.remove(30);
        tree.print();
        tree.remove(22);
        tree.print();
        tree.insert(8);
        tree.print();
	//put some code here to show that your BST works
}
