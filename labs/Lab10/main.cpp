#include <iostream>

#include "priority_queue.h"

using namespace std;

int main()
{
	PriorityQueue<int> pq;
        pq.pop();
        cout<<pq.top()<<endl;
        pq.push(4);
        pq.print();
        pq.push(10);
        pq.print();
        pq.push(15);
        pq.print();
        pq.push(7);
        pq.print();
        pq.push(9);
        pq.print();
        pq.push(3);
        pq.print();
        pq.push(2);
        pq.print();
        pq.push(11);
        pq.print();
        pq.pop();
        pq.pop();
        pq.push(50);
	pq.print();
}
