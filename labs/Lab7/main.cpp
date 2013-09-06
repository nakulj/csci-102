#include <fstream>
#include <iostream>
#include <string>

#include "linkedlist.h"

using namespace std;

int main()
{
	LinkedList<int> intList;
        intList.pop_front();
	intList.push_front(4);
	intList.push_front(2);
	intList.push_front(8);
	intList.push_front(3);
	intList.push_front(5);
        cout<<intList.contains(4)<<endl;
        cout<<intList.contains(9)<<endl;
	intList.print();
        for(int i=0; i<10; i++) {
            intList.pop_front();
            intList.print();
        }
        intList.insert(0, 3);
        intList.print();
        intList.insert(0, 2);
        intList.print();
        intList.insert(99, 99);
        intList.print();
        intList.insert(2, 7);
        intList.print();
        intList.insert(2, 5);
        intList.print();
}
